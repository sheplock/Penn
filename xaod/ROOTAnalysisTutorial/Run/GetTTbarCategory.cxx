#include <xAODTruth/TruthEventContainer.h>

#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <SWup/GetTTbarCategory.h>
#include <SWup/EventInit.h>
#include <SWup/CommonData.h>
#include <SWup/Util.h>

using namespace SWup;

const std::vector<int> ENABLED_CHANNEL_NUMBERS = {
	410000, // ttbar 13TeV
	407012, //MET filtered ttbar
	
	204422, // stop_800_1
};

static const std::vector<std::string> BIN_LABELS = {
	"#font[12]{l}#font[12]{l}",
	"#font[12]{l}h",
	"#font[12]{l}#tau_{h}",
	"#font[12]{l}#tau_{#font[12]{l}}",
	"#tau_{#font[12]{l}}h",
	"#tau_{#font[12]{l}}#tau_{h}",
	"#tau_{#font[12]{l}}#tau_{#font[12]{l}}",
	"hh",
	"h#tau_{h}",
	"#tau_{h}#tau_{h}",
	"other",
};

// this is needed to distribute the algorithm to the workers
ClassImp(GetTTbarCategory)

GetTTbarCategory::GetTTbarCategory()
{
	// Here you put any code for the base initialization of variables,
	// e.g. initialize all pointers to 0.  Note that you should only put
	// the most basic initialization here, since this method will be
	// called on both the submission and the worker node.  Most of your
	// initialization code will go into histInitialize() and
	// initialize().
}

EL::StatusCode GetTTbarCategory::setupJob(EL::Job& /*job*/)
{
	// Here you put code that sets up the job on the submission object
	// so that it is ready to work with your algorithm, e.g. you can
	// request the D3PDReader service or add output files.  Any code you
	// put here could instead also go into the submission script.  The
	// sole advantage of putting it here is that it gets automatically
	// activated/deactivated when you add/remove the algorithm from your
	// job, which may or may not be of value to you.
	return EL::StatusCode::SUCCESS;
}

EL::StatusCode GetTTbarCategory::histInitialize()
{
	// Here you do everything that needs to be done at the very
	// beginning on each worker node, e.g. create histograms and output
	// trees.  This method gets called before any input files are
	// connected.
	return EL::StatusCode::SUCCESS;
}

EL::StatusCode GetTTbarCategory::fileExecute()
{
	// Here you do everything that needs to be done exactly once for every
	// single file, e.g. collect a list of all lumi-blocks processed
	return EL::StatusCode::SUCCESS;
}

EL::StatusCode GetTTbarCategory::changeInput(bool /*firstFile*/)
{
	// Here you do everything you need to do when we change input files,
	// e.g. resetting branch addresses on trees.  If you are using
	// D3PDReader or a similar service this method is not needed.

	// for the very unlikely case, that someone mixes e.g. ttbar and w+jets,
	// recheck the sample number
	sampleNumberChecked = false; 

	return EL::StatusCode::SUCCESS;
}

EL::StatusCode GetTTbarCategory::initialize()
{
	// Here you do everything that you need to do after the first input
	// file has been connected and before the first event is processed,
	// e.g. create additional histograms based on which variables are
	// available in the input files.  You can also create all of your
	// histograms and trees in here, but be aware that this method
	// doesn't get called if no events are processed.  So any objects
	// you create here won't be available in the output if you have no
	// input events.
	EventInit *eventInit = dynamic_cast<EventInit*>(wk()->getAlg("EventInit"));
	if (!eventInit) {
		Error("initialize()", "Failed to find EventInit algorithm");
		return EL::StatusCode::FAILURE;
	}
	commonData = eventInit->getCommonData();
	commonData->outputInts.push_back({"TTbarCategory", "tt_cat"});

	const size_t nCategories = static_cast<size_t>(UNKNOWN) + 1;
	breakdownHist = new TH1F("tt_cat_breakdown", ";t#bar{t} decay category;weighted mc events", nCategories, 0, nCategories);
	breakdownHist->Sumw2();
	for (size_t i=0; i < BIN_LABELS.size(); ++i) {
		breakdownHist->GetXaxis()->SetBinLabel(i+1, BIN_LABELS[i].c_str());
	}
	wk()->addOutput(breakdownHist);

	return EL::StatusCode::SUCCESS;
}

enum DecayMode {HAD, LEPel, LEPmu, TAU, TAUHAD, TAULEPel, TAULEPmu, ERROR};
enum reducedDecayMode {rHAD, rLEP, rTAU, rTAUHAD, rTAULEP, rERROR};

