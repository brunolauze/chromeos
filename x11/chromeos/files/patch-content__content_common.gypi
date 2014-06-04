--- content/content_common.gypi.orig	2014-05-29 22:12:01.323730655 -0500
+++ content/content_common.gypi	2014-05-30 07:26:17.328436415 -0500
@@ -587,6 +587,27 @@
         'content.gyp:common_aidl',
       ],
     }],
+    ['os_bsd==1', {
+      'sources!': [
+      'common/sandbox_linux/android/sandbox_bpf_base_policy_android.cc',
+      'common/sandbox_linux/android/sandbox_bpf_base_policy_android.h',
+      'common/sandbox_linux/bpf_cros_arm_gpu_policy_linux.cc',
+      'common/sandbox_linux/bpf_cros_arm_gpu_policy_linux.h',
+      'common/sandbox_linux/bpf_gpu_policy_linux.cc',
+      'common/sandbox_linux/bpf_gpu_policy_linux.h',
+      'common/sandbox_linux/bpf_ppapi_policy_linux.cc',
+      'common/sandbox_linux/bpf_ppapi_policy_linux.h',
+      'common/sandbox_linux/bpf_renderer_policy_linux.cc',
+      'common/sandbox_linux/bpf_renderer_policy_linux.h',
+      'common/sandbox_linux/sandbox_bpf_base_policy_linux.cc',
+      'common/sandbox_linux/sandbox_bpf_base_policy_linux.h',
+      'common/sandbox_linux/sandbox_init_linux.cc',
+      'common/sandbox_linux/sandbox_linux.cc',
+      'common/sandbox_linux/sandbox_linux.h',
+      'common/sandbox_linux/sandbox_seccomp_bpf_linux.cc',
+      'common/sandbox_linux/sandbox_seccomp_bpf_linux.h',
+      ],
+    }],
     ['use_pango == 1', {
       'dependencies': [
         '../build/linux/system.gyp:pangocairo',
