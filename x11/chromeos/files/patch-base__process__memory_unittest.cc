--- base/process/memory_unittest.cc.orig	2014-05-22 07:47:41.517535146 -0500
+++ base/process/memory_unittest.cc	2014-05-24 12:39:17.063421092 -0500
@@ -421,7 +421,7 @@
     EXPECT_EQ(0, bytes[i]);
   free(value_);
 
-  EXPECT_FALSE(base::UncheckedCalloc(1, test_size_, &value_));
+#endif  // !defined(OS_ANDROID) && !defined(OS_BSD) &&
   EXPECT_TRUE(value_ == NULL);
 }
 #endif  // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
