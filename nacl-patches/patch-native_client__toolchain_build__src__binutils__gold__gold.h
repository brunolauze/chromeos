--- native_client/toolchain_build/src/binutils/gold/gold.h.orig	2014-06-08 11:47:35.648487865 -0500
+++ native_client/toolchain_build/src/binutils/gold/gold.h	2014-06-08 11:55:13.450461764 -0500
@@ -98,6 +98,7 @@
 
 #elif defined(HAVE_EXT_HASH_MAP) && defined(HAVE_EXT_HASH_SET)
 
+#undef __DEPRECATED
 #include <ext/hash_map>
 #include <ext/hash_set>
 #include <string>
@@ -114,7 +115,14 @@
 {
   size_t
   operator()(std::string s) const
-  { return __stl_hash_string(s.c_str()); }
+  { 
+#if defined(__FreeBSD__)
+            std::hash<std::string> hash_fn;
+            return hash_fn(s);
+#else
+	return __stl_hash_string(s.c_str()); 
+#endif
+}
 };
 
 template<typename T>
