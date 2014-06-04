--- chrome/chrome_resources.gyp.orig	2014-06-03 09:38:19.961996203 -0500
+++ chrome/chrome_resources.gyp	2014-06-03 09:38:52.379992908 -0500
@@ -294,7 +294,7 @@
             'platform_locale_settings_grd':
                 'app/resources/locale_settings_win.grd',
           },],
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="freebsd"', {
             'conditions': [
               ['chromeos==1', {
                 'conditions': [
@@ -312,7 +312,7 @@
               }],
             ],
           },],
-          ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "linux"', {
+          ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "linux" and OS != "freebsd"', {
             'platform_locale_settings_grd':
                 'app/resources/locale_settings_linux.grd',
           },],
