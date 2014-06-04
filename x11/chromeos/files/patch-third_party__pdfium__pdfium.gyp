--- third_party/pdfium/pdfium.gyp.orig	2014-05-30 09:45:59.403861802 -0500
+++ third_party/pdfium/pdfium.gyp	2014-05-30 09:46:28.480857394 -0500
@@ -14,7 +14,7 @@
       ['pdf_use_skia==1', {
         'defines': ['_SKIA_SUPPORT_'],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="freebsd"', {
         'cflags!': [
           '-fno-exceptions',
         ],
