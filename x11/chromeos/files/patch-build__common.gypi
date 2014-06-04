--- build/common.gypi.orig	2014-05-30 09:20:27.561964867 -0500
+++ build/common.gypi	2014-05-30 09:31:56.296918252 -0500
@@ -626,7 +626,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -1122,6 +1122,9 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    'os_ver%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -2148,7 +2151,7 @@
       }],
 
       # Enable brlapi by default for chromeos.
-      [ 'chromeos==1', {
+      [ 'chromeos==1 and OS!="freebsd"', {
         'use_brlapi%': 1,
       }],
 
@@ -4051,6 +4054,13 @@
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
