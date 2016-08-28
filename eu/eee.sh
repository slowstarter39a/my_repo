
export LD_LIBRARY_PATH="./lib"
#LD_LIBRARY_PATH="."
make TARGET=$1
echo =================================================
echo
echo =================================================
./out/$1
