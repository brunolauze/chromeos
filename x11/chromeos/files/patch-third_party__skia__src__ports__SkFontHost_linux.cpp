--- third_party/skia/src/ports/SkFontHost_linux.cpp.orig	2014-06-03 09:07:26.752148263 -0500
+++ third_party/skia/src/ports/SkFontHost_linux.cpp	2014-06-03 09:12:13.778120483 -0500
@@ -22,8 +22,12 @@
 #include <limits>
 
 #ifndef SK_FONT_FILE_PREFIX
+#if defined(__FreeBSD__)
+#    define SK_FONT_FILE_PREFIX "/usr/local/lib/X11/fonts/TTF/"
+#else
 #    define SK_FONT_FILE_PREFIX "/usr/share/fonts/truetype/"
 #endif
+#endif
 
 bool find_name_and_attributes(SkStream* stream, SkString* name,
                               SkTypeface::Style* style, bool* isFixedPitch);
