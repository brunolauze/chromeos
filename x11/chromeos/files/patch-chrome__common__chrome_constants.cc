--- chrome/common/chrome_constants.cc.orig	2014-06-03 08:39:48.912259662 -0500
+++ chrome/common/chrome_constants.cc	2014-06-03 08:40:12.906242590 -0500
@@ -237,7 +237,7 @@
 // This is used by the PreRead experiment.
 const char kPreReadEnvironmentVariable[] = "CHROME_PRE_READ_EXPERIMENT";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 const int kLowestRendererOomScore = 300;
 const int kHighestRendererOomScore = 1000;
 #endif
