--- chrome/browser/chromeos/login/wizard_controller.h.orig	2014-06-03 10:49:05.756730399 -0500
+++ chrome/browser/chromeos/login/wizard_controller.h	2014-06-03 10:50:15.713699882 -0500
@@ -34,7 +34,9 @@
 class EnrollmentScreen;
 class ErrorScreen;
 class EulaScreen;
+#if defined(OS_LINUX)
 class HIDDetectionScreen;
+#endif
 struct Geoposition;
 class KioskAutolaunchScreen;
 class KioskEnableScreen;
@@ -128,7 +130,9 @@
   TermsOfServiceScreen* GetTermsOfServiceScreen();
   WrongHWIDScreen* GetWrongHWIDScreen();
   AutoEnrollmentCheckScreen* GetAutoEnrollmentCheckScreen();
+#if defined(OS_LINUX)
   HIDDetectionScreen* GetHIDDetectionScreen();
+#endif
   LocallyManagedUserCreationScreen* GetLocallyManagedUserCreationScreen();
 
   // Returns a pointer to the current screen or NULL if there's no such
@@ -155,8 +159,9 @@
   static const char kWrongHWIDScreenName[];
   static const char kLocallyManagedUserCreationScreenName[];
   static const char kAppLaunchSplashScreenName[];
+#if defined(OS_LINUX)
   static const char kHIDDetectionScreenName [];
-
+#endif
   // Volume percent at which spoken feedback is still audible.
   static const int kMinAudibleOutputVolumePercent;
 
@@ -174,8 +179,9 @@
   void ShowWrongHWIDScreen();
   void ShowAutoEnrollmentCheckScreen();
   void ShowLocallyManagedUserCreationScreen();
+#if defined(OS_LINUX)
   void ShowHIDDetectionScreen();
-
+#endif
   // Shows images login screen.
   void ShowLoginScreen(const LoginScreenContext& context);
 
@@ -183,7 +189,9 @@
   void ResumeLoginScreen();
 
   // Exit handlers:
+#if defined(OS_LINUX)
   void OnHIDDetectionCompleted();
+#endif
   void OnNetworkConnected();
   void OnNetworkOffline();
   void OnConnectionFailed();
@@ -309,8 +317,9 @@
   scoped_ptr<AutoEnrollmentCheckScreen> auto_enrollment_check_screen_;
   scoped_ptr<LocallyManagedUserCreationScreen>
       locally_managed_user_creation_screen_;
+#if defined(OS_LINUX)
   scoped_ptr<HIDDetectionScreen> hid_detection_screen_;
-
+#endif
   // Screen that's currently active.
   WizardScreen* current_screen_;
 
