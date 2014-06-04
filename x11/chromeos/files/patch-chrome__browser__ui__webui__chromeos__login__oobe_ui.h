--- chrome/browser/ui/webui/chromeos/login/oobe_ui.h.orig	2014-06-03 10:40:13.767764747 -0500
+++ chrome/browser/ui/webui/chromeos/login/oobe_ui.h	2014-06-03 10:40:35.724737770 -0500
@@ -109,8 +109,9 @@
       GetAppLaunchSplashScreenActor() OVERRIDE;
   virtual bool IsJSReady(const base::Closure& display_is_ready_callback)
       OVERRIDE;
+#if defined(OS_LINUX)
   virtual HIDDetectionScreenActor* GetHIDDetectionScreenActor() OVERRIDE;
-
+#endif
   // Collects localized strings from the owned handlers.
   void GetLocalizedStrings(base::DictionaryValue* localized_strings);
 
