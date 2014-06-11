--- native_client/toolchain_build/src/binutils/gold/archive.h.orig	2014-06-07 23:16:09.684863529 -0500
+++ native_client/toolchain_build/src/binutils/gold/archive.h	2014-06-08 11:42:50.738531223 -0500
@@ -40,7 +40,7 @@
 class Layout;
 class Symbol_table;
 class Object;
-class Read_symbols_data;
+struct Read_symbols_data;
 class Input_file_lib;
 class Incremental_archive_entry;
 
@@ -512,7 +512,7 @@
   do_for_all_unused_symbols(Symbol_visitor_base*) const;
 
   // For reading the files.
-  const Input_file_lib* lib_;
+  const __unused Input_file_lib* lib_;
   // Table of the objects in the group.
   std::vector<Archive_member> members_;
 };
