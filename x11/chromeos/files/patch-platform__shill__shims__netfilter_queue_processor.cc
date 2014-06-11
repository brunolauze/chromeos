--- platform/shill/shims/netfilter_queue_processor.cc.orig	2014-06-09 12:04:57.810943477 -0500
+++ platform/shill/shims/netfilter_queue_processor.cc	2014-06-09 12:06:43.320972067 -0500
@@ -8,11 +8,13 @@
 #include <errno.h>
 #include <net/if.h>
 #include <netinet/in.h>
+#if !defined(__FreeBSD__)
 #include <libnetfilter_queue/libnetfilter_queue.h>
 #include <linux/ip.h>
 #include <linux/netfilter.h>    /* for NF_ACCEPT */
 #include <linux/types.h>
 #include <linux/udp.h>
+#endif
 #include <string.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
@@ -246,11 +248,15 @@
       reinterpret_cast<NetfilterQueueProcessor *>(private_data);
   uint32_t verdict;
   time_t now = time(NULL);
+#if defined(__FreeBSD__)
+  verdict = 1;
+#else
   if (processor->IsIncomingPacketAllowed(packet, now)) {
     verdict = NF_ACCEPT;
   } else {
     verdict = NF_DROP;
   }
+#endif
   return nfq_set_verdict(queue_handle, packet.packet_id(), verdict, 0, NULL);
 }
 
