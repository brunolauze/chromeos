--- native_client/src/shared/platform/platform.gyp.orig	2014-05-22 11:55:40.312509913 -0500
+++ native_client/src/shared/platform/platform.gyp	2014-05-30 07:54:50.753318057 -0500
@@ -36,7 +36,7 @@
       'refcount_base.cc',
     ],
     'conditions': [
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="android" or OS=="freebsd"', {
         'platform_sources': [
           'linux/nacl_clock.c',
           'linux/nacl_host_dir.c',
