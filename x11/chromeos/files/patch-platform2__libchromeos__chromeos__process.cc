--- platform2/libchromeos/chromeos/process.cc.orig	2014-06-09 09:37:10.361554821 -0500
+++ platform2/libchromeos/chromeos/process.cc	2014-06-09 09:39:51.459543081 -0500
@@ -7,6 +7,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <signal.h>
 #include <fcntl.h>
 #include <unistd.h>
 
