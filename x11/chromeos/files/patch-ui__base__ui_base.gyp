--- ui/base/ui_base.gyp.orig	2014-06-03 11:11:28.500638023 -0500
+++ ui/base/ui_base.gyp	2014-06-03 11:12:06.995606598 -0500
@@ -365,7 +365,7 @@
             'x/selection_utils.h',
           ]
         }],
-        ['use_aura==0 or OS!="linux"', {
+        ['use_aura==0 or (OS!="linux" and OS!="freebsd")', {
           'sources!': [
             'resource/resource_bundle_auralinux.cc',
           ],
