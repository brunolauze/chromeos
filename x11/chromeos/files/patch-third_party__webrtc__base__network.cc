--- third_party/webrtc/base/network.cc.orig	2014-05-30 11:01:31.623547971 -0500
+++ third_party/webrtc/base/network.cc	2014-05-30 11:17:08.447509358 -0500
@@ -18,11 +18,12 @@
 // linux/if.h can't be included at the same time as the posix sys/if.h, and
 // it's transitively required by linux/route.h, so include that version on
 // linux instead of the standard posix one.
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 #include <linux/if.h>
 #include <linux/route.h>
 #elif !defined(__native_client__)
 #include <net/if.h>
+#include <net/route.h>
 #endif
 #include <sys/socket.h>
 #include <sys/utsname.h>
