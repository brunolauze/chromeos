#!/bin/sh


BUILD_TYPE=Release

LD_LIBRARY_PATH=/home/workspace/chromeos/src/out/$BUILD_TYPE:/home/workspace/chromeos/src/out/$BUILD_TYPE/lib:/usr/local/lib:/usr/lib:/lib /home/workspace/chromeos/src/out/$BUILD_TYPE/chrome --user-data-dir=/tmp/chrome --ash-host-window-bounds=1+1-1366x768 \
	--allow-file-access \
	--always-authorize-plugin \
	--enable-app-window-controls \
	--enable-apps-file-association \
	--enable-app-list \
        --enable-threaded-compositing \
        --file-manager-enable-new-audio-player \
        --enable-experimental-app-list \
        --enable-experimental-web-platform-features \
        --enable-experimental-extension-apis \
        --dbus-stub \
	--login-manager \
	--enable-logging=stderr \
	--v=1


#	--enable-threaded-compositing \
#	--file-manager-enable-new-audio-player \
#	--enable-experimental-app-list \
#	--enable-experimental-web-platform-features \
#	--enable-experimental-extension-apis \
#	--dbus-stub \


#        --disable-gpu \
#        --disable-threaded-compositing \
#        --ui-disable-threaded-compositing \

#--login-profile=user 
#--login-manager
