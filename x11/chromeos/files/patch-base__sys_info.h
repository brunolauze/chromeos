--- base/sys_info.h.orig	2014-06-05 18:54:38.629464531 -0500
+++ base/sys_info.h	2014-06-05 18:55:08.723531857 -0500
@@ -111,6 +111,9 @@
   // Returns true when actually running in a Chrome OS environment.
   static bool IsRunningOnChromeOS();
 
+  // Returns true when actually running in a Chrome BSD environment.
+  static bool IsRunningOnChromeBSD();
+
   // Test method to force re-parsing of lsb-release.
   static void SetChromeOSVersionInfoForTest(const std::string& lsb_release,
                                             const Time& lsb_release_time);
