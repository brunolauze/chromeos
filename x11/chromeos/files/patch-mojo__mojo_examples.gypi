--- mojo/mojo_examples.gypi.orig	2014-06-04 09:15:07.930243381 -0500
+++ mojo/mojo_examples.gypi	2014-06-04 09:15:27.787244583 -0500
@@ -333,7 +333,7 @@
         },
       ],
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'targets': [
         {
           'target_name': 'mojo_dbus_echo',
