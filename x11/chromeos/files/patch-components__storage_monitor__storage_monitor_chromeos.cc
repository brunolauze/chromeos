--- components/storage_monitor/storage_monitor_chromeos.cc.orig	2014-06-03 10:55:51.694679187 -0500
+++ components/storage_monitor/storage_monitor_chromeos.cc	2014-06-03 10:59:26.217659876 -0500
@@ -103,6 +103,7 @@
   DiskMountManager::GetInstance()->AddObserver(this);
   CheckExistingMountPoints();
 
+#if defined(OS_LINUX)
   if (!media_transfer_protocol_manager_) {
     scoped_refptr<base::MessageLoopProxy> loop_proxy;
     media_transfer_protocol_manager_.reset(
@@ -112,6 +113,7 @@
   media_transfer_protocol_device_observer_.reset(
       new MediaTransferProtocolDeviceObserverLinux(
           receiver(), media_transfer_protocol_manager_.get()));
+#endif
 }
 
 void StorageMonitorCros::CheckExistingMountPoints() {
@@ -200,10 +202,12 @@
     StorageInfo* device_info) const {
   DCHECK(device_info);
 
+#if defined(OS_LINUX)
   if (media_transfer_protocol_device_observer_->GetStorageInfoForPath(
           path, device_info)) {
     return true;
   }
+#endif
 
   if (!path.IsAbsolute())
     return false;
@@ -242,10 +246,12 @@
     return;
   }
 
+#if defined(OS_LINUX)
   if (type == StorageInfo::MTP_OR_PTP) {
     media_transfer_protocol_device_observer_->EjectDevice(device_id, callback);
     return;
   }
+#endif
 
   std::string mount_path;
   for (MountMap::const_iterator info_it = mount_map_.begin();
