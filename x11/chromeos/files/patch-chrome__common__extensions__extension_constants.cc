--- chrome/common/extensions/extension_constants.cc.orig	2014-06-03 09:25:27.226047559 -0500
+++ chrome/common/extensions/extension_constants.cc	2014-06-03 09:26:33.046094928 -0500
@@ -145,6 +145,16 @@
     "chromeos/braille_ime";
 const char kBrailleImeEngineId[] =
     "_comp_ime_jddehjeebkoimngcbdkaahpobgicbffpbraille";
+#if defined(OS_FREEBSD)
+const char kConnectivityDiagnosticsPath[] =
+    "/usr/local/share/chromeos-assets/connectivity_diagnostics";
+const char kConnectivityDiagnosticsKioskPath[] =
+    "/usr/local/share/chromeos-assets/connectivity_diagnostics_kiosk";
+const char kConnectivityDiagnosticsLauncherPath[] =
+    "/usr/local/share/chromeos-assets/connectivity_diagnostics_launcher";
+const char kSpeechSynthesisExtensionPath[] =
+    "/usr/local/share/chromeos-assets/speech_synthesis/patts";
+#else
 const char kConnectivityDiagnosticsPath[] =
     "/usr/share/chromeos-assets/connectivity_diagnostics";
 const char kConnectivityDiagnosticsKioskPath[] =
@@ -153,6 +163,7 @@
     "/usr/share/chromeos-assets/connectivity_diagnostics_launcher";
 const char kSpeechSynthesisExtensionPath[] =
     "/usr/share/chromeos-assets/speech_synthesis/patts";
+#endif
 const char kSpeechSynthesisExtensionId[] =
     "gjjabgpgjpampikjhjpfhneeoapjbjaf";
 const char kWallpaperManagerId[] = "obklkkbkpaoaejdabbfldmcfplpdgolj";
