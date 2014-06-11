--- chromeos/chromeos.gyp.orig	2014-06-10 06:51:08.282375442 -0500
+++ chromeos/chromeos.gyp	2014-06-10 07:33:21.232203163 -0500
@@ -7,7 +7,8 @@
     'chromium_code': 1,
   },
   'includes': [
-    'chromeos_tools.gypi'
+    'chromeos_tools.gypi',
+    '../platform2/common-mk/common.gypi',
   ],
   'targets': [
     {
@@ -32,6 +33,7 @@
         'cryptohome_proto',
         'ime/input_method.gyp:gencode',
         'power_manager_proto',
+	'../platform2/common-mk/platform.gyp:All',
       ],
       'defines': [
         'CHROMEOS_IMPLEMENTATION',
