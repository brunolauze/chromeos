--- third_party/khronos/khronos.gyp.orig	2014-06-04 10:37:54.487923994 -0500
+++ third_party/khronos/khronos.gyp	2014-06-04 10:42:24.475899052 -0500
@@ -11,6 +11,7 @@
         'include_dirs': [
           '.',
           '../../gpu',  # Contains GLES2/gl2chromium.h
+	  '/usr/local/include',
         ],
       },
     },
