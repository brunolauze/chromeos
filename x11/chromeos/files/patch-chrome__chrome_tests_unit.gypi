--- chrome/chrome_tests_unit.gypi.orig	2014-05-24 12:44:57.087397400 -0500
+++ chrome/chrome_tests_unit.gypi	2014-05-25 14:16:55.096757262 -0500
@@ -486,7 +486,6 @@
         'test_support_common',
         'test_support_unit',
         # 3) anything tests directly depend on
-        '../courgette/courgette.gyp:courgette_lib',
         '../google_apis/google_apis.gyp:google_apis',
         '../skia/skia.gyp:skia',
         '../third_party/cacheinvalidation/cacheinvalidation.gyp:cacheinvalidation',
@@ -788,12 +787,12 @@
         'browser/command_updater_unittest.cc',
         'browser/component_updater/test/cld_component_installer_unittest.cc',
         'browser/component_updater/test/component_installers_unittest.cc',
-        'browser/component_updater/test/component_patcher_unittest.cc',
-        'browser/component_updater/test/component_updater_ping_manager_unittest.cc',
-        'browser/component_updater/test/component_updater_service_unittest.cc',
+        #'browser/component_updater/test/component_patcher_unittest.cc',
+        #'browser/component_updater/test/component_updater_ping_manager_unittest.cc',
+        #'browser/component_updater/test/component_updater_service_unittest.cc',
         'browser/component_updater/test/crx_downloader_unittest.cc',
         'browser/component_updater/test/test_installer.cc',
-        'browser/component_updater/test/update_checker_unittest.cc',
+        #'browser/component_updater/test/update_checker_unittest.cc',
         'browser/component_updater/test/update_response_unittest.cc',
         'browser/component_updater/test/url_request_post_interceptor.cc',
         'browser/content_settings/content_settings_default_provider_unittest.cc',
@@ -1067,7 +1066,7 @@
         'browser/media/webrtc_log_uploader_unittest.cc',
         'browser/media/webrtc_log_util_unittest.cc',
         'browser/media_galleries/fileapi/native_media_file_util_unittest.cc',
-        'browser/media_galleries/linux/mtp_device_object_enumerator_unittest.cc',
+        #'browser/media_galleries/linux/mtp_device_object_enumerator_unittest.cc',
         'browser/media_galleries/mac/mtp_device_delegate_impl_mac_unittest.mm',
         'browser/media_galleries/win/mtp_device_delegate_impl_win_unittest.cc',
         'browser/media_galleries/media_file_system_registry_unittest.cc',
