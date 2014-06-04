--- chrome/chrome_browser_extensions.gypi.orig	2014-05-30 09:41:17.409878899 -0500
+++ chrome/chrome_browser_extensions.gypi	2014-05-30 09:51:48.038835613 -0500
@@ -37,7 +37,6 @@
         '../content/content.gyp:content_common',
         '../crypto/crypto.gyp:crypto',
         '../device/bluetooth/bluetooth.gyp:device_bluetooth',
-        '../device/hid/hid.gyp:device_hid',
         '../device/serial/serial.gyp:device_serial',
         '../extensions/common/api/api.gyp:extensions_api',
         '../extensions/extensions.gyp:extensions_browser',
@@ -940,6 +939,11 @@
         'browser/extensions/window_controller_list_observer.h',
       ],
       'conditions': [
+        ['os_bsd==1', {
+         'sources/': [
+            ['exclude', '^browser/extensions/api/image_writer_private/removable_storage_provider_linux.cc'],
+         ],
+        }],
         ['chromeos==1', {
           'dependencies': [
             '../build/linux/system.gyp:dbus',
@@ -1066,6 +1070,9 @@
           ],
         }],
         ['OS=="linux"', {
+	  'dependencies': [
+	    '../device/hid/hid.gyp:device_hid',
+	  ],
           'conditions': [
             ['use_aura==1', {
               'dependencies': [
