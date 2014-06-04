--- third_party/pdfium/fpdfsdk/src/jsapi/fxjs_v8.cpp.orig	2014-05-30 12:37:07.755153922 -0500
+++ third_party/pdfium/fpdfsdk/src/jsapi/fxjs_v8.cpp	2014-05-30 12:38:40.844154897 -0500
@@ -758,7 +758,7 @@
 	time_t t = 0;
 	time(&t);
 	localtime(&t);
-	return (double)(-(timezone * 1000));
+	return (double)(-(t * 1000));
 }
 
 int _getDaylightSavingTA(double d)
