--- chrome/common/chrome_paths.cc.orig	2014-05-30 15:06:19.417534867 -0500
+++ chrome/common/chrome_paths.cc	2014-06-03 08:10:10.812362530 -0500
@@ -100,6 +100,18 @@
 #endif  // defined(GOOGLE_CHROME_BUILD)
 #endif  // defined(OS_LINUX)
 
+#if defined(OS_FREEBSD)
+// The path to the external extension <id>.json files.
+// /usr/local/share seems like a good choice, see: http://www.pathname.com/fhs/
+const base::FilePath::CharType kFilepathSinglePrefExtensions[] =
+#if defined(GOOGLE_CHROME_BUILD)
+    FILE_PATH_LITERAL("/usr/local/share/google-chrome/extensions");
+#else
+    FILE_PATH_LITERAL("/usr/local/share/chromium/extensions");
+#endif  // defined(GOOGLE_CHROME_BUILD)
+#endif  // defined(OS_FREEBSD)
+
+
 static base::LazyInstance<base::FilePath>
     g_invalid_specified_user_data_dir = LAZY_INSTANCE_INITIALIZER;
 
@@ -469,10 +481,12 @@
       if (!base::PathExists(cur))  // We don't want to create this
         return false;
       break;
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD)
+#if defined(OS_POSIX) && !defined(OS_MACOSX)
     case chrome::DIR_POLICY_FILES: {
 #if defined(GOOGLE_CHROME_BUILD)
       cur = base::FilePath(FILE_PATH_LITERAL("/etc/opt/chrome/policies"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL("/usr/local/etc/chrome/policies"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL("/etc/chromium/policies"));
 #endif
@@ -550,7 +564,7 @@
 #endif
       break;
 
-#if defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || (defined(OS_MACOSX) && !defined(OS_IOS))
     case chrome::DIR_NATIVE_MESSAGING:
 #if defined(OS_MACOSX)
 #if defined(GOOGLE_CHROME_BUILD)
@@ -561,6 +575,15 @@
           "/Library/Application Support/Chromium/NativeMessagingHosts"));
 #endif
 #else  // defined(OS_MACOSX)
+#if defined(OS_FREEBSD)
+#if defined(GOOGLE_CHROME_BUILD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chrome/native-messaging-hosts"));
+#else
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chromium/native-messaging-hosts"));
+#endif
+#else
 #if defined(GOOGLE_CHROME_BUILD)
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/opt/chrome/native-messaging-hosts"));
@@ -568,6 +591,7 @@
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/chromium/native-messaging-hosts"));
 #endif
+#endif
 #endif  // !defined(OS_MACOSX)
       break;
 
@@ -576,7 +600,7 @@
         return false;
       cur = cur.Append(FILE_PATH_LITERAL("NativeMessagingHosts"));
       break;
-#endif  // defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD) || (defined(OS_MACOSX) && !defined(OS_IOS))
 
     default:
       return false;
