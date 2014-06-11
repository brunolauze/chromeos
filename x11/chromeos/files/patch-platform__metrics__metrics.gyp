--- platform/metrics/metrics.gyp.orig	2014-06-09 11:23:40.782115177 -0500
+++ platform/metrics/metrics.gyp	2014-06-09 14:13:45.755455890 -0500
@@ -5,6 +5,9 @@
   'target_defaults': {
     'dependencies': [
       '../../platform2/libchromeos/libchromeos-<(libbase_ver).gyp:libchromeos-<(libbase_ver)',
+      '../../base/base.gyp:base',
+      '../../base/base.gyp:base_i18n',
+      '../../base/base.gyp:base_static',
     ],
     'variables': {
       'deps': [
@@ -16,8 +19,16 @@
         'libchrome-<(libbase_ver)',
       ]
     },
-    'cflags_cc': [
-      '-fno-exceptions',
+    'include_dirs': [
+      '../libchromeos',
+      '../..',
+      '/usr/local/include',
+      '/usr/local/include/dbus-1.0',
+      '/usr/local/include/dbus-1.0/include',
+      '/usr/local/include/glib-2.0',
+      '/usr/local/include/dbus-c++-1',
+      '../../testing/gtest/include',
+      '<(SHARED_INTERMEDIATE_DIR)/include',
     ],
   },
   'targets': [
@@ -29,8 +40,7 @@
       ],
       'link_settings': {
         'libraries': [
-          '-lrootdev',
-          '-lgflags',
+          '-L/usr/local/lib -lrootdev',
         ],
       },
       'sources': [
