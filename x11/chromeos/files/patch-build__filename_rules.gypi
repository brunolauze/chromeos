--- build/filename_rules.gypi.orig	2014-05-24 12:36:45.501432371 -0500
+++ build/filename_rules.gypi	2014-05-24 12:37:54.734428531 -0500
@@ -85,7 +85,7 @@
     ['<(use_aura)==0 or OS!="win" or >(nacl_untrusted_build)==1', {
       'sources/': [ ['exclude', '_aurawin\\.(h|cc)$'] ]
     }],
-    ['<(use_aura)==0 or OS!="linux" or >(nacl_untrusted_build)==1', {
+    ['<(use_aura)==0 or (OS!="linux" and OS!="freebsd") or >(nacl_untrusted_build)==1', {
       'sources/': [ ['exclude', '_auralinux\\.(h|cc)$'] ]
     }],
     ['<(use_ash)==0 or >(nacl_untrusted_build)==1', {
