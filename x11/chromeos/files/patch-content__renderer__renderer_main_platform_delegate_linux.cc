--- content/renderer/renderer_main_platform_delegate_linux.cc.orig	2014-06-04 11:51:36.306594990 -0500
+++ content/renderer/renderer_main_platform_delegate_linux.cc	2014-06-04 12:02:28.542550012 -0500
@@ -44,6 +44,7 @@
   // http://code.google.com/p/chromium/wiki/LinuxSUIDSandbox
   //
   // Anything else is started in InitializeSandbox().
+#if !defined(OS_BSD)
   LinuxSandbox::InitializeSandbox();
   // about:sandbox uses a value returned from LinuxSandbox::GetStatus() before
   // any renderer has been started.
@@ -70,7 +71,7 @@
     CHECK_EQ(errno, EPERM);
   }
 #endif  // __x86_64__
-
+#endif
   return true;
 }
 
