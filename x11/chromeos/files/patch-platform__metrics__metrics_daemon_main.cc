--- platform/metrics/metrics_daemon_main.cc.orig	2014-06-09 11:41:20.480039812 -0500
+++ platform/metrics/metrics_daemon_main.cc	2014-06-09 12:28:20.526851942 -0500
@@ -7,7 +7,9 @@
 #include <base/logging.h>
 #include <base/strings/string_util.h>
 #include <chromeos/syslog_logging.h>
+#if !defined(__FreeBSD__)
 #include <gflags/gflags.h>
+#endif
 #include <rootdev/rootdev.h>
 
 #include "metrics_daemon.h"
@@ -17,8 +19,11 @@
 const char kCpuinfoMaxFreqPath[] =
     "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq";
 
+#if defined(__FreeBSD__)
+#define FLAGS_daemon true /* run as daemon (use -nodaemon for debugging) */
+#else
 DEFINE_bool(daemon, true, "run as daemon (use -nodaemon for debugging)");
-
+#endif
 // Returns the path to the disk stats in the sysfs.  Returns the null string if
 // it cannot find the disk stats file.
 static
@@ -46,8 +51,9 @@
 
 int main(int argc, char** argv) {
   CommandLine::Init(argc, argv);
+#if !defined(__FreeBSD__)
   google::ParseCommandLineFlags(&argc, &argv, true);
-
+#endif
   // Also log to stderr when not running as daemon.
   chromeos::InitLog(chromeos::kLogToSyslog | chromeos::kLogHeader |
                     (FLAGS_daemon ? 0 : chromeos::kLogToStderr));
