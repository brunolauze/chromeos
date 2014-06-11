--- chrome/browser/extensions/api/terminal/terminal_private_api.cc.orig	2014-06-06 08:34:32.822072982 -0500
+++ chrome/browser/extensions/api/terminal/terminal_private_api.cc	2014-06-06 09:03:42.088953799 -0500
@@ -26,12 +26,16 @@
 namespace {
 
 const char kCroshName[] = "crosh";
+#if defined(OS_FREEBSD)
+const char kCroshCommand[] = "/usr/local/bin/crosh";
+#else
 const char kCroshCommand[] = "/usr/bin/crosh";
+#endif
 // We make stubbed crosh just echo back input.
 const char kStubbedCroshCommand[] = "cat";
 
 const char* GetCroshPath() {
-  if (base::SysInfo::IsRunningOnChromeOS())
+  if (base::SysInfo::IsRunningOnChromeOS() || base::SysInfo::IsRunningOnChromeBSD())
     return kCroshCommand;
   else
     return kStubbedCroshCommand;
