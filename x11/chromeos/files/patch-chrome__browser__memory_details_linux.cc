--- chrome/browser/memory_details_linux.cc.orig	2014-06-03 10:34:12.529765369 -0500
+++ chrome/browser/memory_details_linux.cc	2014-06-03 10:35:32.041758668 -0500
@@ -233,7 +233,7 @@
     process_data_.push_back(browser);
   }
 
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) && defined(OS_LINUX)
   base::GetSwapInfo(&swap_info_);
 #endif
 
