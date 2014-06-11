--- content/shell/app/shell_main_delegate.cc.orig	2014-06-04 14:29:08.480945877 -0500
+++ content/shell/app/shell_main_delegate.cc	2014-06-04 14:34:55.522919146 -0500
@@ -67,8 +67,10 @@
 
 namespace {
 
+#if !defined(OS_FREEBSD)
 base::LazyInstance<content::ShellBreakpadClient>::Leaky
     g_shell_breakpad_client = LAZY_INSTANCE_INITIALIZER;
+#endif
 
 #if defined(OS_WIN)
 // If "Content Shell" doesn't show up in your list of trace providers in
@@ -200,6 +202,7 @@
     std::string process_type =
         CommandLine::ForCurrentProcess()->GetSwitchValueASCII(
             switches::kProcessType);
+#if !defined(OS_FREEBSD)
     breakpad::SetBreakpadClient(g_shell_breakpad_client.Pointer());
 #if defined(OS_MACOSX)
     base::mac::DisableOSCrashDumps();
@@ -215,6 +218,7 @@
 #else
       breakpad::InitCrashReporter(process_type);
 #endif
+#endif
     }
 #elif defined(OS_WIN)
     UINT new_flags =
@@ -251,7 +255,9 @@
     std::string process_type =
         CommandLine::ForCurrentProcess()->GetSwitchValueASCII(
             switches::kProcessType);
+#if !defined(OS_FREEBSD)
     breakpad::InitCrashReporter(process_type);
+#endif
   }
 }
 #endif
