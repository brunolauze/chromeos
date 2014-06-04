--- components/nacl.gyp.orig	2014-05-30 08:55:53.160066589 -0500
+++ components/nacl.gyp	2014-05-30 09:01:49.607043254 -0500
@@ -52,7 +52,7 @@
               '<(DEPTH)/third_party/wtl/include',
             ],
           },],
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="freebsd"', {
             'defines': [
               '__STDC_LIMIT_MACROS=1',
             ],
@@ -228,7 +228,7 @@
         },
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'targets': [
             {
               'target_name': 'nacl_helper',
@@ -306,8 +306,6 @@
                 'nacl_switches',
                 '../components/tracing.gyp:tracing',
                 '../crypto/crypto.gyp:crypto',
-                '../sandbox/sandbox.gyp:libc_urandom_override',
-                '../sandbox/sandbox.gyp:sandbox',
                 '../ppapi/ppapi_internal.gyp:ppapi_proxy',
               ],
               'conditions': [
@@ -316,6 +314,12 @@
                     '../build/linux/system.gyp:glib',
                   ],
                 }],
+		['OS=="linux"', {
+		  'dependencies': [
+                    '../sandbox/sandbox.gyp:libc_urandom_override',
+                    '../sandbox/sandbox.gyp:sandbox',
+		  ],
+		}],
                 ['os_posix == 1 and OS != "mac"', {
                   'conditions': [
                     ['use_allocator!="none"', {
