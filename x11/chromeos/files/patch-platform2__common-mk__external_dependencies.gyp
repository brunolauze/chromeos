--- platform2/common-mk/external_dependencies.gyp.orig	2014-06-09 08:09:57.617938671 -0500
+++ platform2/common-mk/external_dependencies.gyp	2014-06-09 09:18:03.358632467 -0500
@@ -5,7 +5,7 @@
       'type': 'none',
       'variables': {
         'xml2cpp_type': 'proxy',
-        'xml2cpp_in_dir': '<(sysroot)/usr/share/dbus-1/interfaces/',
+        'xml2cpp_in_dir': '<(sysroot)/usr/local/share/dbus-1/interfaces/',
         'xml2cpp_out_dir': 'include/dbus_proxies',
       },
       'sources': [
@@ -73,7 +73,7 @@
       'type': 'none',
       'variables': {
         'xml2cpp_type': 'proxy',
-        'xml2cpp_in_dir': '<(sysroot)/usr/share/dbus-1/interfaces/',
+        'xml2cpp_in_dir': '<(sysroot)/usr/local/share/dbus-1/interfaces/',
         'xml2cpp_out_dir': 'include/dbus_proxies',
       },
       'sources': [
@@ -85,8 +85,9 @@
       'target_name': 'policy-protos',
       'type': 'static_library',
       'variables': {
-        'proto_in_dir': '<(sysroot)/usr/include/proto',
+	'proto_in_dir': '../../components/policy/proto',
         'proto_out_dir': 'include/bindings',
+	'config_h_dir': '../../third_party/protobuf',
       },
       'cflags': [
         '-fvisibility=hidden',
@@ -98,14 +99,18 @@
         '<(proto_in_dir)/device_management_local.proto',
         '<(proto_in_dir)/install_attributes.proto',
       ],
-      'includes': ['../common-mk/protoc.gypi'],
+      'includes': [
+	'../common-mk/protoc.gypi',
+	'../../third_party/protobuf/protobuf_lite.gypi',
+      ],
     },
     {
       'target_name': 'feedback-protos',
       'type': 'static_library',
       'variables': {
-        'proto_in_dir': '<(sysroot)/usr/include/proto',
+        'proto_in_dir': '../../chrome/browser/feedback/proto',
         'proto_out_dir': 'include/bindings',
+	'config_h_dir': '../../third_party/protobuf',
       },
       'cflags': [
         '-fvisibility=hidden',
@@ -120,7 +125,10 @@
         '<(proto_in_dir)/math.proto',
         '<(proto_in_dir)/web.proto',
       ],
-      'includes': ['../common-mk/protoc.gypi'],
+      'includes': [
+        '../common-mk/protoc.gypi',
+        '../../third_party/protobuf/protobuf_lite.gypi',
+      ],
     },
   ],
 }
