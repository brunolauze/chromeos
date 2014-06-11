--- platform2/libchromeos/libchromeos.gypi.orig	2014-06-09 08:46:17.333765794 -0500
+++ platform2/libchromeos/libchromeos.gypi	2014-06-09 13:42:19.380539441 -0500
@@ -10,7 +10,38 @@
     },
     'include_dirs': [
       '../libchromeos',
+      '../..',
+      '/usr/local/include/dbus-1.0',
+      '/usr/local/include/dbus-1.0/include',
+      '/usr/local/include/glib-2.0',
+      '/usr/local/include/dbus-c++-1',
+      '../../testing/gtest/include',
+      '<(SHARED_INTERMEDIATE_DIR)/include',
     ],
+    'dependencies': [
+      '../../base/base.gyp:base',
+      '../../base/base.gyp:base_i18n',
+      '../../base/base.gyp:base_static',
+    ],
+      'link_settings': {
+        'variables': {
+          'deps': [
+            'dbus-c++-1',
+            'gio-2.0',
+            'glib-2.0',
+            'libcares',
+            'libnl-3.0',
+            'libnl-genl-3.0',
+            'protobuf-lite',
+          ],
+        },
+        'libraries': [
+          '-lssl',
+	  '-L/usr/local/lib -ldbus-1',
+	  '-L/usr/local/lib -ldbus-glib-1',
+	  '-L/usr/local/lib -ldbus-c++-1',
+        ],
+      },
   },
   'targets': [
     {
@@ -25,6 +56,13 @@
       'direct_dependent_settings': {
         'include_dirs': [
           '../libchromeos',
+	  '../..'
+      	  '/usr/local/include/dbus-1.0',
+	  '/usr/local/include/dbus-1.0/include',
+     	  '/usr/local/include/glib-2.0',
+      	  '/usr/local/include/dbus-c++-1',
+      	  '../../testing/gtest/include',
+	  '<(SHARED_INTERMEDIATE_DIR)/include',
         ],
       },
       'includes': ['../../platform2/common-mk/deps.gypi'],
@@ -113,6 +151,9 @@
       'dependencies': [
         '../libchromeos/libpolicy.gyp:*',
         '../../platform2/common-mk/external_dependencies.gyp:policy-protos',
+	'../../base/base.gyp:base',
+        '../../base/base.gyp:base_i18n',
+        '../../base/base.gyp:base_static',
       ],
       'variables': {
         'exported_deps': [
@@ -130,7 +171,7 @@
         },
       },
       'ldflags': [
-        '-Wl,--version-script,<(platform2_root)/libchromeos/libpolicy.ver',
+        '-Wl,--version-script,<(platform2_root)/libchromeos/libpolicy.ver -lssl',
       ],
       'sources': [
         'chromeos/policy/device_policy.cc',
