--- chrome/browser/ui/webui/about_ui.cc.orig	2014-05-30 15:06:19.411534786 -0500
+++ chrome/browser/ui/webui/about_ui.cc	2014-06-03 09:51:17.365940671 -0500
@@ -473,7 +473,7 @@
   output.append(base::StringPrintf("<a href='%s%s'>Discard tab now</a>",
                                    chrome::kChromeUIDiscardsURL,
                                    kRunCommand));
-
+#if defined(OS_LINUX)
   base::SystemMemoryInfoKB meminfo;
   base::GetSystemMemoryInfo(&meminfo);
   output.append("<h3>System memory information in MB</h3>");
@@ -506,7 +506,7 @@
   output.append(AddStringRow(
       "Graphics", base::IntToString(meminfo.gem_size / 1024 / 1024)));
   output.append("</table>");
-
+#endif
   AppendFooter(&output);
   return output;
 }
@@ -763,7 +763,7 @@
   return data;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -779,6 +779,7 @@
   return data;
 }
 
+#if !defined(OS_BSD)
 void AboutSandboxRow(std::string* data, const std::string& prefix, int name_id,
                      bool good) {
   data->append("<tr><td>");
@@ -849,6 +850,7 @@
   return data;
 }
 #endif
+#endif
 
 // AboutMemoryHandler ----------------------------------------------------------
 
@@ -1019,7 +1021,7 @@
   } else if (source_name_ == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(profile(), callback);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
