--- chrome/common/chrome_constants.h.orig	2014-06-03 08:38:31.581241087 -0500
+++ chrome/common/chrome_constants.h	2014-06-03 08:39:03.587268202 -0500
@@ -117,7 +117,7 @@
 // This is used by the PreRead experiment.
 extern const char kPreReadEnvironmentVariable[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // The highest and lowest assigned OOM score adjustment
 // (oom_score_adj) used by the OomPriority Manager.
 extern const int kLowestRendererOomScore;
