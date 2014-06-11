--- native_client/toolchain_build/toolchain_build.py.orig	2014-06-11 08:14:32.831901198 -0500
+++ native_client/toolchain_build/toolchain_build.py	2014-06-11 08:18:04.562886599 -0500
@@ -1,4 +1,4 @@
-#!/usr/bin/python
+#!/usr/bin/env python
 # Copyright (c) 2012 The Native Client Authors. All rights reserved.
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
@@ -119,7 +119,7 @@
         'type': 'source',
         'commands': command.SyncGitRepoCmds(GitUrl(package), '%(output)s',
                                             info['rev'],
-                                            git_cache='%(git_cache_dir)s',
+                                            git_cache=None,
                                             push_url=GitUrl(package, True),
                                             known_mirrors=KNOWN_MIRRORS,
                                             push_mirrors=PUSH_MIRRORS),
@@ -287,6 +287,8 @@
       # a --build switch to ensure things build correctly.
       configure_args.append('--build=' + host)
 
+  configure_args.append('--disable-werror')
+
   extra_cxx_args = list(extra_cc_args)
   if fnmatch.fnmatch(host, '*-linux*'):
     # Avoid shipping binaries with a runtime dependency on
@@ -294,6 +296,12 @@
     # TODO(mcgrathr): Do we want this for MinGW and/or Mac too?
     extra_cxx_args.append('-static-libstdc++')
 
+  if fnmatch.fnmatch(host, '*-freebsd*'):
+    # Avoid shipping binaries with a runtime dependency on
+    # a particular version of the libstdc++ shared library.
+    # TODO(mcgrathr): Do we want this for MinGW and/or Mac too?
+    extra_cxx_args.append('-static-libstdc++')
+
   if extra_cc_args:
     # These are the defaults when there is no setting, but we will add
     # additional switches, so we must supply the command name too.
