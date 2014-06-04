--- chrome/browser/chromeos/login/screens/hid_detection_screen.cc.orig	2014-06-03 11:36:42.617506981 -0500
+++ chrome/browser/chromeos/login/screens/hid_detection_screen.cc	2014-06-03 11:37:58.714499464 -0500
@@ -36,7 +36,11 @@
 }
 
 std::string HIDDetectionScreen::GetName() const {
+#if defined(OS_FREEBSD)
+  return std::string("hid-detection");
+#else
   return WizardController::kHIDDetectionScreenName;
+#endif
 }
 
 void HIDDetectionScreen::OnExit() {
