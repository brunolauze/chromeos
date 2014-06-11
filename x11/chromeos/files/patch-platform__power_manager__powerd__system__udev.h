--- platform/power_manager/powerd/system/udev.h.orig	2014-06-10 07:09:55.355298220 -0500
+++ platform/power_manager/powerd/system/udev.h	2014-06-10 07:10:46.977299903 -0500
@@ -13,8 +13,10 @@
 #include <base/message_loop/message_loop.h>
 #include <base/observer_list.h>
 
+#if defined(__linux__)
 struct udev;
 struct udev_monitor;
+#endif
 
 namespace power_manager {
 namespace system {
@@ -54,9 +56,10 @@
   virtual void OnFileCanWriteWithoutBlocking(int fd) OVERRIDE;
 
  private:
+#if defined(__linux__)
   struct udev* udev_;
   struct udev_monitor* udev_monitor_;
-
+#endif
   // Maps from a subsystem name to the corresponding observers.
   typedef std::map<std::string, linked_ptr<ObserverList<UdevObserver> > >
       ObserverMap;
