--- chrome/browser/chromeos/mobile/mobile_activator.cc.orig	2014-06-03 09:23:43.559055903 -0500
+++ chrome/browser/chromeos/mobile/mobile_activator.cc	2014-06-03 09:24:24.687061579 -0500
@@ -44,7 +44,11 @@
 
 // Cellular configuration file path.
 const char kCellularConfigPath[] =
+#if defined(OS_FREEBSD)
+    "/usr/local/share/chromeos-assets/mobile/mobile_config.json";
+#else
     "/usr/share/chromeos-assets/mobile/mobile_config.json";
+#endif
 
 // Cellular config file field names.
 const char kVersionField[] = "version";
