--- native_client/src/trusted/service_runtime/service_runtime.gyp.orig	2014-05-22 11:55:40.440509788 -0500
+++ native_client/src/trusted/service_runtime/service_runtime.gyp	2014-05-30 08:12:20.641247416 -0500
@@ -296,7 +296,7 @@
             '<(DEPTH)/native_client/src/trusted/validator_x86/validator_x86.gyp:nccopy_x86_64',
           ],
         }],
-        ['OS=="linux" or OS=="FreeBSD" or OS=="android"', {
+        ['OS=="linux" or OS=="freebsd" or OS=="android"', {
           'dependencies': [
             'nacl_signal',
           ],
@@ -445,7 +445,7 @@
         },
       ],
     }],
-    ['OS=="linux" or OS=="FreeBSD" or OS=="android"', {
+    ['OS=="linux" or OS=="freebsd" or OS=="android"', {
       'targets': [
         {
           # This has to be an independent target in order to benefit from
