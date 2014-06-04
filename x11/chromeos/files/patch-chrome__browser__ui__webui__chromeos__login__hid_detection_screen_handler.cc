--- chrome/browser/ui/webui/chromeos/login/hid_detection_screen_handler.cc.orig	2014-06-03 08:22:44.197308699 -0500
+++ chrome/browser/ui/webui/chromeos/login/hid_detection_screen_handler.cc	2014-06-03 09:59:58.234905368 -0500
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#if defined(OS_LINUX)
+
 #include "chrome/browser/ui/webui/chromeos/login/hid_detection_screen_handler.h"
 
 #include "base/bind.h"
@@ -553,3 +555,5 @@
 }
 
 }  // namespace chromeos
+
+#endif
