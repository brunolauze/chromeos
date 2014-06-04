--- chrome/browser/extensions/api/hid/hid_api.cc.orig	2014-06-03 10:59:59.980658394 -0500
+++ chrome/browser/extensions/api/hid/hid_api.cc	2014-06-03 11:34:31.412516742 -0500
@@ -109,6 +109,7 @@
 }
 
 void HidConnectFunction::AsyncWorkStart() {
+#if defined(OS_LINUX)
   device::HidDeviceInfo device_info;
   if (!device_manager_->GetDeviceInfo(parameters_->device_id, &device_info)) {
     CompleteWithError(kErrorInvalidDeviceId);
@@ -137,6 +138,8 @@
   int connection_id = connection_manager_->Add(
       new HidConnectionResource(extension_->id(), connection));
   SetResult(PopulateHidConnection(connection_id, connection));
+#endif
+
   AsyncWorkCompleted();
 }
 
