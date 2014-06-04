--- chrome/browser/prefs/browser_prefs.cc.orig	2014-06-03 10:23:58.625805943 -0500
+++ chrome/browser/prefs/browser_prefs.cc	2014-06-03 10:24:44.729803619 -0500
@@ -164,7 +164,9 @@
 #include "chrome/browser/extensions/extension_assets_manager_chromeos.h"
 #include "chrome/browser/metrics/chromeos_metrics_provider.h"
 #include "chrome/browser/ui/webui/chromeos/charger_replacement_handler.h"
+#if defined(OS_LINUX)
 #include "chrome/browser/ui/webui/chromeos/login/hid_detection_screen_handler.h"
+#endif
 #include "chrome/browser/ui/webui/chromeos/login/network_screen_handler.h"
 #include "chrome/browser/ui/webui/chromeos/login/signin_screen_handler.h"
 #else
@@ -294,7 +296,9 @@
   chromeos::KioskAppManager::RegisterPrefs(registry);
   chromeos::LoginUtils::RegisterPrefs(registry);
   chromeos::MultiProfileUserController::RegisterPrefs(registry);
+#if defined(OS_LINUX)
   chromeos::HIDDetectionScreenHandler::RegisterPrefs(registry);
+#endif
   chromeos::NetworkScreenHandler::RegisterPrefs(registry);
   chromeos::Preferences::RegisterPrefs(registry);
   chromeos::proxy_config::RegisterPrefs(registry);
