--- chrome/browser/chromeos/login/ui/oobe_display.h.orig	2014-06-03 10:39:14.965744228 -0500
+++ chrome/browser/chromeos/login/ui/oobe_display.h	2014-06-03 10:39:31.425745435 -0500
@@ -86,7 +86,9 @@
   virtual WrongHWIDScreenActor* GetWrongHWIDScreenActor() = 0;
   virtual AutoEnrollmentCheckScreenActor*
       GetAutoEnrollmentCheckScreenActor() = 0;
+#if defined(OS_LINUX)
   virtual HIDDetectionScreenActor* GetHIDDetectionScreenActor() = 0;
+#endif
   virtual LocallyManagedUserCreationScreenHandler*
       GetLocallyManagedUserCreationScreenActor() = 0;
   virtual AppLaunchSplashScreenActor* GetAppLaunchSplashScreenActor() = 0;
