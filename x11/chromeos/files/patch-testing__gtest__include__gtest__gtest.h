--- testing/gtest/include/gtest/gtest.h.orig	2014-06-03 07:20:13.230567075 -0500
+++ testing/gtest/include/gtest/gtest.h	2014-06-03 07:24:40.440547861 -0500
@@ -274,7 +274,7 @@
       typename internal::EnableIf<
           !internal::ImplicitlyConvertible<T, AssertionResult>::value>::type*
           /*enabler*/ = NULL)
-      : success_(success) {}
+      : success_(true /*success */) {}
 
   GTEST_DISABLE_MSC_WARNINGS_POP_()
 
