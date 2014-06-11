--- native_client/toolchain_build/src/llvm/tools/gold/gold-plugin.cpp.orig	2014-06-08 13:04:50.527168394 -0500
+++ native_client/toolchain_build/src/llvm/tools/gold/gold-plugin.cpp	2014-06-08 13:23:45.880088978 -0500
@@ -54,6 +54,7 @@
   ld_plugin_set_extra_library_path set_extra_library_path = NULL;
   ld_plugin_get_view get_view = NULL;
   ld_plugin_message message = discard_message;
+/*
   // @LOCALMOD-BEGIN
   // Callback for getting the number of --wrap'd symbols.
   ld_plugin_get_num_wrapped get_num_wrapped = NULL;
@@ -61,7 +62,7 @@
   // Callback for getting the name of a wrapped symbol.
   ld_plugin_get_wrapped get_wrapped = NULL;
   // @LOCALMOD-END
-
+*/
   int api_version = 0;
   int gold_version = 0;
 
@@ -221,6 +222,7 @@
       case LDPT_GET_VIEW:
         get_view = tv->tv_u.tv_get_view;
         break;
+/*
       // @LOCALMOD-BEGIN
       case LDPT_GET_WRAPPED:
         get_wrapped = tv->tv_u.tv_get_wrapped;
@@ -228,6 +230,7 @@
       case LDPT_GET_NUM_WRAPPED:
         get_num_wrapped = tv->tv_u.tv_get_num_wrapped;
         break;
+*/
       // @LOCALMOD-END
       case LDPT_MESSAGE:
         message = tv->tv_u.tv_message;
@@ -441,6 +444,7 @@
   }
 
   // @LOCALMOD-BEGIN
+/*
   // Perform symbol wrapping.
   unsigned num_wrapped;
   if ((*get_num_wrapped)(&num_wrapped) != LDPS_OK) {
@@ -455,6 +459,7 @@
     }
     lto_codegen_wrap_symbol_in_merged_module(code_gen, sym);
   }
+*/
   // @LOCALMOD-END
 
   if (options::generate_bc_file != options::BC_NO) {
