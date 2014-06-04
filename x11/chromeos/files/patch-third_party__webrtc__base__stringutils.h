--- third_party/webrtc/base/stringutils.h.orig	2014-05-30 11:05:22.530546280 -0500
+++ third_party/webrtc/base/stringutils.h	2014-05-30 11:21:26.029466695 -0500
@@ -23,11 +23,11 @@
 #endif  // WEBRTC_WIN 
 
 #if defined(WEBRTC_POSIX)
-#ifdef BSD
+#ifdef WEBRTC_BSD
 #include <stdlib.h>
 #else  // BSD
 #include <alloca.h>
-#endif  // !BSD
+#endif  // !WEBRTC_BSD
 #endif  // WEBRTC_POSIX
 
 #include <string>
