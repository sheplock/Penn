export PYTHONPATH=./MC14JobOptions:$PYTHONPATH
export JOBOPTSEARCHPATH=./MC14JobOptions:$JOBOPTSEARCHPATH
mv ./share ./MC14JobOptions
mv ./gencontrol/* ./MC14JobOptions
mv ./susycontrol/* ./MC14JobOptions
mv ./common/*.py ./MC14JobOptions
rm ./common/README
rmdir ./common
rmdir ./gencontrol
rmdir ./susycontrol
mkdir ./share
mv ./MC14JobOptions/*DEC ./share
mv ./MC14JobOptions/*model ./share
mv ./MC14JobOptions/*txt ./share
mv ./MC14JobOptions/*slha ./share
mv ./MC14JobOptions/*dat ./share
export DATAPATH=./share:$DATAPATH
