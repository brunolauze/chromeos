--- chrome/browser/extensions/component_loader.cc.orig	2014-06-03 09:16:01.818090551 -0500
+++ chrome/browser/extensions/component_loader.cc	2014-06-03 09:20:58.515093061 -0500
@@ -409,12 +409,21 @@
   // to AddDefaultComponentExtensionsWithBackgroundPages.
 #if defined(OS_CHROMEOS)
   Add(IDR_MOBILE_MANIFEST,
+#if defined(OS_FREEBSD)
+      base::FilePath(FILE_PATH_LITERAL("/usr/local/share/chromeos-assets/mobile")));
+#else
       base::FilePath(FILE_PATH_LITERAL("/usr/share/chromeos-assets/mobile")));
+#endif
 
 #if defined(GOOGLE_CHROME_BUILD)
   if (browser_defaults::enable_help_app) {
+#if defined(OS_FREEBSD)
+    Add(IDR_HELP_MANIFEST, base::FilePath(FILE_PATH_LITERAL(
+                               "/usr/local/share/chromeos-assets/helpapp")));
+#else
     Add(IDR_HELP_MANIFEST, base::FilePath(FILE_PATH_LITERAL(
                                "/usr/share/chromeos-assets/helpapp")));
+#endif
   }
 #endif
 
@@ -424,9 +433,13 @@
     if (!command_line->HasSwitch(chromeos::switches::kGuestSession))
       Add(IDR_BOOKMARKS_MANIFEST,
           base::FilePath(FILE_PATH_LITERAL("bookmark_manager")));
-
+#if defined(OS_FREEBSD)
+    Add(IDR_CROSH_BUILTIN_MANIFEST, base::FilePath(FILE_PATH_LITERAL(
+        "/usr/local/share/chromeos-assets/crosh_builtin")));
+#else
     Add(IDR_CROSH_BUILTIN_MANIFEST, base::FilePath(FILE_PATH_LITERAL(
         "/usr/share/chromeos-assets/crosh_builtin")));
+#endif
   }
 #else  // !defined(OS_CHROMEOS)
   DCHECK(!skip_session_components);
@@ -478,10 +491,17 @@
 #if defined(OS_CHROMEOS) && defined(GOOGLE_CHROME_BUILD)
   // Since this is a v2 app it has a background page.
   if (!command_line->HasSwitch(chromeos::switches::kDisableGeniusApp)) {
+#if defined(OS_FREEBSD)
+    AddWithName(IDR_GENIUS_APP_MANIFEST,
+                base::FilePath(FILE_PATH_LITERAL(
+                    "/usr/local/share/chromeos-assets/genius_app")),
+                l10n_util::GetStringUTF8(IDS_GENIUS_APP_NAME));
+#else
     AddWithName(IDR_GENIUS_APP_MANIFEST,
                 base::FilePath(FILE_PATH_LITERAL(
                     "/usr/share/chromeos-assets/genius_app")),
                 l10n_util::GetStringUTF8(IDS_GENIUS_APP_NAME));
+#endif
   }
 #endif
 
@@ -514,14 +534,24 @@
 #if defined(GOOGLE_CHROME_BUILD)
     if (!command_line->HasSwitch(
             chromeos::switches::kDisableQuickofficeComponentApp)) {
+#if defined(OS_FREEBSD)
+      std::string id = Add(IDR_QUICKOFFICE_MANIFEST, base::FilePath(
+          FILE_PATH_LITERAL("/usr/local/share/chromeos-assets/quickoffice")));
+#else
       std::string id = Add(IDR_QUICKOFFICE_MANIFEST, base::FilePath(
           FILE_PATH_LITERAL("/usr/share/chromeos-assets/quickoffice")));
+#endif
       EnableFileSystemInGuestMode(id);
     }
 #endif  // defined(GOOGLE_CHROME_BUILD)
 
+#if defined(OS_FREEBSD)
+    Add(IDR_ECHO_MANIFEST,
+        base::FilePath(FILE_PATH_LITERAL("/usr/local/share/chromeos-assets/echo")));
+#else
     Add(IDR_ECHO_MANIFEST,
         base::FilePath(FILE_PATH_LITERAL("/usr/share/chromeos-assets/echo")));
+#endif
 
     if (!command_line->HasSwitch(chromeos::switches::kGuestSession)) {
       Add(IDR_WALLPAPERMANAGER_MANIFEST,
@@ -581,7 +611,11 @@
           command_line->GetSwitchValuePath(switches::kEasyUnlockAppPath));
       Add(IDR_EASY_UNLOCK_MANIFEST, easy_unlock_path);
     } else {
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) && defined(OS_FREEBSD)
+      Add(IDR_EASY_UNLOCK_MANIFEST,
+          base::FilePath(
+              FILE_PATH_LITERAL("/usr/local/share/chromeos-assets/easy_unlock")));
+#elif defined(OS_CHROMEOS) && defined(OS_LINUX)
       Add(IDR_EASY_UNLOCK_MANIFEST,
           base::FilePath(
               FILE_PATH_LITERAL("/usr/share/chromeos-assets/easy_unlock")));
