--- chrome/browser/chromeos/login/wizard_controller.cc.orig	2014-06-03 15:15:50.236598632 -0500
+++ chrome/browser/chromeos/login/wizard_controller.cc	2014-06-03 17:48:18.577970113 -0500
@@ -35,7 +35,9 @@
 #include "chrome/browser/chromeos/login/managed/locally_managed_user_creation_screen.h"
 #include "chrome/browser/chromeos/login/screens/error_screen.h"
 #include "chrome/browser/chromeos/login/screens/eula_screen.h"
+#if defined(OS_LINUX)
 #include "chrome/browser/chromeos/login/screens/hid_detection_screen.h"
+#endif
 #include "chrome/browser/chromeos/login/screens/kiosk_autolaunch_screen.h"
 #include "chrome/browser/chromeos/login/screens/kiosk_enable_screen.h"
 #include "chrome/browser/chromeos/login/screens/network_screen.h"
@@ -97,10 +99,12 @@
 };
 
 // Checks flag for HID-detection screen show.
+#if defined(OS_LINUX)
 bool CanShowHIDDetectionScreen() {
   return CommandLine::ForCurrentProcess()->HasSwitch(
       chromeos::switches::kEnableHIDDetectionOnOOBE);
 }
+#endif
 
 bool IsResumableScreen(const std::string& screen) {
   for (size_t i = 0; i < ARRAYSIZE_UNSAFE(kResumableScreens); ++i) {
@@ -132,7 +136,9 @@
   "locally-managed-user-creation-flow";
 const char WizardController::kAppLaunchSplashScreenName[] =
   "app-launch-splash";
+#if defined(OS_LINUX)
 const char WizardController::kHIDDetectionScreenName[] = "hid-detection";
+#endif
 
 // static
 const int WizardController::kMinAudibleOutputVolumePercent = 10;
@@ -349,6 +355,7 @@
   return locally_managed_user_creation_screen_.get();
 }
 
+#if defined(OS_LINUX)
 chromeos::HIDDetectionScreen* WizardController::GetHIDDetectionScreen() {
   if (!hid_detection_screen_.get()) {
     hid_detection_screen_.reset(
@@ -357,6 +364,7 @@
   }
   return hid_detection_screen_.get();
 }
+#endif
 
 void WizardController::ShowNetworkScreen() {
   VLOG(1) << "Showing network screen.";
@@ -510,11 +518,13 @@
   SetCurrentScreen(screen);
 }
 
+#if defined(OS_LINUX)
 void WizardController::ShowHIDDetectionScreen() {
   VLOG(1) << "Showing HID discovery screen.";
   SetStatusAreaVisible(true);
   SetCurrentScreen(GetHIDDetectionScreen());
 }
+#endif
 
 void WizardController::SkipToLoginForTesting(
     const LoginScreenContext& context) {
@@ -538,9 +548,11 @@
 
 ///////////////////////////////////////////////////////////////////////////////
 // WizardController, ExitHandlers:
+#if defined(OS_LINUX)
 void WizardController::OnHIDDetectionCompleted() {
   ShowNetworkScreen();
 }
+#endif
 
 void WizardController::OnNetworkConnected() {
   if (is_official_build_) {
@@ -740,10 +752,12 @@
 
 void WizardController::PerformOOBECompletedActions() {
   StartupUtils::MarkOobeCompleted();
+#if defined(OS_LINUX)
   UMA_HISTOGRAM_COUNTS_100(
       "HIDDetection.TimesDialogShownPerOOBECompleted",
       GetLocalState()->GetInteger(prefs::kTimesHIDDialogShown));
   GetLocalState()->ClearPref(prefs::kTimesHIDDialogShown);
+#endif
 }
 
 void WizardController::SetCurrentScreen(WizardScreen* new_current) {
@@ -827,13 +841,19 @@
     ShowLocallyManagedUserCreationScreen();
   } else if (screen_name == kAppLaunchSplashScreenName) {
     AutoLaunchKioskApp();
-  } else if (screen_name == kHIDDetectionScreenName) {
+  }
+#if defined(OS_LINUX)
+  else if (screen_name == kHIDDetectionScreenName) {
     ShowHIDDetectionScreen();
-  } else if (screen_name != kTestNoScreenName) {
+  } 
+#endif
+  else if (screen_name != kTestNoScreenName) {
     if (is_out_of_box_) {
+#if defined(OS_LINUX)
       if (CanShowHIDDetectionScreen())
         ShowHIDDetectionScreen();
       else
+#endif
         ShowNetworkScreen();
     } else {
       ShowLoginScreen(LoginScreenContext());
@@ -846,9 +866,11 @@
 void WizardController::OnExit(ExitCodes exit_code) {
   VLOG(1) << "Wizard screen exit code: " << exit_code;
   switch (exit_code) {
+#if defined(OS_LINUX)
     case HID_DETECTION_COMPLETED:
       OnHIDDetectionCompleted();
       break;
+#endif
     case NETWORK_CONNECTED:
       OnNetworkConnected();
       break;
