--- mojo/mojo.gyp.orig	2014-06-04 08:55:39.567322609 -0500
+++ mojo/mojo.gyp	2014-06-04 08:56:31.118347896 -0500
@@ -81,7 +81,7 @@
             'mojo_test_apk',
           ],
         }],
-        ['OS == "linux"', {
+        ['OS == "linux" or OS == "freebsd"', {
           'dependencies': [
             'mojo_dbus_echo',
             'mojo_dbus_echo_service',
@@ -519,7 +519,7 @@
         'shell/view_manager_loader.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS == "freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:dbus',
             '../dbus/dbus.gyp:dbus',
@@ -839,7 +839,7 @@
         }
       ],
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'targets': [
         {
           'target_name': 'mojo_dbus_service',
