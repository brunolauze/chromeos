--- base/posix/unix_domain_socket_linux.cc.orig	2014-05-30 11:24:10.148454371 -0500
+++ base/posix/unix_domain_socket_linux.cc	2014-05-30 11:32:09.831450690 -0500
@@ -9,6 +9,15 @@
 #include <sys/uio.h>
 #include <unistd.h>
 
+#if defined(OS_FREEBSD)
+#define SCM_CREDENTIALS 0x02            /* rw: struct ucred             */
+struct ucred {
+        pid_t   pid;
+        uid_t   uid;
+        uid_t   gid;
+};
+#endif
+
 #include <vector>
 
 #include "base/files/scoped_file.h"
@@ -34,8 +43,12 @@
 
 // static
 bool UnixDomainSocket::EnableReceiveProcessId(int fd) {
+#ifdef SO_PASSCRED
   const int enable = 1;
   return setsockopt(fd, SOL_SOCKET, SO_PASSCRED, &enable, sizeof(enable)) == 0;
+#else
+  return true;
+#endif
 }
 
 // static
