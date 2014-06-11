--- net/url_request/url_fetcher_core.cc.orig	2014-06-05 16:52:01.532972238 -0500
+++ net/url_request/url_fetcher_core.cc	2014-06-05 17:14:56.958876938 -0500
@@ -103,8 +103,10 @@
   DCHECK(delegate_task_runner_.get());
   DCHECK(request_context_getter_.get()) << "We need an URLRequestContext!";
   if (network_task_runner_.get()) {
+#if !defined(OS_FREEBSD)
     DCHECK_EQ(network_task_runner_,
               request_context_getter_->GetNetworkTaskRunner());
+#endif
   } else {
     network_task_runner_ = request_context_getter_->GetNetworkTaskRunner();
   }
