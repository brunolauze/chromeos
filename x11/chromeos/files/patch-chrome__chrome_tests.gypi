--- chrome/chrome_tests.gypi.orig	2014-06-04 11:51:36.302617862 -0500
+++ chrome/chrome_tests.gypi	2014-06-04 11:58:51.996567325 -0500
@@ -159,14 +159,14 @@
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
           ],
         }],
-        ['OS=="linux" and use_aura==1', {
+        ['(OS=="linux" or OS=="freebsd") and use_aura==1', {
           # TODO(gbillock): aura linux does not support the automation for
           # SendMouseMoveNotifyWhenDone
           'sources!': [
             'browser/ui/views/toolbar/toolbar_button_test.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:ssl',
           ],
@@ -1707,7 +1707,7 @@
                 'chrome.gyp:chrome_nacl_win64',
               ],
             }],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'dependencies': [
                 '../native_client/src/trusted/service_runtime/linux/nacl_bootstrap.gyp:nacl_helper_bootstrap',
                 '../components/nacl.gyp:nacl_helper',
@@ -1857,7 +1857,7 @@
             'browser/ui/views/frame/browser_non_client_frame_view_ash_browsertest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:ssl',
           ],
@@ -1967,7 +1967,7 @@
             '../v8/src/d8.gyp:d8#host',
           ],
         }],
-        ['OS!="android" and OS!="ios" and OS!="linux"', {
+        ['OS!="android" and OS!="ios" and OS!="linux" and OS!="freebsd"', {
           # npapi test plugin doesn't build on android or ios
           'dependencies': [
             # build time dependency.
@@ -2178,7 +2178,7 @@
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:ssl',
           ],
@@ -2406,7 +2406,7 @@
         'browser/sync/test/integration/two_client_typed_urls_sync_test.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:ssl',
           ],
@@ -2510,7 +2510,7 @@
         'test/data/resource.rc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:ssl',
           ],
@@ -2698,7 +2698,7 @@
                 }],
               ],
             }],
-            ['OS=="linux" and enable_webrtc==1', {
+            ['(OS=="linux" or OS=="freebsd") and enable_webrtc==1', {
               'dependencies': [
                 '../third_party/libjingle/libjingle.gyp:libpeerconnection',
               ],
