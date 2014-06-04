--- chrome/browser/chrome_browser_main_linux.cc.orig	2014-06-03 11:43:06.041479286 -0500
+++ chrome/browser/chrome_browser_main_linux.cc	2014-06-03 11:43:42.784477420 -0500
@@ -43,5 +43,10 @@
   ChromeBrowserMainPartsPosix::PostProfileInit();
 
   g_browser_process->metrics_service()->RecordBreakpadRegistration(
-      breakpad::IsCrashReporterEnabled());
+#if defined(OS_LINUX)
+      breakpad::IsCrashReporterEnabled()
+#else
+      false
+#endif
+  );
 }
