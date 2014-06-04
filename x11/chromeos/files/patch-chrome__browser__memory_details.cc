--- chrome/browser/memory_details.cc.orig	2014-05-30 15:06:19.409534737 -0500
+++ chrome/browser/memory_details.cc	2014-06-03 10:21:48.716814715 -0500
@@ -32,7 +32,7 @@
 #include "grit/generated_resources.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #endif
 
@@ -202,7 +202,7 @@
 void MemoryDetails::CollectChildInfoOnUIThread() {
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   const pid_t zygote_pid = content::ZygoteHost::GetInstance()->GetPid();
 #endif
 
@@ -334,7 +334,7 @@
       }
     }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     if (process.pid == zygote_pid) {
       process.process_type = content::PROCESS_TYPE_ZYGOTE;
     }
@@ -448,7 +448,7 @@
         continue;
     }
   }
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) && defined(OS_LINUX)
   // Chrome OS exposes system-wide graphics driver memory which has historically
   // been a source of leak/bloat.
   base::SystemMemoryInfoKB meminfo;
