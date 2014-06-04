--- media/cdm/ppapi/supported_cdm_versions.h.orig	2014-06-03 10:15:28.309846983 -0500
+++ media/cdm/ppapi/supported_cdm_versions.h	2014-06-03 10:17:04.348874705 -0500
@@ -13,6 +13,7 @@
   switch(version) {
     // Latest.
     case CDM_MODULE_VERSION:
+    case 5:
       return true;
     default:
       return false;
@@ -20,12 +21,15 @@
 }
 
 bool IsSupportedCdmInterfaceVersion(int version) {
+/*
   COMPILE_ASSERT(cdm::ContentDecryptionModule::kVersion ==
                  cdm::ContentDecryptionModule_4::kVersion,
                  update_code_below);
+*/
   switch(version) {
     // Supported versions in decreasing order.
     case cdm::ContentDecryptionModule_4::kVersion:
+    case cdm::ContentDecryptionModule_5::kVersion:
       return true;
     default:
       return false;
@@ -33,12 +37,15 @@
 }
 
 bool IsSupportedCdmHostVersion(int version) {
+/*
   COMPILE_ASSERT(cdm::ContentDecryptionModule::Host::kVersion ==
                  cdm::ContentDecryptionModule_4::Host::kVersion,
                  update_code_below);
+*/
   switch(version) {
     // Supported versions in decreasing order.
     case cdm::Host_4::kVersion:
+    case cdm::Host_5::kVersion:
       return true;
     default:
       return false;
