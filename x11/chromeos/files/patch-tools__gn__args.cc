--- tools/gn/args.cc.orig	2014-06-11 08:56:56.050733052 -0500
+++ tools/gn/args.cc	2014-06-11 08:57:30.393748907 -0500
@@ -222,6 +222,8 @@
   os = "mac";
 #elif defined(OS_LINUX)
   os = "linux";
+#elif defined(OS_FREEBSD)
+  os = "freebsd";
 #elif defined(OS_ANDROID)
   os = "android";
 #else
