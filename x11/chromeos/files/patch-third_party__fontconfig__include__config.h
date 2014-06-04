--- third_party/fontconfig/include/config.h.orig	2014-06-03 09:02:50.894142378 -0500
+++ third_party/fontconfig/include/config.h	2014-06-03 09:03:27.603166797 -0500
@@ -17,7 +17,11 @@
 /* #undef FC_ARCHITECTURE */
 
 /* System font directory */
+#if defined(__FreeBSD__)
+#define FC_DEFAULT_FONTS "/usr/local/share/fonts"
+#else
 #define FC_DEFAULT_FONTS "/usr/share/fonts"
+#endif
 
 /* Define to nothing if C supports flexible array members, and to 1 if it does
    not. That way, with a declaration like `struct s { int n; double
