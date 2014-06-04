--- chrome/common/chrome_paths.h.orig	2014-05-30 15:06:19.417534867 -0500
+++ chrome/common/chrome_paths.h	2014-06-03 08:06:18.714375340 -0500
@@ -55,7 +55,7 @@
                                  // Getting this path does not create it.
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   DIR_STANDALONE_EXTERNAL_EXTENSIONS,  // Directory for 'per-extension'
                                        // definition manifest files that
                                        // describe extensions which are to be
@@ -116,7 +116,7 @@
                                    // files to be installed when managed user
                                    // session starts.
 
-#if defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || (defined(OS_MACOSX) && !defined(OS_IOS))
   DIR_NATIVE_MESSAGING,         // System directory where native messaging host
                                 // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,    // Directory with Native Messaging Hosts
