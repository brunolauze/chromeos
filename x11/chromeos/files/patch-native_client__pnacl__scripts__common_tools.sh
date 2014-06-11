--- native_client/pnacl/scripts/common-tools.sh.orig	2014-06-03 22:24:01.639936018 -0500
+++ native_client/pnacl/scripts/common-tools.sh	2014-06-07 12:35:20.061088352 -0500
@@ -42,6 +42,13 @@
   EXEC_EXT=
   SO_EXT=.so
   SO_DIR=lib
+elif [ "${BUILD_PLATFORM}" == "freebsd" ] ; then
+  BUILD_PLATFORM_LINUX=true
+  SCONS_BUILD_PLATFORM=linux
+  BUILD_ARCH=${BUILD_ARCH:-$(uname -m)}
+  EXEC_EXT=
+  SO_EXT=.so
+  SO_DIR=lib
 elif [[ "${BUILD_PLATFORM}" =~ cygwin_nt ]]; then
   BUILD_PLATFORM=win
   BUILD_PLATFORM_WIN=true
@@ -91,6 +98,9 @@
 elif [ "${BUILD_ARCH}" == "x86_64" ] ; then
   BUILD_ARCH_X8664=true
   BUILD_ARCH_SHORT=x86
+elif [ "${BUILD_ARCH}" == "amd64" ] ; then
+  BUILD_ARCH_X8664=true
+  BUILD_ARCH_SHORT=x86
 elif [ "${BUILD_ARCH}" == "armv7l" ] ; then
   BUILD_ARCH_ARM=true
   BUILD_ARCH_SHORT=arm
@@ -122,6 +132,8 @@
   HOST_ARCH_X8632=true
 elif [ "${HOST_ARCH}" == "x86_64" ] ; then
   HOST_ARCH_X8664=true
+elif [ "${HOST_ARCH}" == "amd64" ] ; then
+  HOST_ARCH_X8664=true
 elif [ "${HOST_ARCH}" == "armv7l" ] ; then
   HOST_ARCH_ARM=true
 elif [ "${HOST_ARCH}" == "mips32" ] ||
