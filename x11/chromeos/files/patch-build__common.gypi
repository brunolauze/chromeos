--- build/common.gypi.orig	2014-06-09 07:46:19.537011399 -0500
+++ build/common.gypi	2014-06-09 14:18:07.903392260 -0500
@@ -636,7 +636,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -744,7 +744,7 @@
 
         # Use GPU accelerated cross process image transport by default
         # on linux builds with the Aura window manager
-        ['use_aura==1 and OS=="linux"', {
+        ['use_aura==1 and (OS=="linux" or OS=="freebsd")', {
           'ui_compositor_image_transport%': 1,
         }, {
           'ui_compositor_image_transport%': 0,
@@ -1138,6 +1138,9 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    'os_ver%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -1865,7 +1868,7 @@
         'use_cups%': 0,
       }],
 
-      ['enable_plugins==1 and (OS=="linux" or OS=="mac" or OS=="win")', {
+      ['enable_plugins==1 and (OS=="linux" or OS=="mac" or OS=="win" or OS=="freebsd")', {
         'enable_pepper_cdms%': 1,
       }, {
         'enable_pepper_cdms%': 0,
@@ -2167,7 +2170,7 @@
       }],
 
       # Enable brlapi by default for chromeos.
-      [ 'chromeos==1', {
+      [ 'chromeos==1 and OS!="freebsd"', {
         'use_brlapi%': 1,
       }],
 
@@ -3286,7 +3289,7 @@
         'cflags': [
           '<(werror)',  # See note above about the werror variable.
           '-pthread',
-          '-fno-exceptions',
+          #'-fno-exceptions',
           '-fno-strict-aliasing',  # See http://crbug.com/32204
           '-Wall',
           # TODO(evan): turn this back on once all the builds work.
@@ -4100,6 +4103,13 @@
         'ldflags': [
           '-Wl,--no-keep-memory',
         ],
+        'ldflags!': [
+          '-ldl',
+          '-pie',
+        ],
+        'libraries!': [
+          '-ldl',
+        ],
       },
     }],
     # Android-specific options; note that most are set above with Linux.
