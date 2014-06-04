--- chrome/browser/extensions/api/serial/serial_api.cc.orig	2014-05-25 13:10:49.347031189 -0500
+++ chrome/browser/extensions/api/serial/serial_api.cc	2014-05-25 13:11:19.526031739 -0500
@@ -84,7 +84,7 @@
 
 void SerialGetDevicesFunction::Work() {
   DCHECK_CURRENTLY_ON(BrowserThread::FILE);
-
+#if !defined(OS_FREEBSD)
   device::SerialDeviceInfoList devices;
   scoped_ptr<device::SerialDeviceEnumerator> enumerator =
       device::SerialDeviceEnumerator::Create();
@@ -106,6 +106,7 @@
   }
 
   results_ = serial::GetDevices::Results::Create(out_devices);
+#endif
 }
 
 SerialConnectFunction::SerialConnectFunction() {}
