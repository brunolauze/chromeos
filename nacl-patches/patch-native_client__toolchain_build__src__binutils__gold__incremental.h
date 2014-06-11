--- native_client/toolchain_build/src/binutils/gold/incremental.h.orig	2014-06-07 23:19:13.825851243 -0500
+++ native_client/toolchain_build/src/binutils/gold/incremental.h	2014-06-07 23:19:37.948849770 -0500
@@ -342,7 +342,7 @@
 
  private:
   // Information about the script file.
-  Script_info* script_;
+  __unused Script_info* script_;
   // Objects that have been included by this script.
   std::vector<Incremental_input_entry*> objects_;
 };
