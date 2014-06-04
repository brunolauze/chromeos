--- third_party/libjingle/source/talk/base/physicalsocketserver.cc.orig	2014-06-03 07:13:56.212591491 -0500
+++ third_party/libjingle/source/talk/base/physicalsocketserver.cc	2014-06-03 07:14:50.699587119 -0500
@@ -455,7 +455,7 @@
     // and let the caller pick a default MTU.
     SetError(EINVAL);
     return -1;
-#elif defined(LINUX) || defined(ANDROID)
+#elif defined(LINUX) || defined(ANDROID) || defined(__FreeBSD__)
     // Gets the path MTU.
     int value;
     socklen_t vlen = sizeof(value);
