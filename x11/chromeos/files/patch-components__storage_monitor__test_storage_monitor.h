--- components/storage_monitor/test_storage_monitor.h.orig	2014-06-11 09:11:19.030668319 -0500
+++ components/storage_monitor/test_storage_monitor.h	2014-06-11 09:11:43.747689175 -0500
@@ -45,7 +45,7 @@
       base::string16* storage_object_id) const OVERRIDE;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   virtual device::MediaTransferProtocolManager*
       media_transfer_protocol_manager() OVERRIDE;
 #endif
@@ -68,7 +68,7 @@
   // The last device to be ejected.
   std::string ejected_device_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   scoped_ptr<device::MediaTransferProtocolManager>
       media_transfer_protocol_manager_;
 #endif
