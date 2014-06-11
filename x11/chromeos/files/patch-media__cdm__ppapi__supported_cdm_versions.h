--- media/cdm/ppapi/supported_cdm_versions.h.orig	2014-06-07 11:07:04.824451070 -0500
+++ media/cdm/ppapi/supported_cdm_versions.h	2014-06-07 11:29:34.403358461 -0500
@@ -13,6 +13,7 @@
   switch(version) {
     // Latest.
     case CDM_MODULE_VERSION:
+    case 5:
       return true;
     default:
       return false;
