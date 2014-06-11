--- chrome/common/chrome_paths.h.orig	2014-06-05 14:26:36.650571661 -0500
+++ chrome/common/chrome_paths.h	2014-06-05 14:35:32.399563845 -0500
@@ -55,7 +55,7 @@
                                  // Getting this path does not create it.
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   DIR_STANDALONE_EXTERNAL_EXTENSIONS,  // Directory for 'per-extension'
                                        // definition manifest files that
                                        // describe extensions which are to be
@@ -115,7 +115,7 @@
   DIR_MANAGED_USERS_DEFAULT_APPS,  // Directory where installer places .crx
                                    // files to be installed when managed user
                                    // session starts.
-#if defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || (defined(OS_MACOSX) && !defined(OS_IOS))
   DIR_NATIVE_MESSAGING,         // System directory where native messaging host
                                 // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,    // Directory with Native Messaging Hosts
