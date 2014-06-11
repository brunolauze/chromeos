--- build/all.gyp.orig	2014-06-10 09:30:50.744740583 -0500
+++ build/all.gyp	2014-06-10 14:23:24.335992792 -0500
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
@@ -1200,7 +1218,7 @@
       ],  # targets
     }, {
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           # TODO(thakis): Remove this once the linux gtk bot no longer references
           # it (probably after the first aura release on linux), see r249162
           'targets': [
@@ -1212,7 +1230,7 @@
               ],
             },
           ],  # targets
-      }]], # OS=="linux"
+      }]], # OS=="linux" or OS=="freebsd"
     }], # "use_aura==1"
     ['test_isolation_mode != "noop"', {
       'targets': [
