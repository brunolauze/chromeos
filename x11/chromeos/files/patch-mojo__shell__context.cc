--- mojo/shell/context.cc.orig	2014-06-10 13:49:50.818132306 -0500
+++ mojo/shell/context.cc	2014-06-10 13:50:24.388128380 -0500
@@ -22,7 +22,7 @@
 #include "mojo/shell/switches.h"
 #include "mojo/spy/spy.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "mojo/shell/dbus_service_loader_linux.h"
 #endif  // defined(OS_LINUX)
 
@@ -110,7 +110,7 @@
       GURL("mojo:mojo_view_manager"));
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   service_manager_.SetLoaderForScheme(
       scoped_ptr<ServiceLoader>(new DBusServiceLoader(this)),
       "dbus");
