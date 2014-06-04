--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2014-06-03 09:41:59.084979124 -0500
+++ chrome/browser/ui/startup/startup_browser_creator.cc	2014-06-03 09:43:18.663986993 -0500
@@ -81,7 +81,7 @@
 #include "chromeos/chromeos_switches.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && defined(USE_X11)
 #include "ui/events/x/touch_factory_x11.h"
 #endif
 
