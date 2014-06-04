--- chrome/browser/chromeos/camera_detector.cc.orig	2014-06-03 08:12:28.803349953 -0500
+++ chrome/browser/chromeos/camera_detector.cc	2014-06-03 08:13:59.503345911 -0500
@@ -12,11 +12,14 @@
 #include "base/strings/string_util.h"
 #include "base/task_runner_util.h"
 #include "base/threading/sequenced_worker_pool.h"
+#if defined(OS_LINUX)
 #include "components/storage_monitor/udev_util_linux.h"
+#endif
 #include "content/public/browser/browser_thread.h"
 
 namespace chromeos {
 
+#if defined(OS_LINUX)
 namespace {
 
 // Sysfs directory containing V4L devices.
@@ -29,6 +32,7 @@
 const char kV4LCaptureCapability[] = "capture";
 
 }  // namespace
+#endif
 
 using content::BrowserThread;
 
@@ -65,6 +69,7 @@
 
 // static
 bool CameraDetector::CheckPresence() {
+#if defined(OS_LINUX)
   // We do a quick check using udev database because opening each /dev/videoX
   // device may trigger costly device initialization.
   base::FileEnumerator file_enum(
@@ -82,6 +87,7 @@
       }
     }
   }
+#endif
   return false;
 }
 
