--- tools/gn/settings.cc.orig	2014-06-11 08:58:47.182718921 -0500
+++ tools/gn/settings.cc	2014-06-11 08:59:38.200718333 -0500
@@ -36,6 +36,8 @@
   target_os_ = MAC;
 #elif defined(OS_LINUX)
   target_os_ = LINUX;
+#elif defined(OS_FREEBSD)
+  target_os_ = FREEBSD;
 #elif defined(OS_ANDROID)
   // Currently we don't have an "Android" target OS, it looks just like Linux
   // from our perspective.
