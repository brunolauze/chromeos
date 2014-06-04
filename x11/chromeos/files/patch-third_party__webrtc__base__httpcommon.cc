--- third_party/webrtc/base/httpcommon.cc.orig	2014-05-30 10:33:25.646665373 -0500
+++ third_party/webrtc/base/httpcommon.cc	2014-05-30 10:33:50.103663500 -0500
@@ -382,7 +382,7 @@
     gmt = non_gmt + kTimeZoneOffsets[zindex] * 60 * 60;
   }
   // TODO: Android should support timezone, see b/2441195
-#if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS) || defined(WEBRTC_ANDROID) || defined(BSD)
+#if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS) || defined(WEBRTC_ANDROID) || defined(OS_FREEBSD)
   tm *tm_for_timezone = localtime((time_t *)&gmt);
   *seconds = gmt + tm_for_timezone->tm_gmtoff;
 #else
