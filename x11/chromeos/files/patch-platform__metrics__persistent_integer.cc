--- platform/metrics/persistent_integer.cc.orig	2014-06-09 11:43:27.251033406 -0500
+++ platform/metrics/persistent_integer.cc	2014-06-09 11:44:09.177028278 -0500
@@ -5,7 +5,7 @@
 #include "persistent_integer.h"
 
 #include <fcntl.h>
-
+#include <sys/stat.h>
 #include <base/logging.h>
 #include <base/posix/eintr_wrapper.h>
 
