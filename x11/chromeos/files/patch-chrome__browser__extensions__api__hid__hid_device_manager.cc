--- chrome/browser/extensions/api/hid/hid_device_manager.cc.orig	2014-06-03 11:02:31.447647311 -0500
+++ chrome/browser/extensions/api/hid/hid_device_manager.cc	2014-06-03 11:04:37.937662523 -0500
@@ -32,10 +32,12 @@
     uint16_t vendor_id,
     uint16_t product_id) {
   UpdateDevices();
-
+#if defined(OS_LINUX)
   HidService* hid_service = HidService::GetInstance();
   DCHECK(hid_service);
+#endif
   base::ListValue* api_devices = new base::ListValue();
+#if defined(OS_LINUX)
   for (ResourceIdToDeviceIdMap::const_iterator device_iter =
            device_ids_.begin();
        device_iter != device_ids_.end();
@@ -67,12 +69,14 @@
       }
     }
   }
+#endif
   return scoped_ptr<base::ListValue>(api_devices);
 }
 
 bool HidDeviceManager::GetDeviceInfo(int resource_id,
                                      device::HidDeviceInfo* device_info) {
   UpdateDevices();
+#if defined(OS_LINUX)
   HidService* hid_service = HidService::GetInstance();
   DCHECK(hid_service);
 
@@ -82,10 +86,14 @@
     return false;
 
   return hid_service->GetDeviceInfo(device_iter->second, device_info);
+#else
+  return false;
+#endif
 }
 
 void HidDeviceManager::UpdateDevices() {
   thread_checker_.CalledOnValidThread();
+#if defined(OS_LINUX)
   HidService* hid_service = HidService::GetInstance();
   DCHECK(hid_service);
 
@@ -114,6 +122,7 @@
   }
   device_ids_.swap(new_device_ids);
   resource_ids_.swap(new_resource_ids);
+#endif
 }
 
 // static
