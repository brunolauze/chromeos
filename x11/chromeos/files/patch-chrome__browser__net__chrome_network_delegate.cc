--- chrome/browser/net/chrome_network_delegate.cc.orig	2014-06-03 09:21:55.411091028 -0500
+++ chrome/browser/net/chrome_network_delegate.cc	2014-06-03 09:22:50.229059694 -0500
@@ -778,8 +778,13 @@
       "/home/chronos/user/log",
       "/home/chronos/user/WebRTC Logs",
       "/media",
+#if defined(OS_FREEBSD)
+      "/usr/local/share/oem",
+      "/usr/local/share/chromeos-assets",
+#else
       "/opt/oem",
       "/usr/share/chromeos-assets",
+#endif
       "/tmp",
       "/var/log",
   };
