--- third_party/webrtc/build/common.gypi.orig	2014-05-30 11:05:22.530546280 -0500
+++ third_party/webrtc/build/common.gypi	2014-05-30 11:22:12.698489592 -0500
@@ -303,6 +303,14 @@
           'WEBRTC_LINUX',
         ],
       }],
+      ['os_bsd==1', {
+        'defines': [
+          'WEBRTC_BSD',
+	  'BSD',
+	  'WEBRTC_LINUX',
+          'WEBRTC_THREAD_RR',
+        ],
+      }],
       ['OS=="mac"', {
         'defines': [
           'WEBRTC_MAC',
