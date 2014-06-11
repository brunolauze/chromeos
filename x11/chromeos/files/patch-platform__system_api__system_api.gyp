--- platform/system_api/system_api.gyp.orig	2014-06-10 09:31:01.360714264 -0500
+++ platform/system_api/system_api.gyp	2014-06-10 09:38:47.108711071 -0500
@@ -6,6 +6,7 @@
       'variables': {
         'proto_in_dir': 'dbus',
         'proto_out_dir': 'include/system_api/proto_bindings',
+	'config_h_dir': '../../third_party/protobuf',
       },
       'cflags': [
         '-fvisibility=hidden',
@@ -15,7 +16,12 @@
         '<(proto_in_dir)/mtp_file_entry.proto',
         '<(proto_in_dir)/field_trial_list.proto',
       ],
-      'includes': ['../../platform2/common-mk/protoc.gypi'],
+      'includes': [
+        '../../platform2/common-mk/protoc.gypi'
+      ],
+      'dependencies': [
+	'../../third_party/protobuf/protobuf.gyp:protobuf_lite',
+      ],
     },
     {
       'target_name': 'system_api-power_manager-protos',
@@ -23,6 +29,7 @@
       'variables': {
         'proto_in_dir': 'dbus/power_manager',
         'proto_out_dir': 'include/power_manager/proto_bindings',
+	'config_h_dir': '../../third_party/protobuf',
       },
       'cflags': [
         '-fvisibility=hidden',
@@ -34,7 +41,12 @@
         '<(proto_in_dir)/policy.proto',
         '<(proto_in_dir)/power_supply_properties.proto',
       ],
-      'includes': ['../../platform2/common-mk/protoc.gypi'],
+      'includes': [
+	'../../platform2/common-mk/protoc.gypi'
+      ],
+      'include_dirs': [
+        '../../third_party/protobuf/src',
+      ],
     },
     {
       'target_name': 'system_api-cryptohome-protos',
@@ -42,6 +54,7 @@
       'variables': {
         'proto_in_dir': 'dbus/cryptohome',
         'proto_out_dir': 'include/cryptohome/proto_bindings',
+	'config_h_dir': '../../third_party/protobuf',
       },
       'cflags': [
         '-fvisibility=hidden',
@@ -51,7 +64,12 @@
         '<(proto_in_dir)/rpc.proto',
         '<(proto_in_dir)/signed_secret.proto',
       ],
-      'includes': ['../../platform2/common-mk/protoc.gypi'],
+      'includes': [
+        '../../platform2/common-mk/protoc.gypi'
+      ],
+      'include_dirs': [
+	'../../third_party/protobuf/src',
+      ],
     },
     {
       'target_name': 'system_api-headers',
