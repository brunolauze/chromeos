--- third_party/WebKit/Source/platform/fonts/skia/SimpleFontDataSkia.cpp.orig	2014-06-03 07:17:40.456577054 -0500
+++ third_party/WebKit/Source/platform/fonts/skia/SimpleFontDataSkia.cpp	2014-06-03 07:18:11.534575453 -0500
@@ -68,7 +68,7 @@
     int vdmxAscent = 0, vdmxDescent = 0;
     bool isVDMXValid = false;
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || defined(__FreeBSD__)
     // Manually digging up VDMX metrics is only applicable when bytecode hinting using FreeType.
     // With GDI, the metrics will already have taken this into account (as needed).
     // With DirectWrite or CoreText, no bytecode hinting is ever done.
