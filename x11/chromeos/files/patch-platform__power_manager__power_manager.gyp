--- platform/power_manager/power_manager.gyp.orig	2014-06-09 08:27:19.889843857 -0500
+++ platform/power_manager/power_manager.gyp	2014-06-10 08:07:20.670089304 -0500
@@ -3,7 +3,6 @@
     'variables': {
       'deps': [
         'libchrome-<(libbase_ver)',
-        'libudev',
         'protobuf-lite',
       ],
     },
@@ -11,11 +10,11 @@
       '../system_api/system_api.gyp:system_api-headers',
       '../system_api/system_api.gyp:system_api-power_manager-protos',
     ],
-    'link_settings': {
-      'libraries': [
-        '-lgflags',
-      ],
-    },
+    'include_dirs': [
+      '../..',
+      '../../platform',
+      '../../platform2/libchromeos',
+    ],
     'cflags_cc': [
       '-std=gnu++11',
     ],
