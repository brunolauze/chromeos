--- content/browser/child_process_launcher.cc.orig	2014-05-22 07:47:48.455534592 -0500
+++ content/browser/child_process_launcher.cc	2014-05-25 14:30:04.595704375 -0500
@@ -66,7 +66,7 @@
 #else
         terminate_child_on_shutdown_(true)
 #endif
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
         , zygote_(false)
 #endif
         {
@@ -232,7 +232,7 @@
     // child termination.
     base::ScopedFD ipcfd_closer(ipcfd);
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     GetContentClient()->browser()->
         GetAdditionalMappedFilesForChildProcess(*cmd_line, child_process_id,
                                                 &files_to_register);
@@ -253,7 +253,7 @@
                 base::GlobalDescriptors::kBaseDescriptor));
       }
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
       if (process_type == switches::kRendererProcess) {
         const int sandbox_fd =
             RenderSandboxHostLinux::GetInstance()->GetRendererSocket();
@@ -307,7 +307,7 @@
       base::Bind(
           &Context::Notify,
           this_object.get(),
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
           use_zygote,
 #endif
           handle));
@@ -315,7 +315,7 @@
   }
 
   void Notify(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
@@ -328,7 +328,7 @@
     if (!handle)
       LOG(ERROR) << "Failed to launch child process";
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     zygote_ = zygote;
 #endif
     if (client_) {
@@ -355,7 +355,7 @@
         BrowserThread::PROCESS_LAUNCHER, FROM_HERE,
         base::Bind(
             &Context::TerminateInternal,
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
             zygote_,
 #endif
             process_.handle()));
@@ -372,7 +372,7 @@
   }
 
   static void TerminateInternal(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
@@ -386,7 +386,7 @@
     process.Terminate(RESULT_CODE_NORMAL_EXIT);
     // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     if (zygote) {
       // If the renderer was created via a zygote, we have to proxy the reaping
       // through the zygote process.
@@ -413,7 +413,7 @@
 #if defined(OS_ANDROID)
   // The fd to close after creating the process.
   int ipcfd_;
-#elif defined(OS_POSIX) && !defined(OS_MACOSX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   bool zygote_;
 #endif
 };
@@ -455,7 +455,7 @@
       *exit_code = context_->exit_code_;
     return context_->termination_status_;
   }
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (context_->zygote_) {
     context_->termination_status_ = ZygoteHostImpl::GetInstance()->
         GetTerminationStatus(handle, known_dead, &context_->exit_code_);
