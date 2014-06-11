--- platform2/common-mk/common.gypi.orig	2014-06-09 07:18:05.541129587 -0500
+++ platform2/common-mk/common.gypi	2014-06-09 10:11:23.241436365 -0500
@@ -10,7 +10,7 @@
     'debug%': 0,
 
     # Set this to 0 if you'd like to disable -clang-syntax.
-    'clang_syntax%': 1,
+    'clang_syntax%': 0,
 
     # DON'T EDIT BELOW THIS LINE.
     # These arguments shouldn't be changed here.
@@ -60,7 +60,6 @@
       '-Wall',
       '-Wno-psabi',
       '-ggdb3',
-      '-fstack-protector-strong',
       '-Wformat=2',
       '-fvisibility=internal',
       '-Wa,--noexecstack',
