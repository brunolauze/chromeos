--- third_party/pdfium/core/src/fxge/ge/fx_ge_linux.cpp.orig	2014-06-03 08:56:34.153169044 -0500
+++ third_party/pdfium/core/src/fxge/ge/fx_ge_linux.cpp	2014-06-03 08:58:33.262158629 -0500
@@ -238,9 +238,15 @@
         return NULL;
     }
     if (!pInfo->ParseFontCfg()) {
+#if defined(__FreeBSD__)
+        pInfo->AddPath("/usr/local/lib/X11/fonts/Droid");
+        pInfo->AddPath("/usr/local/lib/X11/fonts/Type1");
+        pInfo->AddPath("/usr/local/lib/X11/fonts/TTF");
+#else
         pInfo->AddPath("/usr/share/fonts");
         pInfo->AddPath("/usr/share/X11/fonts/Type1");
         pInfo->AddPath("/usr/share/X11/fonts/TTF");
+#endif
         pInfo->AddPath("/usr/local/share/fonts");
     }
     return pInfo;
