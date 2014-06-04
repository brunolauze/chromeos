--- content/renderer/media/webrtc_audio_capturer.cc.orig	2014-05-22 07:47:48.982535381 -0500
+++ content/renderer/media/webrtc_audio_capturer.cc	2014-05-30 07:34:20.948402967 -0500
@@ -31,7 +31,7 @@
 // will fail if the user selects any rate outside these ranges.
 const int kValidInputRates[] =
     {192000, 96000, 48000, 44100, 32000, 16000, 8000};
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 const int kValidInputRates[] = {48000, 44100};
 #elif defined(OS_ANDROID)
 const int kValidInputRates[] = {48000, 44100};
@@ -457,7 +457,7 @@
 // CaptureCallback.
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
