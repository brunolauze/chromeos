--- native_client/pynacl/platform.py.orig	2014-06-03 21:55:54.422049769 -0500
+++ native_client/pynacl/platform.py	2014-06-03 21:57:59.988043022 -0500
@@ -18,18 +18,21 @@
     'win',
     'mac',
     'linux',
+    'freebsd',
 ]
 
 (
     OS_WIN,
     OS_MAC,
     OS_LINUX,
+    OS_FREEBSD,
 ) = OS_LIST
 
 OS_MAP = {
     OS_WIN: ('win', 'win32', 'cygwin'),
     OS_MAC: ('mac', 'darwin'),
     OS_LINUX: ('linux', 'linux2', 'linux3'),
+    OS_FREEBSD: ('freebsd', 'freebsd11'),
 }
 
 OS_DICT = dict([(platform, os_name)
@@ -169,6 +172,14 @@
       return 'i686-linux'
     elif arch3264 == ARCH3264_X86_64:
       return 'x86_64-linux'
+  elif os == OS_FREEBSD:
+    if arch3264 == ARCH3264_ARM:
+      # TODO(mcgrathr): How to distinguish gnueabi vs gnueabihf?
+      return 'arm-freebsd-gnueabihf'
+    elif arch3264 == ARCH3264_X86_32:
+      return 'i686-freebsd'
+    elif arch3264 == ARCH3264_X86_64:
+      return 'x86_64-freebsd'
 
   raise Exception('Unknown platform and machine')
 
