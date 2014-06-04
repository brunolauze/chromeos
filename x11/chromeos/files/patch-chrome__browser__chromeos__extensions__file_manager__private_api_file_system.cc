--- chrome/browser/chromeos/extensions/file_manager/private_api_file_system.cc.orig	2014-06-03 08:45:34.756214055 -0500
+++ chrome/browser/chromeos/extensions/file_manager/private_api_file_system.cc	2014-06-03 08:45:58.434258671 -0500
@@ -11,6 +11,7 @@
 #include "base/strings/stringprintf.h"
 #include "base/task_runner_util.h"
 #include "base/threading/sequenced_worker_pool.h"
+#include "net/base/escape.h"
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/chromeos/drive/drive.pb.h"
 #include "chrome/browser/chromeos/drive/file_system_interface.h"
