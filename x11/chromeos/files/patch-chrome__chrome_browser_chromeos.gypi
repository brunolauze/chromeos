--- chrome/chrome_browser_chromeos.gypi.orig	2014-06-02 21:54:29.855126392 -0500
+++ chrome/chrome_browser_chromeos.gypi	2014-06-03 08:26:35.602292923 -0500
@@ -40,7 +40,7 @@
         'installer_util',
         'safe_browsing_proto',
         'safe_browsing_report_proto',
-        '../breakpad/breakpad.gyp:breakpad_client',
+        #'../breakpad/breakpad.gyp:breakpad_client',
         '../build/linux/system.gyp:dbus',
         '../chromeos/chromeos.gyp:chromeos',
         # browser_chromeos #includes signed_secret.pb.h directly.
@@ -61,7 +61,7 @@
         '../crypto/crypto.gyp:crypto',
         '../dbus/dbus.gyp:dbus',
         '../device/bluetooth/bluetooth.gyp:device_bluetooth',
-        '../device/hid/hid.gyp:device_hid',
+        #'../device/hid/hid.gyp:device_hid',
         '../media/media.gyp:media',
         '../net/net.gyp:net',
         '../ppapi/ppapi_internal.gyp:ppapi_ipc',  # For PpapiMsg_LoadPlugin
@@ -116,7 +116,7 @@
       'include_dirs': [
         # breakpad_linux.cc uses generated file_version_info_linux.h.
         '<(SHARED_INTERMEDIATE_DIR)',
-        '../breakpad/src',
+        #'../breakpad/src',
       ],
       'sources': [
         # All .cc, .h, .m, and .mm files under browser/chromeos, except for tests
@@ -201,8 +201,8 @@
         'browser/chromeos/dbus/proxy_resolution_service_provider.h',
         'browser/chromeos/dbus/screen_lock_service_provider.cc',
         'browser/chromeos/dbus/screen_lock_service_provider.h',
-        'browser/chromeos/device/input_service_proxy.cc',
-        'browser/chromeos/device/input_service_proxy.h',
+        #'browser/chromeos/device/input_service_proxy.cc',
+        #'browser/chromeos/device/input_service_proxy.h',
         'browser/chromeos/device_hierarchy_observer.h',
         'browser/chromeos/device_uma.cc',
         'browser/chromeos/device_uma.h',
