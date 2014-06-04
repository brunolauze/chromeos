--- device/media_transfer_protocol/media_transfer_protocol_manager.h.orig	2014-05-30 11:54:36.750328649 -0500
+++ device/media_transfer_protocol/media_transfer_protocol_manager.h	2014-05-30 11:55:03.738375236 -0500
@@ -12,8 +12,8 @@
 #include "base/memory/ref_counted.h"
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
-#error "Only used on Linux and ChromeOS"
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
+#error "Only used on Linux, FreeBSD and ChromeOS"
 #endif
 
 class MtpFileEntry;
