--- chrome/chrome.gyp.orig	2014-06-03 08:51:23.890189499 -0500
+++ chrome/chrome.gyp	2014-06-03 08:52:12.941213750 -0500
@@ -52,7 +52,7 @@
           'service',
         ],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="freebsd"', {
         'conditions': [
           ['chromeos==1', {
             'conditions': [
@@ -70,7 +70,7 @@
           }],
         ],
       },],
-      ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "linux"', {
+      ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "linux" and OS != "freebsd"', {
         'platform_locale_settings_grd':
             'app/resources/locale_settings_linux.grd',
       },],
