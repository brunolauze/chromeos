--- chrome/browser/chromeos/mobile_config.cc.orig	2014-06-03 09:04:46.460138736 -0500
+++ chrome/browser/chromeos/mobile_config.cc	2014-06-03 09:06:12.590126996 -0500
@@ -51,11 +51,19 @@
 
 // Location of the global carrier config.
 const char kGlobalCarrierConfigPath[] =
+#if defined(OS_FREEBSD)
+    "/usr/local/share/chromeos-assets/mobile/carrier_config.json";
+#else
     "/usr/share/chromeos-assets/mobile/carrier_config.json";
+#endif
 
 // Location of the local carrier config.
 const char kLocalCarrierConfigPath[] =
+#if defined(OS_FREEBSD)
+    "/usr/local/share/oem/etc/carrier_config.json";
+#else
     "/opt/oem/etc/carrier_config.json";
+#endif
 
 }  // anonymous namespace
 
