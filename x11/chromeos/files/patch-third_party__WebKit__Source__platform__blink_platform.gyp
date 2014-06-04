--- third_party/WebKit/Source/platform/blink_platform.gyp.orig	2014-05-30 15:06:31.846532962 -0500
+++ third_party/WebKit/Source/platform/blink_platform.gyp	2014-06-03 11:10:10.051645033 -0500
@@ -246,7 +246,7 @@
     # compiler optimizations, see crbug.com/237063
     'msvs_disabled_warnings': [ 4267, 4334, 4724 ],
     'conditions': [
-      ['OS=="linux" or OS=="android" or OS=="win"', {
+      ['OS=="linux" or OS=="android" or OS=="freebsd" or OS=="win"', {
         'sources/': [
           # Cherry-pick files excluded by the broader regular expressions above.
           ['include', 'fonts/harfbuzz/FontHarfBuzz\\.cpp$'],
@@ -266,7 +266,7 @@
           ['exclude', 'Harfbuzz[^/]+\\.(cpp|h)$'],
         ],
       }],
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="freebsd" or OS=="android"', {
         'sources/': [
           ['include', 'fonts/linux/FontPlatformDataLinuxHarfBuzz\\.cpp$'],
         ]
@@ -363,7 +363,7 @@
           ['exclude', 'fonts/harfbuzz/HarfBuzzFaceCoreText\\.cpp$'],
         ],
       }],
-      ['OS != "linux" and OS != "mac" and OS != "win"', {
+      ['OS != "linux" and OS != "freebsd" and OS != "mac" and OS != "win"', {
         'sources/': [
           ['exclude', 'VDMX[^/]+\\.(cpp|h)$'],
         ],
@@ -409,7 +409,7 @@
           ['exclude', 'Android\\.cpp$'],
         ],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="freebsd"', {
         'dependencies': [
           '<(DEPTH)/build/linux/system.gyp:fontconfig',
         ],
