--- chrome/browser/chromeos/power/cpu_data_collector.cc.orig	2014-06-05 16:54:15.615963462 -0500
+++ chrome/browser/chromeos/power/cpu_data_collector.cc	2014-06-05 17:05:20.806918637 -0500
@@ -27,16 +27,23 @@
 
 // The value in the file /sys/devices/system/cpu/cpu<n>/online which indicates
 // that CPU-n is online.
+#if defined(OS_FREEBSD)
+const int kCpuOnlineStatus = 8;
+#else
 const int kCpuOnlineStatus = 1;
+#endif
 
+#if !defined(OS_FREEBSD)
 // The base of the path to the files and directories which contain CPU data in
 // the sysfs.
 const char kCpuDataPathBase[] = "/sys/devices/system/cpu";
+#endif
 
 // Suffix of the path to the file listing the range of possible CPUs on the
 // system.
 const char kPossibleCpuPathSuffix[] = "/possible";
 
+#if defined(OS_FREEBSD)
 // Format of the suffix of the path to the file which contains information
 // about a particular CPU being online or offline.
 const char kCpuOnlinePathSuffixFormat[] = "/cpu%d/online";
@@ -57,6 +64,7 @@
 // Format of the suffix of the path which contains information about time spent
 // in an idle state on a CPU.
 const char kCpuIdleStateTimePathSuffixFormat[] = "/cpu%d/cpuidle/state%d/time";
+#endif
 
 // Returns the index at which |str| is in |vector|. If |str| is not present in
 // |vector|, then it is added to it before its index is returned.
@@ -74,6 +82,9 @@
 
 // Returns true if the |i|-th CPU is online; false otherwise.
 bool CpuIsOnline(const int i) {
+#if defined(OS_FREEBSD)
+  return true;
+#else
   const std::string online_file_format = base::StringPrintf(
       "%s%s", kCpuDataPathBase, kCpuOnlinePathSuffixFormat);
   const std::string cpu_online_file = base::StringPrintf(
@@ -96,6 +107,7 @@
   LOG(ERROR) << "Bad format or error reading " << cpu_online_file << ". "
              << "Assuming offline.";
   return false;
+#endif
 }
 
 // Samples the CPU idle state information from sysfs. |cpu_count| is the number
@@ -105,6 +117,7 @@
     int cpu_count,
     std::vector<std::string>* cpu_idle_state_names,
     std::vector<CpuDataCollector::StateOccupancySample>* idle_samples) {
+#if !defined(OS_FREEBSD)
   base::Time start_time = base::Time::Now();
   for (int cpu = 0; cpu < cpu_count; ++cpu) {
     CpuDataCollector::StateOccupancySample idle_sample;
@@ -184,6 +197,7 @@
     LOG(WARNING) << "Dropped an idle state sample due to excessive time delay: "
                  << delay << "milliseconds.";
   }
+#endif
 }
 
 // Samples the CPU freq state information from sysfs. |cpu_count| is the number
@@ -193,6 +207,7 @@
     int cpu_count,
     std::vector<std::string>* cpu_freq_state_names,
     std::vector<CpuDataCollector::StateOccupancySample>* freq_samples) {
+#if !defined(OS_FREEBSD)
   base::Time start_time = base::Time::Now();
   for (int cpu = 0; cpu < cpu_count; ++cpu) {
     CpuDataCollector::StateOccupancySample freq_sample;
@@ -278,6 +293,7 @@
     LOG(WARNING) << "Dropped a freq state sample due to excessive time delay: "
                  << delay << "milliseconds.";
   }
+#endif
 }
 
 // Samples CPU idle and CPU freq data from sysfs. This function should run on
@@ -297,7 +313,8 @@
     // Set |cpu_count_| to 1. If it is something else, it will get corrected
     // later. A system will at least have one CPU. Hence, a value of 1 here
     // will serve as a default value in case of errors.
-    *cpu_count = 1;
+    *cpu_count = kCpuOnlineStatus;
+#if !defined(OS_FREEBSD)
     const std::string possible_cpu_path = base::StringPrintf(
         "%s%s", kCpuDataPathBase, kPossibleCpuPathSuffix);
     if (!base::PathExists(base::FilePath(possible_cpu_path))) {
@@ -324,6 +341,7 @@
                    << "Defaulting CPU count to 1.";
       }
     }
+#endif
   }
 
   // Initialize the deques in the data vectors.
