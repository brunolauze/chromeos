--- components/storage_monitor/test_storage_monitor.cc.orig	2014-06-11 09:07:39.313685818 -0500
+++ components/storage_monitor/test_storage_monitor.cc	2014-06-11 09:10:36.351667862 -0500
@@ -8,7 +8,7 @@
 #include "base/synchronization/waitable_event.h"
 #include "components/storage_monitor/storage_info.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "components/storage_monitor/test_media_transfer_protocol_manager_linux.h"
 #include "device/media_transfer_protocol/media_transfer_protocol_manager.h"
 #endif
@@ -101,7 +101,7 @@
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 device::MediaTransferProtocolManager*
 TestStorageMonitor::media_transfer_protocol_manager() {
   return media_transfer_protocol_manager_.get();
