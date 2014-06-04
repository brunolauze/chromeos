--- native_client/build/common.gypi.orig	2014-05-29 22:02:30.777769503 -0500
+++ native_client/build/common.gypi	2014-05-30 07:50:24.158342471 -0500
@@ -281,7 +281,7 @@
     ],
   },
   'conditions': [
-    ['OS=="linux" or OS=="android"', {
+    ['OS=="linux" or OS=="android" or OS=="freebsd"', {
       'target_defaults': {
         # Enable -Werror by default, but put it in a variable so it can
         # be disabled in ~/.gyp/include.gypi on the valgrind builders.
@@ -295,7 +295,7 @@
           '-Wall', # TODO(bradnelson): why does this disappear?!?
         ],
         'conditions': [
-          ['nacl_standalone==1 and OS=="linux"', {
+          ['nacl_standalone==1 and (OS=="linux" or OS=="freebsd")', {
             'cflags': ['-fPIC'],
           }],
           ['OS=="android"', {
