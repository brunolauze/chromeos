--- native_client/toolchain_build/src/binutils/bfd/elfxx-mips.c.orig	2014-06-04 13:29:14.046193268 -0500
+++ native_client/toolchain_build/src/binutils/bfd/elfxx-mips.c	2014-06-04 13:29:57.594189245 -0500
@@ -1974,13 +1974,13 @@
   return r_type == R_MIPS_GOT_PAGE || r_type == R_MICROMIPS_GOT_PAGE;
 }
 
-static inline bfd_boolean
+static inline __unused bfd_boolean
 got_ofst_reloc_p (unsigned int r_type)
 {
   return r_type == R_MIPS_GOT_OFST || r_type == R_MICROMIPS_GOT_OFST;
 }
 
-static inline bfd_boolean
+static inline __unused bfd_boolean
 got_hi16_reloc_p (unsigned int r_type)
 {
   return r_type == R_MIPS_GOT_HI16 || r_type == R_MICROMIPS_GOT_HI16;
