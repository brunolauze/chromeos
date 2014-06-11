--- platform/shill/shill.gyp.orig	2014-06-09 07:30:37.449081668 -0500
+++ platform/shill/shill.gyp	2014-06-09 14:38:57.791328879 -0500
@@ -19,12 +19,19 @@
       '-Woverloaded-virtual',
       '-Wno-format-nonliteral',  # gcc.gnu.org/bugzilla/show_bug.cgi?id=31843
       '-Wno-missing-field-initializers',  # for LAZY_INSTANCE_INITIALIZER
+      '-I../..',
+    ],
+    'include_dirs': [
+	'.',
+	'..'
+	'../..',
+	'../../platform',
     ],
     'defines': [
       '__STDC_FORMAT_MACROS',
       '__STDC_LIMIT_MACROS',
       'RUNDIR="/var/run/shill"',
-      'SHIMDIR="<(libdir)/shill/shims"',
+      'SHIMDIR="/usr/local/lib/shill/shims"',
     ],
     'conditions': [
       ['USE_cellular == 0', {
@@ -50,36 +57,43 @@
       'type': 'static_library',
       'variables': {
         'proto_in_dir': 'mobile_operator_db',
-        'proto_out_dir':
-            'include/shill/proto_bindings/mobile_operator_db'
+        'proto_out_dir': 'include/shill/proto_bindings/mobile_operator_db',
+	'config_h_dir': '../../third_party/protobuf',
       },
       'sources': [
         '<(proto_in_dir)/mobile_operator_db.proto'
       ],
-      'includes': ['../../platform2/common-mk/protoc.gypi'],
-    },
-    {
-      'target_name': 'mobile_operator_db-db',
-      'type': 'none',
-      'variables' : {
-        'protoc_proto_dir': 'mobile_operator_db',
-        'protoc_proto_def': 'mobile_operator_db.proto',
-        'protoc_text_dir': 'mobile_operator_db',
-        'protoc_bin_dir': '<(PRODUCT_DIR)',
-        'protoc_message_name': 'shill.mobile_operator_db.MobileOperatorDB',
-      },
-      'sources': [
-        '<(protoc_text_dir)/serviceproviders.prototxt',
-        '<(protoc_text_dir)/additional_providers.prototxt',
-      ],
-      'includes': ['../../platform2/common-mk/protoctxt.gypi'],
-    },
+      'includes': [
+	'../../platform2/common-mk/protoc.gypi',
+	'../../third_party/protobuf/protobuf_lite.gypi',
+      ],
+    },
+#    {
+#      'target_name': 'mobile_operator_db-db',
+#      'type': 'none',
+#      'variables' : {
+#        'protoc_proto_dir': 'mobile_operator_db',
+#        'protoc_proto_def': 'mobile_operator_db.proto',
+#        'protoc_text_dir': 'mobile_operator_db',
+#        'protoc_bin_dir': '<(PRODUCT_DIR)',
+#        'protoc_message_name': 'shill.mobile_operator_db.MobileOperatorDB',
+#	'config_h_dir': '../../third_party/protobuf',
+#      },
+#      'sources': [
+#        '<(protoc_text_dir)/serviceproviders.prototxt',
+#        '<(protoc_text_dir)/additional_providers.prototxt',
+#      ],
+#      'includes': [
+#	'../../platform2/common-mk/protoctxt.gypi',
+#	'../../third_party/protobuf/protobuf_lite.gypi',
+#      ],
+#    },
     {
       'target_name': 'mobile_operator_db',
       'type': 'static_library',
       'dependencies': [
         'mobile_operator_db-protos',
-        'mobile_operator_db-db',
+        #'mobile_operator_db-db',
       ],
     },
     {
@@ -140,11 +154,15 @@
       'variables': {
         'proto_in_dir': 'shims/protos',
         'proto_out_dir': 'include/shill/proto_bindings/shims/protos',
+	'config_h_dir': '../../third_party/protobuf',
       },
       'sources': [
         '<(proto_in_dir)/crypto_util.proto',
       ],
-      'includes': ['../../platform2/common-mk/protoc.gypi'],
+      'includes': [
+	'../../platform2/common-mk/protoc.gypi',
+	'../../third_party/protobuf/protobuf_lite.gypi',
+      ],
     },
     {
       'target_name': 'crypto_util',
@@ -152,7 +170,23 @@
       'dependencies': ['shim-protos'],
       'sources': [
         'shims/crypto_util.cc',
-      ]
+      ],
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
+        ],
+      },
     },
     {
       'target_name': 'libshill',
@@ -197,6 +231,7 @@
           ],
         },
         'libraries': [
+	  '-lssl',
           '-lbootstat',
           '-lminijail',
           '-lrootdev',
@@ -449,21 +484,21 @@
         'shims/nss_get_cert.cc',
       ]
     },
-    {
-      'target_name': 'netfilter-queue-helper',
-      'type': 'executable',
-      'variables': {
-        'deps': [
-          'libmnl',
-          'libnetfilter_queue',
-          'libnfnetlink',
-        ],
-      },
-      'sources': [
-        'shims/netfilter_queue_helper.cc',
-        'shims/netfilter_queue_processor.cc',
-      ]
-    },
+#    {
+#      'target_name': 'netfilter-queue-helper',
+#      'type': 'executable',
+#      'variables': {
+#        'deps': [
+#          'libmnl',
+#          'libnetfilter_queue',
+#          'libnfnetlink',
+#        ],
+#      },
+#      'sources': [
+#        'shims/netfilter_queue_helper.cc',
+#        'shims/netfilter_queue_processor.cc',
+#      ]
+#    },
     {
       'target_name': 'openvpn-script',
       'type': 'executable',
