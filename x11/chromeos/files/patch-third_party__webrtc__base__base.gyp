--- third_party/webrtc/base/base.gyp.orig	2014-06-03 11:20:52.747598143 -0500
+++ third_party/webrtc/base/base.gyp	2014-06-03 11:21:34.775595955 -0500
@@ -534,7 +534,7 @@
             '<(DEPTH)/net/third_party/nss/ssl.gyp:libssl',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'link_settings': {
             'libraries': [
               '-lcrypto',
@@ -683,7 +683,7 @@
             'opensslstreamadapter.h',
           ],
         }],
-        ['OS!="linux" and OS!="android"', {
+        ['OS!="linux" and OS!="freebsd" and OS!="android"', {
           'sources!': [
             'linux.cc',
             'linux.h',
