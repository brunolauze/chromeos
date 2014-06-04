--- build/all.gyp.orig	2014-06-03 11:26:30.053546858 -0500
+++ build/all.gyp	2014-06-03 11:28:03.842540759 -0500
@@ -152,6 +152,24 @@
             }],
           ],
         }],
+        ['OS=="freebsd"', {
+          'dependencies': [
+            '../courgette/courgette.gyp:*',
+            '../dbus/dbus.gyp:*',
+          ],
+          'conditions': [
+            ['branding=="Chrome"', {
+              'dependencies': [
+                '../chrome/chrome.gyp:linux_packages_<(channel)',
+              ],
+            }],
+            ['enable_ipc_fuzzer==1', {
+              'dependencies': [
+                '../tools/ipc_fuzzer/ipc_fuzzer.gyp:*',
+              ],
+            }],
+          ],
+	}],
         ['use_x11==1', {
           'dependencies': [
             '../tools/xdisplaycheck/xdisplaycheck.gyp:*',
