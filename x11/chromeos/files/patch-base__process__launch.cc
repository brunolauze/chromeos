--- base/process/launch.cc.orig	2014-05-30 12:21:51.503216061 -0500
+++ base/process/launch.cc	2014-05-30 12:22:57.517211745 -0500
@@ -23,10 +23,10 @@
       fds_to_remap(NULL),
       maximize_rlimits(NULL),
       new_process_group(false)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
       , clone_flags(0)
       , allow_new_privs(false)
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_FREEBSD
 #if defined(OS_CHROMEOS)
       , ctrl_terminal_fd(-1)
 #endif  // OS_CHROMEOS
@@ -39,7 +39,7 @@
 
 LaunchOptions LaunchOptionsForTest() {
   LaunchOptions options;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // To prevent accidental privilege sharing to an untrusted child, processes
   // are started with PR_SET_NO_NEW_PRIVS. Do not set that here, since this
   // new child will be used for testing only.
