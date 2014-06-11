--- content/content_shell.gypi.orig	2014-06-04 09:28:13.166189857 -0500
+++ content/content_shell.gypi	2014-06-04 09:29:35.063184987 -0500
@@ -43,7 +43,7 @@
         '../base/base.gyp:base_static',
         '../base/third_party/dynamic_annotations/dynamic_annotations.gyp:dynamic_annotations',
         '../cc/cc.gyp:cc',
-        '../components/components.gyp:breakpad_component',
+        #'../components/components.gyp:breakpad_component',
         '../gin/gin.gyp:gin',
         '../gpu/gpu.gyp:gpu',
         '../ipc/ipc.gyp:ipc',
@@ -75,8 +75,8 @@
         'shell/android/shell_manager.h',
         'shell/app/paths_mac.h',
         'shell/app/paths_mac.mm',
-        'shell/app/shell_breakpad_client.cc',
-        'shell/app/shell_breakpad_client.h',
+        #'shell/app/shell_breakpad_client.cc',
+        #'shell/app/shell_breakpad_client.h',
         'shell/app/shell_main_delegate.cc',
         'shell/app/shell_main_delegate.h',
         'shell/app/shell_main_delegate_mac.h',
@@ -294,7 +294,7 @@
             'copy_test_netscape_plugin',
           ],
         }],  # OS=="android"
-        ['os_posix == 1 and OS != "mac" and android_webview_build != 1', {
+        ['os_posix == 1 and OS != "freebsd" and OS != "mac" and android_webview_build != 1', {
           'dependencies': [
             '../components/components.gyp:breakpad_host',
           ],
