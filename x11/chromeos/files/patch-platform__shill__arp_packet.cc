--- platform/shill/arp_client.cc.orig	2014-06-09 14:56:55.001232222 -0500
+++ platform/shill/arp_client.cc	2014-06-09 14:57:20.733258290 -0500
@@ -4,7 +4,11 @@
 
 #include "shill/arp_client.h"
 
+#if defined(__FreeBSD__)
+
+#else
 #include <linux/if_packet.h>
+#endif
 #include <net/ethernet.h>
 #include <net/if_arp.h>
 #include <netinet/in.h>
