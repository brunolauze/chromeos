--- chrome/browser/chromeos/login/demo_mode/demo_app_launcher.cc.orig	2014-06-03 09:27:38.104038654 -0500
+++ chrome/browser/chromeos/login/demo_mode/demo_app_launcher.cc	2014-06-03 09:28:29.816035695 -0500
@@ -30,7 +30,11 @@
 const char DemoAppLauncher::kDemoUserName[] = "demouser@demo.app.local";
 const char DemoAppLauncher::kDemoAppId[] = "klimoghijjogocdbaikffefjfcfheiel";
 const base::FilePath::CharType kDefaultDemoAppPath[] =
+#if defined(OS_FREEBSD)
+    FILE_PATH_LITERAL("/usr/local/share/chromeos-assets/demo_app");
+#else
     FILE_PATH_LITERAL("/usr/share/chromeos-assets/demo_app");
+#endif
 
 // static
 base::FilePath* DemoAppLauncher::demo_app_path_ = NULL;
