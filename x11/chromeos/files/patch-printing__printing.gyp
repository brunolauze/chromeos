--- printing/printing.gyp.orig	2014-05-30 12:55:03.466077671 -0500
+++ printing/printing.gyp	2014-05-30 14:25:23.881705421 -0500
@@ -193,7 +193,7 @@
             'backend/print_backend_chromeos.cc',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" or OS=="freebsd") and chromeos==0', { #XXX (rene) temp!
           'sources': [
             'printing_context_linux.cc',
             'printing_context_linux.h',
