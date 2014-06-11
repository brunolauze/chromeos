--- content/renderer/media/webrtc_audio_capturer.cc.orig	2014-06-06 07:56:30.156229718 -0500
+++ content/renderer/media/webrtc_audio_capturer.cc	2014-06-06 07:57:08.809227213 -0500
@@ -31,7 +31,7 @@
 // will fail if the user selects any rate outside these ranges.
 const int kValidInputRates[] =
     {192000, 96000, 48000, 44100, 32000, 16000, 8000};
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 const int kValidInputRates[] = {48000, 44100};
 #elif defined(OS_ANDROID)
 const int kValidInputRates[] = {48000, 44100};
