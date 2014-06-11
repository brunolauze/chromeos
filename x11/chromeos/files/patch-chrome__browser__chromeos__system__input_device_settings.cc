--- chrome/browser/chromeos/system/input_device_settings.cc.orig	2014-06-05 14:18:27.389634306 -0500
+++ chrome/browser/chromeos/system/input_device_settings.cc	2014-06-05 14:19:16.531601961 -0500
@@ -35,7 +35,11 @@
 
 const char kDeviceTypeTouchpad[] = "touchpad";
 const char kDeviceTypeMouse[] = "mouse";
+#if defined(OS_FREEBSD)
+const char kInputControl[] = "/usr/local/share/chromeos-assets/scripts/input/inputcontrol";
+#else
 const char kInputControl[] = "/opt/google/input/inputcontrol";
+#endif
 
 const char kRemoraRequisition[] = "remora";
 
