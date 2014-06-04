--- chromeos/chromeos_paths.cc.orig	2014-06-03 08:53:22.329180241 -0500
+++ chromeos/chromeos_paths.cc	2014-06-03 08:54:30.629176618 -0500
@@ -14,11 +14,19 @@
 namespace {
 
 const base::FilePath::CharType kDefaultAppOrderFileName[] =
+#if defined(OS_FREEBSD)
+#if defined(GOOGLE_CHROME_BUILD)
+    FILE_PATH_LITERAL("/usr/local/share/google-chrome/default_app_order.json");
+#else
+    FILE_PATH_LITERAL("/usr/local/share/chromium/default_app_order.json");
+#endif  // defined(GOOGLE_CHROME_BUILD)
+#else
 #if defined(GOOGLE_CHROME_BUILD)
     FILE_PATH_LITERAL("/usr/share/google-chrome/default_app_order.json");
 #else
     FILE_PATH_LITERAL("/usr/share/chromium/default_app_order.json");
 #endif  // defined(GOOGLE_CHROME_BUILD)
+#endif
 
 const base::FilePath::CharType kDefaultUserPolicyKeysDir[] =
     FILE_PATH_LITERAL("/var/run/user_policy");
