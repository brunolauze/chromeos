--- skia/skia_library.gypi.orig	2014-05-30 15:02:33.180551199 -0500
+++ skia/skia_library.gypi	2014-05-30 15:04:07.531544662 -0500
@@ -15,6 +15,7 @@
   'dependencies': [
     'skia_library_opts.gyp:skia_opts',
     '../third_party/zlib/zlib.gyp:zlib',
+    '../third_party/skia/gyp/etc1.gyp:libetc1',
   ],
 
   'includes': [
