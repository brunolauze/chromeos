--- chrome/app/chrome_main_delegate.h.orig	2014-05-22 07:47:41.841534944 -0500
+++ chrome/app/chrome_main_delegate.h	2014-05-24 13:15:00.940968409 -0500
@@ -38,7 +38,7 @@
   virtual bool ShouldSendMachPort(const std::string& process_type) OVERRIDE;
   virtual bool DelaySandboxInitialization(
       const std::string& process_type) OVERRIDE;
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   virtual void ZygoteStarting(
       ScopedVector<content::ZygoteForkDelegate>* delegates) OVERRIDE;
   virtual void ZygoteForked() OVERRIDE;