std::pair<DecayMode, const xAOD::TruthParticle*> getTopDecayMode(const xAOD::TruthParticle *top)
{
	for (size_t i = 0; i < top->nChildren(); i++) {
		auto particle = top->child(i);

		if (particle->isTop()) {
			return getTopDecayMode(particle);
		}

		if (particle->isW()) {
			if (particle->nChildren()==0)
				return std::make_pair(ERROR, nullptr);

			while (particle->child(0)->isW()){
				particle = particle->child(0);
				if (particle->nChildren()==0)
					return std::make_pair(ERROR, nullptr);
			}

			for (size_t j = 0; j < particle->nChildren(); j++) {
				auto wBosonChild = particle->child(j);
				if (wBosonChild->isMuon()) {
					return std::make_pair(LEPmu, wBosonChild);
				}
				if (wBosonChild->isElectron()) {
					return std::make_pair(LEPel, wBosonChild);
				}
				else if (wBosonChild->isTau()) {
					return std::make_pair(TAU, wBosonChild);
				}
			}
			return std::make_pair(HAD, nullptr);
		}
	}
	return std::make_pair(ERROR, nullptr);
}

bool isCombinedDecay(const reducedDecayMode topDecay,const reducedDecayMode antitopDecay, const reducedDecayMode d1, const reducedDecayMode d2) {
	return ((topDecay == d1 && antitopDecay == d2) || (topDecay == d2 && antitopDecay == d1));
}

EL::StatusCode GetTTbarCategory::execute()
{
	// Here you do everything that needs to be done on every single
	// events, e.g. read input variables, apply cuts, and fill
	// histograms and trees.  This is where most of your actual analysis
	// code will go.

	// don't do anything when running on data.
	xAOD::TEvent *event = wk()->xaodEvent();
	xAOD::TStore *store = wk()->xaodStore();

	auto truthTopLeptonContainer = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
	CHECK_THROW(store->record(truthTopLeptonContainer, "TruthTopLeptons"));

	if (!IsMC(event)) {
		return EL::StatusCode::SUCCESS;
	}

	if (!sampleNumberChecked) {
		int mcChannelNumber = commonData->eventInfo->mcChannelNumber();
		enableSample = std::find(ENABLED_CHANNEL_NUMBERS.begin(), ENABLED_CHANNEL_NUMBERS.end(), mcChannelNumber) != ENABLED_CHANNEL_NUMBERS.end();
		sampleNumberChecked = true;
	}

	if (!enableSample) {
		return EL::StatusCode::SUCCESS;
	}

	auto truthParticles = Retrieve<xAOD::TruthParticleContainer>(event, "TruthParticles");

	DecayMode topDecay = ERROR;
	DecayMode antitopDecay = ERROR;
	const xAOD::TruthParticle* topLepton = nullptr;
	const xAOD::TruthParticle* antitopLepton = nullptr;
	bool topfound = false;
	bool antitopfound = false;

	for (const auto& particle: *truthParticles) {
		if (particle->pdgId() == 6) {
			std::tie(topDecay, topLepton) = getTopDecayMode(particle);
			topfound = true;
			commonData->eventInfo->auxdata<size_t>("TruthTopIndex") = particle->index();
		}
		if (particle->pdgId() == -6) {
			std::tie(antitopDecay, antitopLepton) = getTopDecayMode(particle);
			antitopfound = true;
			commonData->eventInfo->auxdata<size_t>("TruthAntiTopIndex") = particle->index();
		}
		if (topfound && antitopfound) {
			if (topDecay==TAU){
				for (const auto& particle2: *truthParticles) {
					//suppress semi-leptonic b-decays with the PDGid and the mass cut.
					if (particle2->pdgId() == -15 && particle2->nParents() > 0 && particle2->parent(0)->p4().M()/1000. > 20) {
						if (particle2->nChildren() > 1){
							if (particle2->child(1)->isElectron()) topDecay = TAULEPel;
							else if (particle2->child(1)->isMuon()) topDecay = TAULEPmu;
							else {
								if (particle2->child(0)->nChildren()>1){ //tau-> tau+photon
									if (particle2->child(0)->child(1)->isElectron()) topDecay = TAULEPel; 
									if (particle2->child(0)->child(1)->isMuon()) topDecay = TAULEPmu;
									break;
								}
								else{
									topDecay = TAUHAD;
									break;
								}
							}
						}
					}
				}
			}
			if (antitopDecay==TAU){
				for (const auto& particle2: *truthParticles) {
					//suppress semi-leptonic b-decays with the PDGid and the mass cut.
					if (particle2->pdgId() == 15 && particle2->nParents() > 0 && particle2->parent(0)->p4().M()/1000. > 20) { 
						if (particle2->nChildren() > 1){
							if (particle2->child(1)->isElectron()) antitopDecay = TAULEPel;
							else if (particle2->child(1)->isMuon()) antitopDecay = TAULEPmu;
							else{
								if (particle2->child(0)->nChildren()>1){
									if (particle2->child(0)->child(1)->isElectron()) antitopDecay = TAULEPel; 
									if (particle2->child(0)->child(1)->isMuon()) antitopDecay = TAULEPmu; 
									break;
								}
								else{
									antitopDecay = TAUHAD;
									break;
								}
							}
						}
					}
				}
			}
			break;
		}
	}
	if (topDecay==TAU) topDecay = TAUHAD;
	if (antitopDecay==TAU) antitopDecay = TAUHAD;

	reducedDecayMode reducedtopDecay = rERROR;
	reducedDecayMode reducedantitopDecay = rERROR;
	if (topDecay==HAD) reducedtopDecay = rHAD;
	if (topDecay==LEPel || topDecay==LEPmu) reducedtopDecay = rLEP;
	if (topDecay==TAULEPel || topDecay==TAULEPmu) reducedtopDecay = rTAULEP;
	if (topDecay==TAUHAD) reducedtopDecay = rTAUHAD;
	
	if (antitopDecay==HAD) reducedantitopDecay = rHAD;
	if (antitopDecay==LEPel || antitopDecay==LEPmu) reducedantitopDecay = rLEP;
	if (antitopDecay==TAULEPel || antitopDecay==TAULEPmu) reducedantitopDecay= rTAULEP;
	if (antitopDecay==TAUHAD) reducedantitopDecay= rTAUHAD;

	Category ttbarCat = UNKNOWN;
	if (!topfound || !antitopfound) {
		Error("execute()", "failed to find two top quarks");
		return EL::StatusCode::FAILURE;
	}
	else if (isCombinedDecay(reducedtopDecay, reducedantitopDecay, rLEP, rLEP))
		ttbarCat = LEP_LEP;
	else if (isCombinedDecay(reducedtopDecay, reducedantitopDecay, rLEP, rHAD))
		ttbarCat = LEP_HAD;
	else if (isCombinedDecay(reducedtopDecay, reducedantitopDecay, rLEP, rTAUHAD))
		ttbarCat = LEP_TAUHAD;
	else if (isCombinedDecay(reducedtopDecay, reducedantitopDecay, rLEP, rTAULEP))
		ttbarCat = LEP_TAULEP;
	else if (isCombinedDecay(reducedtopDecay, reducedantitopDecay, rTAULEP, rHAD))
		ttbarCat = TAULEP_HAD;
	else if (isCombinedDecay(reducedtopDecay, reducedantitopDecay, rTAULEP, rTAUHAD))
		ttbarCat = TAULEP_TAUHAD;
	else if (isCombinedDecay(reducedtopDecay, reducedantitopDecay, rTAULEP, rTAULEP))
		ttbarCat = TAULEP_TAULEP;
	else if (isCombinedDecay(reducedtopDecay, reducedantitopDecay, rHAD, rHAD))
		ttbarCat = HAD_HAD;
	else if (isCombinedDecay(reducedtopDecay, reducedantitopDecay, rHAD, rTAUHAD))
		ttbarCat = HAD_TAUHAD;
	else if (isCombinedDecay(reducedtopDecay, reducedantitopDecay, rTAUHAD, rTAUHAD))
		ttbarCat = TAUHAD_TAUHAD;
	else {
		Warning("execute()", "failed to find combined decay %d %d", topDecay, antitopDecay);
	}

	// store the leptonic decay products of the top
	if (topLepton)
		truthTopLeptonContainer->push_back(const_cast<xAOD::TruthParticle*>(topLepton));
	if (antitopLepton)
		truthTopLeptonContainer->push_back(const_cast<xAOD::TruthParticle*>(antitopLepton));

	breakdownHist->Fill(static_cast<int>(ttbarCat), commonData->weight);
	commonData->eventInfo->auxdata<int>("TTbarCategory") = static_cast<int>(ttbarCat);

	if (filterCat && ttbarCat != filterCatToKeep) {
		wk()->skipEvent();
	}

	return EL::StatusCode::SUCCESS;
}

