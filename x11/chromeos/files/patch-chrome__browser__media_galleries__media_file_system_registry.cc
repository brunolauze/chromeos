--- chrome/browser/media_galleries/media_file_system_registry.cc.orig	2014-05-22 07:47:43.806535090 -0500
+++ chrome/browser/media_galleries/media_file_system_registry.cc	2014-05-25 13:14:41.454051584 -0500
@@ -724,7 +724,10 @@
 // Constructor in 'private' section because depends on private class definition.
 MediaFileSystemRegistry::MediaFileSystemRegistry()
     : file_system_context_(new MediaFileSystemContextImpl) {
-  StorageMonitor::GetInstance()->AddObserver(this);
+  /* This conditional is needed for shutdown.  Destructors
+     try to get the media file system registry. */
+  if (StorageMonitor::GetInstance())
+    StorageMonitor::GetInstance()->AddObserver(this);
 }
 
 MediaFileSystemRegistry::~MediaFileSystemRegistry() {
