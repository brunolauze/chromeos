--- platform2/common-mk/protoc.gypi.orig	2014-06-09 20:14:00.808237309 -0500
+++ platform2/common-mk/protoc.gypi	2014-06-09 20:29:57.950224579 -0500
@@ -2,8 +2,11 @@
   'variables': {
     'cc_dir': '<(SHARED_INTERMEDIATE_DIR)/<(proto_out_dir)',
     'proto_in_dir%': '.',
-    'protoc': '<!(which protoc)',
+    'protoc': '<(PRODUCT_DIR)/protoc',
   },
+  'dependencies': [
+    '../../third_party/protobuf/protobuf.gyp:protoc',
+  ],
   'rules': [
     {
       'rule_name': 'genproto',
