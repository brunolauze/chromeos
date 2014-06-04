--- chrome/browser/chromeos/memory/oom_priority_manager.cc.orig	2014-06-03 08:35:21.255260271 -0500
+++ chrome/browser/chromeos/memory/oom_priority_manager.cc	2014-06-03 10:54:39.182678779 -0500
@@ -134,11 +134,13 @@
   // These logs are collected by user feedback reports.  We want them to help
   // diagnose user-reported problems with frequently discarded tabs.
   std::string log_string = ToLogString();
+#if defined(OS_LINUX)
   base::SystemMemoryInfoKB memory;
   if (base::GetSystemMemoryInfo(&memory) && memory.gem_size != -1) {
     log_string += "Graphics ";
     log_string += base::UTF16ToASCII(ui::FormatBytes(memory.gem_size));
   }
+#endif
   LOG(WARNING) << "OOM details (" << delta.InMilliseconds() << " ms):\n"
       << log_string;
   if (g_browser_process &&
@@ -349,6 +351,7 @@
     UMA_HISTOGRAM_CUSTOM_COUNTS(
         "Tabs.Discard.IntervalTime2", interval_ms, 100, 100000 * 1000, 50);
   }
+#if defined(OS_LINUX)
   // Record Chrome's concept of system memory usage at the time of the discard.
   base::SystemMemoryInfoKB memory;
   if (base::GetSystemMemoryInfo(&memory)) {
@@ -382,6 +385,7 @@
         (memory.active_file + memory.inactive_file + memory.free) / 1024;
     HISTOGRAM_MEGABYTES("Tabs.Discard.MemAvailableMB", mem_available_mb);
   }
+#endif
   // Set up to record the next interval.
   last_discard_time_ = TimeTicks::Now();
 }
@@ -456,8 +460,10 @@
 void OomPriorityManager::AdjustFocusedTabScoreOnFileThread() {
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::FILE));
   base::AutoLock pid_to_oom_score_autolock(pid_to_oom_score_lock_);
+#if defined(OS_LINUX)
   content::ZygoteHost::GetInstance()->AdjustRendererOOMScore(
       focused_tab_pid_, chrome::kLowestRendererOomScore);
+#endif
   pid_to_oom_score_[focused_tab_pid_] = chrome::kLowestRendererOomScore;
 }
 
@@ -651,8 +657,10 @@
     // If a process has the same score as the newly calculated value,
     // do not set it.
     if (it == pid_to_oom_score_.end() || it->second != score) {
+#if defined(OS_LINUX)
       content::ZygoteHost::GetInstance()->AdjustRendererOOMScore(*iterator,
                                                                  score);
+#endif
       pid_to_oom_score_[*iterator] = score;
     }
     priority += priority_increment;
