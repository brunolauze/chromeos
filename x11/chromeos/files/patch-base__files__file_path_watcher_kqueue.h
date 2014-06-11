--- base/files/file_path_watcher_kqueue.h.orig	2014-06-11 08:46:46.167769705 -0500
+++ base/files/file_path_watcher_kqueue.h	2014-06-11 09:52:37.645513250 -0500
@@ -5,6 +5,10 @@
 #ifndef BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 #define BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 
+#include <stdlib.h>
+#include <stdint.h>
+#include <fcntl.h>
+#include <unistd.h>
 #include <sys/event.h>
 #include <vector>
 
