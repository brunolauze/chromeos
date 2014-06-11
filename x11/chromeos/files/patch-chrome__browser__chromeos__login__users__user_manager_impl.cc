--- chrome/browser/chromeos/login/users/user_manager_impl.cc.orig	2014-06-06 09:10:52.476925467 -0500
+++ chrome/browser/chromeos/login/users/user_manager_impl.cc	2014-06-06 10:46:12.454530328 -0500
@@ -957,7 +957,7 @@
           GetPrimaryUser() &&
           profile == GetProfileByUser(GetPrimaryUser()) &&
           CertLoader::IsInitialized() &&
-          base::SysInfo::IsRunningOnChromeOS()) {
+          (base::SysInfo::IsRunningOnChromeOS() || base::SysInfo::IsRunningOnChromeBSD())) {
         GetNSSCertDatabaseForProfile(profile,
                                      base::Bind(&OnGetNSSCertDatabaseForUser));
       }
