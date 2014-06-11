--- platform2/common-mk/protoctxt.gypi.orig	2014-06-09 07:33:16.233065676 -0500
+++ platform2/common-mk/protoctxt.gypi	2014-06-09 20:30:17.839224844 -0500
@@ -21,7 +21,7 @@
   'variables': {
     'protoc_proto_dir%': '.',
     'protoc_text_dir%': '.',
-    'protoc': '<!(which protoc)',
+    'protoc': '<(PRODUCT_DIR)/protoc',
   },
   'rules': [
     {
