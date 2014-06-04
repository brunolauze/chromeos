--- chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2014-05-22 07:47:43.412535194 -0500
+++ chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc	2014-05-24 13:20:47.386005221 -0500
@@ -167,10 +167,12 @@
 }
 
 bool ImageWriterPrivateListRemovableStorageDevicesFunction::RunAsync() {
+#if !defined(OS_FREEBSD)
   RemovableStorageProvider::GetAllDevices(
     base::Bind(
       &ImageWriterPrivateListRemovableStorageDevicesFunction::OnDeviceListReady,
       this));
+#endif
   return true;
 }
 
