--- base/time/time.h.orig	2014-06-06 08:10:51.254172466 -0500
+++ base/time/time.h	2014-06-06 08:11:21.551170851 -0500
@@ -577,7 +577,7 @@
 class BASE_EXPORT TimeTicks {
  public:
   // We define this even without OS_CHROMEOS for seccomp sandbox testing.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // Force definition of the system trace clock; it is a chromeos-only api
   // at the moment and surfacing it in the right place requires mucking
   // with glibc et al.
