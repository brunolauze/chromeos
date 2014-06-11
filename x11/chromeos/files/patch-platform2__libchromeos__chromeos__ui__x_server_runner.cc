--- platform2/libchromeos/chromeos/ui/x_server_runner.cc.orig	2014-06-09 09:01:35.175704104 -0500
+++ platform2/libchromeos/chromeos/ui/x_server_runner.cc	2014-06-09 09:13:45.496649670 -0500
@@ -8,7 +8,9 @@
 #include <grp.h>
 #include <signal.h>
 #include <sys/resource.h>
+#if !defined(__FreeBSD__)
 #include <sys/signalfd.h>
+#endif
 #include <sys/wait.h>
 #include <unistd.h>
 
@@ -31,7 +33,7 @@
 namespace {
 
 // Path to the X server binary.
-const char kXServerCommand[] = "/usr/bin/X";
+const char kXServerCommand[] = "/usr/local/bin/X";
 
 // Writes |data| to |file|, returning true on success.
 bool WriteString(base::File* file, const std::string& data) {
@@ -121,6 +123,10 @@
 // via signalfd-created |fd|. Returns true if the server started successfully.
 bool WaitForSignalFromServer(pid_t server_pid, int fd) {
   LOG(INFO) << "X server started with PID " << server_pid;
+#if defined(__FreeBSD__)
+  sleep(3); /* BIG HACK */
+  return true;
+#else
   while (true) {
     struct signalfd_siginfo siginfo;
     int bytes_read = HANDLE_EINTR(read(fd, &siginfo, sizeof(siginfo)));
@@ -160,6 +166,7 @@
     }
   }
   return false;
+#endif
 }
 
 // Drops privileges, forks-and-execs the X server, waits for it to emit SIGUSR1
@@ -182,6 +189,9 @@
   PCHECK(sigemptyset(&mask) == 0);
   PCHECK(sigaddset(&mask, SIGUSR1) == 0);
   PCHECK(sigaddset(&mask, SIGCHLD) == 0);
+#if defined(__FreeBSD__)
+  return true;
+#else
   const int fd = signalfd(-1, &mask, 0);
   PCHECK(fd != -1) << "signalfd() failed";
   PCHECK(sigprocmask(SIG_BLOCK, &mask, NULL) == 0);
@@ -214,6 +224,7 @@
 
   close(fd);
   return success;
+#endif
 }
 
 }  // namespace
