--- components/usb_service/usb_context.cc.orig	2014-05-25 14:12:43.217803550 -0500
+++ components/usb_service/usb_context.cc	2014-05-25 14:13:30.731774318 -0500
@@ -45,7 +45,9 @@
   running_ = false;
   // Spreading running_ to the UsbEventHandler thread.
   base::subtle::MemoryBarrier();
+#if !defined(OS_FREEBSD)
   libusb_interrupt_handle_event(context_);
+#endif
   base::PlatformThread::Join(thread_handle_);
 }
 
