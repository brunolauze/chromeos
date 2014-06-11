--- tools/gn/settings.h.orig	2014-06-11 09:03:04.376701748 -0500
+++ tools/gn/settings.h	2014-06-11 09:03:24.219728373 -0500
@@ -29,6 +29,7 @@
   enum TargetOS {
     UNKNOWN,
     LINUX,
+    FREEBSD,
     MAC,
     WIN
   };
