#!/bin/sh

git clone https://chromium.googlesource.com/chromium/src
cd src
cd tools
git clone https://chromium.googlesource.com/chromium/tools/deps2git
cd ..
python tools/deps2git/deps2submodules.py .DEPS.git
git submodule update --init --recursive
git pull
