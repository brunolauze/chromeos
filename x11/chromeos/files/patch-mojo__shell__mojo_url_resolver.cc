--- mojo/shell/mojo_url_resolver.cc.orig	2014-06-10 15:49:12.419638187 -0500
+++ mojo/shell/mojo_url_resolver.cc	2014-06-10 15:49:26.459635709 -0500
@@ -17,7 +17,7 @@
 std::string MakeSharedLibraryName(const std::string& file_name) {
 #if defined(OS_WIN)
   return file_name + ".dll";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   return "lib" + file_name + ".so";
 #elif defined(OS_MACOSX)
   return "lib" + file_name + ".dylib";
