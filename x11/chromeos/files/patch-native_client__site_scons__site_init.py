--- native_client/site_scons/site_init.py.orig	2014-06-03 22:12:08.788984551 -0500
+++ native_client/site_scons/site_init.py	2014-06-03 22:13:58.818977057 -0500
@@ -40,10 +40,10 @@
   target_platform tool for your environments.  When you call
   BuildEnvironments(), only environments with the current host platform will be
   built.  If for some reason you really need to examine the host platform,
-  check env.Bit('host_windows') / env.Bit('host_linux') / env.Bit('host_mac').
+  check env.Bit('host_windows') / env.Bit('host_linux') / env.Bit('host_freebsd') / env.Bit('host_mac').
 
   Returns:
-    The host platform name - one of ('WINDOWS', 'LINUX', 'MAC').
+    The host platform name - one of ('WINDOWS', 'LINUX', 'FREEBSD', 'MAC').
   """
 
   platform_map = {
@@ -52,6 +52,8 @@
       'linux': 'LINUX',
       'linux2': 'LINUX',
       'linux3': 'LINUX',
+      'freebsd': 'FREEBSD',
+      'freebsd11': 'FREEBSD',
       'darwin': 'MAC',
   }
 
@@ -149,6 +151,8 @@
       'cygwin': 'win',
       'linux': 'linux',
       'linux2': 'linux',
+      'freebsd': 'freebsd',
+      'freebsd11': 'freebsd',
       'darwin': 'mac',
       }
   if sys.platform in platform_map:
