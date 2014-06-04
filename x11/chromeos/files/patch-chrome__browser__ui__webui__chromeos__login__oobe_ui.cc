--- chrome/browser/ui/webui/chromeos/login/oobe_ui.cc.orig	2014-06-03 10:00:57.232902551 -0500
+++ chrome/browser/ui/webui/chromeos/login/oobe_ui.cc	2014-06-03 10:03:12.966891314 -0500
@@ -28,7 +28,9 @@
 #include "chrome/browser/ui/webui/chromeos/login/error_screen_handler.h"
 #include "chrome/browser/ui/webui/chromeos/login/eula_screen_handler.h"
 #include "chrome/browser/ui/webui/chromeos/login/gaia_screen_handler.h"
+#if defined(OS_LINUX)
 #include "chrome/browser/ui/webui/chromeos/login/hid_detection_screen_handler.h"
+#endif
 #include "chrome/browser/ui/webui/chromeos/login/kiosk_app_menu_handler.h"
 #include "chrome/browser/ui/webui/chromeos/login/kiosk_autolaunch_screen_handler.h"
 #include "chrome/browser/ui/webui/chromeos/login/kiosk_enable_screen_handler.h"
@@ -133,7 +135,9 @@
 const char OobeUI::kAppLaunchSplashDisplay[] = "app-launch-splash";
 
 // static
+#if defined(OS_LINUX)
 const char OobeUI::kScreenOobeHIDDetection[] = "hid-detection";
+#endif
 const char OobeUI::kScreenOobeNetwork[]      = "connect";
 const char OobeUI::kScreenOobeEula[]         = "eula";
 const char OobeUI::kScreenOobeUpdate[]       = "update";
@@ -153,7 +157,9 @@
 const char OobeUI::kScreenWrongHWID[]        = "wrong-hwid";
 const char OobeUI::kScreenAutoEnrollmentCheck[]
                                              = "auto-enrollment-check";
+#if defined(OS_LINUX)
 const char OobeUI::kScreenHIDDetection[]     = "hid-detection";
+#endif
 const char OobeUI::kScreenAppLaunchSplash[]  = "app-launch-splash";
 const char OobeUI::kScreenConfirmPassword[]  = "confirm-password";
 const char OobeUI::kScreenFatalError[]       = "fatal-error";
@@ -165,7 +171,9 @@
       update_screen_handler_(NULL),
       network_screen_actor_(NULL),
       eula_screen_actor_(NULL),
+#if defined(OS_LINUX)
       hid_detection_screen_actor_(NULL),
+#endif
       reset_screen_actor_(NULL),
       autolaunch_screen_actor_(NULL),
       kiosk_enable_screen_actor_(NULL),
@@ -239,10 +247,12 @@
   auto_enrollment_check_screen_actor_ = auto_enrollment_check_screen_handler;
   AddScreenHandler(auto_enrollment_check_screen_handler);
 
+#if defined(OS_LINUX)
   HIDDetectionScreenHandler* hid_detection_screen_handler =
       new HIDDetectionScreenHandler();
   hid_detection_screen_actor_ = hid_detection_screen_handler;
   AddScreenHandler(hid_detection_screen_handler);
+#endif
 
   EnrollmentScreenHandler* enrollment_screen_handler =
       new EnrollmentScreenHandler();
@@ -362,9 +372,11 @@
   return auto_enrollment_check_screen_actor_;
 }
 
+#if defined(OS_LINUX)
 HIDDetectionScreenActor* OobeUI::GetHIDDetectionScreenActor() {
   return hid_detection_screen_actor_;
 }
+#endif
 
 UserImageScreenActor* OobeUI::GetUserImageScreenActor() {
   return user_image_screen_actor_;
@@ -417,7 +429,9 @@
 
 void OobeUI::InitializeScreenMaps() {
   screen_names_.resize(SCREEN_UNKNOWN);
+#if defined(OS_LINUX)
   screen_names_[SCREEN_OOBE_HID_DETECTION] = kScreenOobeHIDDetection;
+#endif
   screen_names_[SCREEN_OOBE_NETWORK] = kScreenOobeNetwork;
   screen_names_[SCREEN_OOBE_EULA] = kScreenOobeEula;
   screen_names_[SCREEN_OOBE_UPDATE] = kScreenOobeUpdate;
