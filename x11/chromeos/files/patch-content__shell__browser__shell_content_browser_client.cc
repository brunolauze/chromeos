--- content/shell/browser/shell_content_browser_client.cc.orig	2014-06-05 17:55:02.358709767 -0500
+++ content/shell/browser/shell_content_browser_client.cc	2014-06-05 18:02:25.650683200 -0500
@@ -42,8 +42,10 @@
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX)
 #include "base/debug/leak_annotations.h"
+#if !defined(OS_FREEBSD)
 #include "components/breakpad/app/breakpad_linux.h"
 #include "components/breakpad/browser/crash_handler_host_linux.h"
+#endif
 #include "content/public/common/content_descriptors.h"
 #endif
 
@@ -59,7 +61,7 @@
 ShellContentBrowserClient* g_browser_client;
 bool g_swap_processes_for_redirect = false;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_FREEBSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path =
@@ -322,7 +324,8 @@
                              base::FileDescriptor(f.Pass())));
     }
   }
-#else  // !defined(OS_ANDROID)
+#elif !defined(OS_FREEBSD)  // !defined(OS_ANDROID)
+
   int crash_signal_fd = GetCrashSignalFD(command_line);
   if (crash_signal_fd >= 0) {
     mappings->push_back(FileDescriptorInfo(
