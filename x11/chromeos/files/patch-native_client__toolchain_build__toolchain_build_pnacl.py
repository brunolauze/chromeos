--- native_client/toolchain_build/toolchain_build_pnacl.py.orig	2014-06-11 08:14:32.832901321 -0500
+++ native_client/toolchain_build/toolchain_build_pnacl.py	2014-06-11 08:22:26.016870088 -0500
@@ -1,4 +1,4 @@
-#!/usr/bin/python
+#!/usr/bin/env python
 # Copyright (c) 2013 The Native Client Authors. All rights reserved.
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
@@ -94,6 +94,7 @@
       # For now we only do native builds for linux and mac
       'i686-linux': ('gcc', 'g++'), # treat 32-bit linux like a native build
       'x86_64-linux': ('gcc', 'g++'),
+      'x86_64-freebsd': ('clang', 'clang++'),
       # TODO(dschuff): switch to clang on mac
       'x86_64-apple-darwin': ('gcc', 'g++'),
       # Windows build should work for native and cross
@@ -121,6 +122,8 @@
     else:
       configure_args.append('--host=' + host)
 
+  configure_args.append('--disable-werror')
+
   extra_cxx_args = list(extra_cc_args)
 
   cc, cxx = CompilersForHost(host)
@@ -146,7 +149,7 @@
 def CmakeHostArchFlags(host, options):
   cmake_flags = []
   if options.clang:
-    cc ='%(abs_top_srcdir)s/../third_party/llvm-build/Release+Asserts/bin/clang'
+    cc ='/usr/bin/clang'
     cxx = cc + '++'
   else:
     cc, cxx = CompilersForHost(host)
@@ -225,7 +228,7 @@
     is_newlib = component == 'nacl-newlib'
     return (command.SyncGitRepoCmds(git_url, '%(output)s', revisions[component],
                                     clean=is_newlib,
-                                    git_cache='%(git_cache_dir)s',
+                                    git_cache=None,
                                     push_url=git_push_url,
                                     known_mirrors=KNOWN_MIRRORS,
                                     push_mirrors=PUSH_MIRRORS) +
