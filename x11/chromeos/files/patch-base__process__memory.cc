--- base/process/memory.cc.orig	2014-06-03 15:15:50.018597821 -0500
+++ base/process/memory.cc	2014-06-03 15:28:46.928548210 -0500
@@ -3,6 +3,9 @@
 // found in the LICENSE file.
 
 #include "base/process/memory.h"
+#if defined(OS_FREEBSD)
+#include <stdlib.h>
+#endif
 
 namespace base {
 
@@ -27,4 +30,11 @@
 
 #endif
 
+#if defined(OS_FREEBSD)
+bool UncheckedMalloc(size_t size, void** result) {
+	*result = malloc(size);
+	return *result != NULL;
+}
+#endif
+
 }
