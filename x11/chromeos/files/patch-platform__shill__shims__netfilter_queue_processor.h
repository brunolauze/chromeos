--- platform/shill/shims/netfilter_queue_processor.h.orig	2014-06-09 11:57:33.842978050 -0500
+++ platform/shill/shims/netfilter_queue_processor.h	2014-06-09 11:57:53.592975251 -0500
@@ -116,7 +116,7 @@
     uint32_t destination;
   };
 
-  typedef std::tr1::shared_ptr<ListenerEntry> ListenerEntryPtr;
+  typedef std::shared_ptr<ListenerEntry> ListenerEntryPtr;
 
   // Called by the netlink_queue code when a packet arrives for the
   // input queue.
