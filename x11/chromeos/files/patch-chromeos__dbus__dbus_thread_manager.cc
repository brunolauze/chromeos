--- chromeos/dbus/dbus_thread_manager.cc.orig	2014-06-07 11:30:37.920354581 -0500
+++ chromeos/dbus/dbus_thread_manager.cc	2014-06-07 15:32:38.950780555 -0500
@@ -483,6 +483,7 @@
   }
 
   // Determine whether we use stub or real client implementations.
+  // if ((!base::SysInfo::IsRunningOnChromeOS() && !base::SysInfo::IsRunningOnChromeBSD()) ||
   if (!base::SysInfo::IsRunningOnChromeOS() ||
       CommandLine::ForCurrentProcess()->HasSwitch(
           chromeos::switches::kDbusStub)) {
