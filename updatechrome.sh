#!/bin/sh

ROOT_CHR=`pwd`

rm -rf out
git clean -f
git reset --hard
patch < /home/workspace/chromeos/patch-dot_DEPS.git
python tools/deps2git/deps2submodules.py .DEPS.git
cd native_client
python ../tools/deps2git/deps2submodules.py .DEPS.git
cd $ROOT_CHR
git submodule foreach git reset --hard
git submodule foreach git pull origin master
cd native_client
git submodule foreach git reset --hard
git submodule foreach git pull origin master
cd $ROOT_CHR
git clean -f 
git reset --hard
git pull

mkdir -p $ROOT_CHR/third_party/cloog
cd $ROOT_CHR/third_party/cloog
fetch http://gd.tuwien.ac.at/gnu/gcc/infrastructure/cloog-0.18.1.tar.gz
fetch http://isl.gforge.inria.fr/isl-0.12.2.tar.bz2
cd $ROOT_CHR

mkdir -p $ROOT_CHR/third_party/gmp
cd $ROOT_CHR/third_party/gmp
fetch https://gmplib.org/download/gmp/gmp-6.0.0a.tar.bz2
cd $ROOT_CHR

cd $ROOT_CHR/third_party/expat
fetch http://fossies.org/linux/www/expat-2.1.0.tar.gz
cd $ROOT_CHR
