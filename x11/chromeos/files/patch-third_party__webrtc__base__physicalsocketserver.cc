--- third_party/webrtc/base/physicalsocketserver.cc.orig	2014-05-30 11:17:56.132479121 -0500
+++ third_party/webrtc/base/physicalsocketserver.cc	2014-05-30 11:20:33.981469556 -0500
@@ -240,7 +240,7 @@
     socklen_t optlen = sizeof(*value);
     int ret = ::getsockopt(s_, slevel, sopt, (SockOptArg)value, &optlen);
     if (ret != -1 && opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
       *value = (*value != IP_PMTUDISC_DONT) ? 1 : 0;
 #endif
     }
@@ -253,7 +253,7 @@
     if (TranslateOption(opt, &slevel, &sopt) == -1)
       return -1;
     if (opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
       value = (value) ? IP_PMTUDISC_DO : IP_PMTUDISC_DONT;
 #endif
     }
@@ -262,7 +262,7 @@
 
   int Send(const void *pv, size_t cb) {
     int sent = ::send(s_, reinterpret_cast<const char *>(pv), (int)cb,
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
         // Suppress SIGPIPE. Without this, attempting to send on a socket whose
         // other end is closed will result in a SIGPIPE signal being raised to
         // our process, which by default will terminate the process, which we
@@ -288,7 +288,7 @@
     size_t len = addr.ToSockAddrStorage(&saddr);
     int sent = ::sendto(
         s_, static_cast<const char *>(buffer), static_cast<int>(length),
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
         // Suppress SIGPIPE. See above for explanation.
         MSG_NOSIGNAL,
 #else
@@ -503,7 +503,7 @@
         *slevel = IPPROTO_IP;
         *sopt = IP_DONTFRAGMENT;
         break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD) || defined(__native_client__)
         LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
         return -1;
 #elif defined(WEBRTC_POSIX)
