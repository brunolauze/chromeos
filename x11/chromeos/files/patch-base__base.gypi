--- base/base.gypi.orig	2014-05-30 11:24:10.148454371 -0500
+++ base/base.gypi	2014-05-30 11:40:25.647390815 -0500
@@ -802,6 +802,11 @@
               ['include', '^worker_pool_linux\\.cc$'],
             ],
           }],
+	  ['os_bsd==1', {
+	    'sources!': [
+		'process/process_handle_linux.cc',
+	    ],
+	  }],
           ['OS == "android" and _toolset == "host" and host_os == "linux"', {
             'defines': [
               'OS_ANDROID_HOST=Linux',
@@ -915,11 +920,15 @@
               'process/memory_stubs.cc',
             ],
             'sources/': [
+              ['exclude', '^debug/proc_maps_linux\\.cc$'],
               ['exclude', '^files/file_path_watcher_linux\\.cc$'],
               ['exclude', '^files/file_path_watcher_stub\\.cc$'],
               ['exclude', '^file_util_linux\\.cc$'],
+              ['exclude', '^process/memory_linux\\.cc$'],
               ['exclude', '^process/process_linux\\.cc$'],
               ['exclude', '^sys_info_linux\\.cc$'],
+              ['exclude', '^process/process_iterator_linux\\.cc$'],
+              ['exclude', '^process/process_metrics_linux\\.cc$'],
             ],
           }],
           # Remove all unnecessary files for build_nexe.py to avoid exceeding
