--- native_client/src/shared/serialization/serialization.h.orig	2014-06-04 06:49:37.618844876 -0500
+++ native_client/src/shared/serialization/serialization.h	2014-06-04 06:55:23.562821377 -0500
@@ -8,11 +8,13 @@
 #ifndef NATIVE_CLIENT_SRC_SHARED_SERIALIZATION_SERIALIZATION_H_
 #define NATIVE_CLIENT_SRC_SHARED_SERIALIZATION_SERIALIZATION_H_
 
+#if !defined(__FreeBSD__)
 #if defined(__native_client__) || (NACL_LINUX && !NACL_ANDROID)
 # define NACL_HAS_IEEE_754
 // Make sure fp is not dead code and is tested.  DO NOT USE the fp
 // interface until we have a portability version of ieee754.h!
 #endif
+#endif
 
 #if defined(NACL_HAS_IEEE_754)
 # include <ieee754.h>
