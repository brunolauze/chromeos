--- native_client/run.py.orig	2014-06-04 12:21:52.446471211 -0500
+++ native_client/run.py	2014-06-04 12:23:07.411466646 -0500
@@ -1,4 +1,4 @@
-#!/usr/bin/python
+#!/usr/bin/env python
 # Copyright (c) 2012 The Native Client Authors. All rights reserved.
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
@@ -584,6 +584,8 @@
     arch = 'x86-32'
   elif 'X86-64' in machine_line:
     arch = 'x86-64'
+  elif 'amd64' in machine_line:
+  arch = 'x86-64'
   elif 'ARM' in machine_line:
     arch = 'arm'
   elif 'MIPS' in machine_line:
