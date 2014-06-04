--- chrome/browser/chromeos/system/syslogs_provider.cc.orig	2014-06-03 09:13:07.511103341 -0500
+++ chrome/browser/chromeos/system/syslogs_provider.cc	2014-06-03 09:14:58.342090849 -0500
@@ -36,9 +36,17 @@
 namespace {
 
 const char kSysLogsScript[] =
+#if defined(OS_FREEBSD)
+    "/usr/local/share/chromium/userfeedback/scripts/sysinfo_script_runner";
+#else
     "/usr/share/userfeedback/scripts/sysinfo_script_runner";
+#endif
 const char kBzip2Command[] =
+#if defined(OS_FREEBSD)
+    "/usr/bin/bzip2";
+#else
     "/bin/bzip2";
+#endif
 const char kMultilineQuote[] = "\"\"\"";
 const char kNewLineChars[] = "\r\n";
 const char kInvalidLogEntry[] = "<invalid characters in log entry>";
