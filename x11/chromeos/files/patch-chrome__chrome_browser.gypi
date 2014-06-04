--- chrome/chrome_browser.gypi.orig	2014-06-02 21:54:29.854127084 -0500
+++ chrome/chrome_browser.gypi	2014-06-03 10:52:15.943689177 -0500
@@ -1152,8 +1152,8 @@
         'browser/media_galleries/imported_media_gallery_registry.h',
         'browser/media_galleries/linux/mtp_device_delegate_impl_linux.cc',
         'browser/media_galleries/linux/mtp_device_delegate_impl_linux.h',
-        'browser/media_galleries/linux/mtp_device_object_enumerator.cc',
-        'browser/media_galleries/linux/mtp_device_object_enumerator.h',
+        #'browser/media_galleries/linux/mtp_device_object_enumerator.cc',
+        #'browser/media_galleries/linux/mtp_device_object_enumerator.h',
         'browser/media_galleries/linux/mtp_device_task_helper.cc',
         'browser/media_galleries/linux/mtp_device_task_helper.h',
         'browser/media_galleries/linux/mtp_device_task_helper_map_service.cc',
@@ -2949,7 +2949,7 @@
             '../device/media_transfer_protocol/media_transfer_protocol.gyp:device_media_transfer_protocol',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" and chromeos==0) or os_bsd==1', {
           'dependencies': [
             '../build/linux/system.gyp:libspeechd',
           ],
@@ -3076,7 +3076,7 @@
             '../build/linux/system.gyp:xscrnsaver',
           ],
         }],
-        ['os_posix == 1 and OS != "mac" and OS != "ios"', {
+        ['os_posix == 1 and OS != "mac" and OS != "ios" and os_bsd != 1', {
           'sources': [
             'app/chrome_breakpad_client.cc',
             'app/chrome_breakpad_client.h',
@@ -3314,6 +3314,23 @@
             ['exclude', '^third_party/mozilla_security_manager/'],
           ],
         }],
+        ['os_bsd==1', {
+          'sources/': [
+            ['exclude', '^browser/media_galleries/linux/'],
+            ['exclude', '^browser/storage_monitor/media_transfer_protocol_device_observer_linux.cc'],
+            ['exclude', '^browser/storage_monitor/media_transfer_protocol_device_observer_linux.h'],
+            ['exclude', '^browser/storage_monitor/removable_device_notifications_linux.cc'],
+            ['exclude', '^browser/storage_monitor/removable_device_notifications_linux.h'],
+            ['exclude', '^browser/storage_monitor/storage_monitor_linux.cc'],
+            ['exclude', '^browser/storage_monitor/storage_monitor_linux.h'],
+            ['exclude', '^browser/storage_monitor/udev_util_linux.cc'],
+            ['exclude', '^browser/storage_monitor/udev_util_linux.h'],
+            ['exclude', '^browser/storage_monitor/test_media_transfer_protocol_manager_linux.cc'],
+            ['exclude', '^browser/storage_monitor/test_media_transfer_protocol_manager_linux.h'],
+            ['exclude', '^browser/storage_monitor/mtab_watcher_linux.cc'],
+            ['exclude', '^browser/storage_monitor/mtab_watcher_linux.h'],
+          ],
+        }],
         ['OS=="mac"', {
           'dependencies': [
             '../third_party/google_toolbox_for_mac/google_toolbox_for_mac.gyp:google_toolbox_for_mac',
