--- chrome/browser/ui/webui/chromeos/login/hid_detection_screen_handler.h.orig	2014-06-03 08:19:51.311345341 -0500
+++ chrome/browser/ui/webui/chromeos/login/hid_detection_screen_handler.h	2014-06-03 10:00:17.128936348 -0500
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#if defined(OS_LINUX)
+
 #ifndef CHROME_BROWSER_UI_WEBUI_CHROMEOS_LOGIN_HID_DETECTION_SCREEN_HANDLER_H_
 #define CHROME_BROWSER_UI_WEBUI_CHROMEOS_LOGIN_HID_DETECTION_SCREEN_HANDLER_H_
 
@@ -219,3 +221,4 @@
 
 #endif  // CHROME_BROWSER_UI_WEBUI_CHROMEOS_LOGIN_HID_DETECTION_SCREEN_HANDLER_H_
 
+#endif
