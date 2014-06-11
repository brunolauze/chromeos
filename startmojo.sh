#!/bin/sh

LD_LIBRARY_PATH=/home/workspace/chromeos/src/out/Release/lib:/home/workspace/chromeos/src/out/Release:/usr/local/lib:/usr/lib:/lib ./mojo_shell --origin=http://127.0.0.1:4444 --disable-cache mojo:mojo_sample_app
