--- base/sys_info_chromeos.cc.orig	2014-06-05 18:27:35.120577215 -0500
+++ base/sys_info_chromeos.cc	2014-06-05 18:29:22.991569282 -0500
@@ -207,6 +207,15 @@
 }
 
 // static
+bool SysInfo::IsRunningOnChromeBSD() {
+#if defined(OS_FREEBSD)
+   return true;
+#else
+   return false;
+#endif
+}
+
+// static
 void SysInfo::SetChromeOSVersionInfoForTest(const std::string& lsb_release,
                                             const Time& lsb_release_time) {
   scoped_ptr<Environment> env(Environment::Create());
