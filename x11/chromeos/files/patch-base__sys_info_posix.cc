--- base/sys_info_posix.cc.orig	2014-06-09 07:43:57.307020684 -0500
+++ base/sys_info_posix.cc	2014-06-09 11:50:01.986007255 -0500
@@ -28,7 +28,7 @@
 
 namespace {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
 int NumberOfProcessors() {
   // It seems that sysconf returns the number of "logical" processors on both
   // Mac and Linux.  So we get the number of "online logical" processors.
@@ -40,7 +40,6 @@
 
   return static_cast<int>(res);
 }
-
 base::LazyInstance<
     base::internal::LazySysInfoValue<int, NumberOfProcessors> >::Leaky
     g_lazy_number_of_processors = LAZY_INSTANCE_INITIALIZER;
@@ -64,7 +63,7 @@
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
