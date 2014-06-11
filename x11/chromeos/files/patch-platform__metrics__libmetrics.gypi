--- platform/metrics/libmetrics.gypi.orig	2014-06-09 11:37:48.138056212 -0500
+++ platform/metrics/libmetrics.gypi	2014-06-09 14:14:45.318434478 -0500
@@ -8,8 +8,15 @@
         'libchrome-<(libbase_ver)',
       ]
     },
-    'cflags_cc': [
-      '-fno-exceptions',
+    'include_dirs': [
+      '../libchromeos',
+      '../..',
+      '/usr/local/include/dbus-1.0',
+      '/usr/local/include/dbus-1.0/include',
+      '/usr/local/include/glib-2.0',
+      '/usr/local/include/dbus-c++-1',
+      '../../testing/gtest/include',
+      '<(SHARED_INTERMEDIATE_DIR)/include',
     ],
   },
   'targets': [
