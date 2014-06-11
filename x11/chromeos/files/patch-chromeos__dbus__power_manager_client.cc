--- chromeos/dbus/power_manager_client.cc.orig	2014-06-07 15:45:14.303750151 -0500
+++ chromeos/dbus/power_manager_client.cc	2014-06-07 15:48:25.700714441 -0500
@@ -667,11 +667,11 @@
 class PowerManagerClientStubImpl : public PowerManagerClient {
  public:
   PowerManagerClientStubImpl()
-      : discharging_(true),
-        battery_percentage_(40),
-        brightness_(50.0),
-        pause_count_(2),
-        cycle_count_(0),
+      : discharging_(false),
+        battery_percentage_(100),
+        brightness_(100.0),
+        pause_count_(0),
+        cycle_count_(2),
         num_pending_suspend_readiness_callbacks_(0),
         weak_ptr_factory_(this) {}
 
@@ -684,12 +684,14 @@
   // PowerManagerClient overrides:
   virtual void Init(dbus::Bus* bus) OVERRIDE {
     ParseCommandLineSwitch();
+/*
     if (power_cycle_delay_ != base::TimeDelta()) {
       update_timer_.Start(FROM_HERE,
                           power_cycle_delay_,
                           this,
                           &PowerManagerClientStubImpl::UpdateStatus);
     }
+*/
   }
 
   virtual void AddObserver(Observer* observer) OVERRIDE {
