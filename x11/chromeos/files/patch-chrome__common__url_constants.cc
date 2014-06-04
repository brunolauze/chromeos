--- chrome/common/url_constants.cc.orig	2014-06-03 08:48:00.444203321 -0500
+++ chrome/common/url_constants.cc	2014-06-03 08:48:45.848218083 -0500
@@ -294,7 +294,11 @@
 const char kChromeUINetworkMenu[] = "network-menu";
 const char kChromeUIWrenchMenu[] = "wrench-menu";
 
+#if defined(OS_FREEBSD)
+const char kEULAPathFormat[] = "/usr/local/share/chromeos-assets/eula/%s/eula.html";
+#else
 const char kEULAPathFormat[] = "/usr/share/chromeos-assets/eula/%s/eula.html";
+#endif
 const char kOemEulaURLPath[] = "oem";
 const char kOnlineEulaURLPath[] =
     "https://www.google.com/intl/%s/chrome/eula_text.html";
