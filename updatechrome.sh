#!/bin/sh

rm -rf out
git clean -f
git reset --hard
patch < /home/workspace/chromeos/dot.DEPS.git
python tools/deps2git/deps2submodules.py .DEPS.git
git submodule foreach git reset --hard
git submodule foreach git pull origin master
git clean -f 
git reset --hard
git pull
