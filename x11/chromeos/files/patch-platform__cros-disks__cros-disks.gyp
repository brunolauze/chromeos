--- platform/cros-disks/cros-disks.gyp.orig	2014-06-09 14:06:12.527442642 -0500
+++ platform/cros-disks/cros-disks.gyp	2014-06-09 14:09:57.481425220 -0500
@@ -5,23 +5,43 @@
       '../metrics/libmetrics-<(libbase_ver).gyp:libmetrics-<(libbase_ver)',
     ],
     'libraries': [
-      '-lminijail',
+      #'-lminijail',
       '-lrootdev',
+      '-lssl',
+    ],
+    'include_dirs': [
+      '../..',
+      '../../platform',
     ],
     'variables': {
       'deps': [
-        'blkid',
         'dbus-c++-1',
         'glib-2.0',
         'gobject-2.0',
         'gthread-2.0',
         'libchrome-<(libbase_ver)',
-        'libudev',
       ],
     },
     'cflags_cc': [
       '-std=gnu++11',
     ],
+      'link_settings': {
+        'variables': {
+          'deps': [
+            'dbus-c++-1',
+            'gio-2.0',
+            'glib-2.0',
+            'libcares',
+            'protobuf-lite',
+          ],
+        },
+        'libraries': [
+          '-lssl',
+          '-L/usr/local/lib -ldbus-1',
+          '-L/usr/local/lib -ldbus-glib-1',
+          '-L/usr/local/lib -ldbus-c++-1',
+        ],
+      },
   },
   'targets': [
     {
