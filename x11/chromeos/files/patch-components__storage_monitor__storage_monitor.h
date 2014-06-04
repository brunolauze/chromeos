--- components/storage_monitor/storage_monitor.h.orig	2014-05-30 11:58:42.365314465 -0500
+++ components/storage_monitor/storage_monitor.h	2014-05-30 11:58:55.435309892 -0500
@@ -119,7 +119,7 @@
       base::string16* storage_object_id) const = 0;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   virtual device::MediaTransferProtocolManager*
       media_transfer_protocol_manager() = 0;
 #endif
