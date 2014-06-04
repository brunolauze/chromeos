--- third_party/webrtc/base/taskrunner.cc.orig	2014-05-30 11:22:56.805461935 -0500
+++ third_party/webrtc/base/taskrunner.cc	2014-05-30 11:23:40.180484307 -0500
@@ -102,7 +102,7 @@
   std::vector<Task *>::iterator it;
   it = std::remove(tasks_.begin(),
                    tasks_.end(),
-                   reinterpret_cast<Task *>(NULL));
+                   static_cast<Task *>(NULL));
 
   tasks_.erase(it, tasks_.end());
 