EL::StatusCode GetTTbarCategory::postExecute()
{
	// Here you do everything that needs to be done after the main event
	// processing.  This is typically very rare, particularly in user
	// code.  It is mainly used in implementing the NTupleSvc.
	return EL::StatusCode::SUCCESS;
}

EL::StatusCode GetTTbarCategory::finalize()
{
	// This method is the mirror image of initialize(), meaning it gets
	// called after the last event has been processed on the worker node
	// and allows you to finish up any objects you created in
	// initialize() before they are written to disk.  This is actually
	// fairly rare, since this happens separately for each worker node.
	// Most of the time you want to do your post-processing on the
	// submission node after all your histogram outputs have been
	// merged.  This is different from histFinalize() in that it only
	// gets called on worker nodes that processed input events.
	return EL::StatusCode::SUCCESS;
}

EL::StatusCode GetTTbarCategory::histFinalize()
{
	// This method is the mirror image of histInitialize(), meaning it
	// gets called after the last event has been processed on the worker
	// node and allows you to finish up any objects you created in
	// histInitialize() before they are written to disk.  This is
	// actually fairly rare, since this happens separately for each
	// worker node.  Most of the time you want to do your
	// post-processing on the submission node after all your histogram
	// outputs have been merged.  This is different from finalize() in
	// that it gets called on all worker nodes regardless of whether
	// they processed input events.
	return EL::StatusCode::SUCCESS;
}
