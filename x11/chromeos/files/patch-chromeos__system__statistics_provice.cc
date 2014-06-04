--- chromeos/system/statistics_provider.cc.orig	2014-06-03 09:00:26.208207146 -0500
+++ chromeos/system/statistics_provider.cc	2014-06-03 09:01:47.120146366 -0500
@@ -30,7 +30,11 @@
 
 // Path to the tool used to get system info, and delimiters for the output
 // format of the tool.
+#if defined(OS_FREEBSD)
+const char* kCrosSystemTool[] = { "/usr/local/bin/crossystem" };
+#else
 const char* kCrosSystemTool[] = { "/usr/bin/crossystem" };
+#endif
 const char kCrosSystemEq[] = "=";
 const char kCrosSystemDelim[] = "\n";
 const char kCrosSystemCommentDelim[] = "#";
@@ -63,7 +67,11 @@
 
 // The location of OEM manifest file used to trigger OOBE flow for kiosk mode.
 const CommandLine::CharType kOemManifestFilePath[] =
+#if defined(OS_FREEBSD)
+    FILE_PATH_LITERAL("/usr/local/share/oem/oobe/manifest.json");
+#else
     FILE_PATH_LITERAL("/usr/share/oem/oobe/manifest.json");
+#endif
 
 }  // namespace
 
