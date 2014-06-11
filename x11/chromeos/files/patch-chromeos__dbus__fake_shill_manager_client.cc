--- chromeos/dbus/fake_shill_manager_client.cc.orig	2014-06-09 07:43:58.048077190 -0500
+++ chromeos/dbus/fake_shill_manager_client.cc	2014-06-09 15:43:18.533040563 -0500
@@ -87,12 +87,14 @@
          state == shill::kStateReady;
 }
 
+#if !defined(OS_FREEBSD)
 void UpdatePortaledWifiState(const std::string& service_path) {
   DBusThreadManager::Get()->GetShillServiceClient()->GetTestInterface()
       ->SetServiceProperty(service_path,
                            shill::kStateProperty,
                            base::StringValue(shill::kStatePortal));
 }
+#endif
 
 const char* kTechnologyUnavailable = "unavailable";
 const char* kNetworkActivated = "activated";
@@ -628,6 +630,7 @@
   }
 
   // Wifi
+/*
   state = GetInitialStateForType(shill::kTypeWifi, &enabled);
   if (state != kTechnologyUnavailable) {
     bool portaled = false;
@@ -690,8 +693,9 @@
       profiles->AddService(shared_profile, kPortaledWifiPath);
     }
   }
-
+*/
   // Wimax
+/*
   state = GetInitialStateForType(shill::kTypeWimax, &enabled);
   if (state != kTechnologyUnavailable) {
     AddTechnology(shill::kTypeWimax, enabled);
@@ -707,8 +711,9 @@
                                  shill::kConnectableProperty,
                                  base::FundamentalValue(true));
   }
-
+*/
   // Cellular
+/*
   state = GetInitialStateForType(shill::kTypeCellular, &enabled);
   if (state != kTechnologyUnavailable) {
     bool activated = false;
@@ -752,8 +757,9 @@
                                  shill::kRoamingStateProperty,
                                  base::StringValue(shill::kRoamingStateHome));
   }
-
+*/
   // VPN
+/*
   state = GetInitialStateForType(shill::kTypeVPN, &enabled);
   if (state != kTechnologyUnavailable) {
     // Set the "Provider" dictionary properties. Note: when setting these in
@@ -782,6 +788,7 @@
     services->SetServiceProperty(
         "/service/vpn2", shill::kProviderProperty, provider_properties);
   }
+*/
 
   SortManagerServices();
 }
