--- platform2/libchromeos/chromeos/policy/libpolicy.cc.orig	2014-06-09 11:09:34.666173462 -0500
+++ platform2/libchromeos/chromeos/policy/libpolicy.cc	2014-06-09 11:09:49.496202909 -0500
@@ -36,8 +36,8 @@
 }
 
 const DevicePolicy& PolicyProvider::GetDevicePolicy() const {
-  if (!device_policy_is_loaded_)
-    DCHECK("Trying to get policy data but policy was not loaded!");
+//  if (!device_policy_is_loaded_)
+//    DCHECK("Trying to get policy data but policy was not loaded!");
 
   return *device_policy_;
 }
