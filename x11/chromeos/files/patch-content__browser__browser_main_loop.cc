--- content/browser/browser_main_loop.cc.orig	2014-05-23 08:53:11.702309688 -0500
+++ content/browser/browser_main_loop.cc	2014-05-25 14:25:58.255720059 -0500
@@ -131,7 +131,7 @@
 namespace content {
 namespace {
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void SetupSandbox(const CommandLine& parsed_command_line) {
   TRACE_EVENT0("startup", "SetupSandbox");
   base::FilePath sandbox_binary;
@@ -332,7 +332,7 @@
 void BrowserMainLoop::EarlyInitialization() {
   TRACE_EVENT0("startup", "BrowserMainLoop::EarlyInitialization");
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   // No thread should be created before this call, as SetupSandbox()
   // will end-up using fork().
   SetupSandbox(parsed_command_line_);
@@ -758,7 +758,7 @@
   }
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHostImpl::GetInstance()->TearDownAfterLastChild();
 #endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
 
