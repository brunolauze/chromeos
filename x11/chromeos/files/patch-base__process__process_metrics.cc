--- base/process/process_metrics.cc.orig	2014-06-03 11:45:54.113493280 -0500
+++ base/process/process_metrics.cc	2014-06-03 11:46:38.648492453 -0500
@@ -21,7 +21,7 @@
   GetSystemMemoryInfo(&system_metrics.memory_info_);
   GetSystemDiskInfo(&system_metrics.disk_info_);
 #endif
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) && defined(OS_LINUX)
   GetSwapInfo(&system_metrics.swap_info_);
 #endif
 
@@ -36,7 +36,7 @@
   res->Set("meminfo", memory_info_.ToValue().release());
   res->Set("diskinfo", disk_info_.ToValue().release());
 #endif
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) && defined(OS_LINUX)
   res->Set("swapinfo", swap_info_.ToValue().release());
 #endif
 
