--- mojo/mojo_services.gypi.orig	2014-06-04 09:16:15.817237580 -0500
+++ mojo/mojo_services.gypi	2014-06-04 09:17:01.936298278 -0500
@@ -147,7 +147,7 @@
         'services/native_viewport/native_viewport_x11.cc',
       ],
       'conditions': [
-        ['OS=="win" or OS=="android" or OS=="linux" or OS=="mac"', {
+        ['OS=="win" or OS=="android" or OS=="linux" or OS=="freebsd" or OS=="mac"', {
           'sources!': [
             'services/native_viewport/native_viewport_stub.cc',
           ],
@@ -352,7 +352,7 @@
         },
       ],
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'targets': [
         {
           'target_name': 'mojo_dbus_echo_service',
