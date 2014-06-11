--- mojo/shell/desktop/mojo_main.cc.orig	2014-06-08 14:31:23.122810060 -0500
+++ mojo/shell/desktop/mojo_main.cc	2014-06-08 14:34:38.183852322 -0500
@@ -14,6 +14,55 @@
 #include "mojo/shell/switches.h"
 #include "ui/gl/gl_surface.h"
 
+
+#include "mojo/environment/default_async_waiter_impl.h"
+
+#include "base/bind.h"
+#include "mojo/common/handle_watcher.h"
+
+namespace mojo {
+namespace internal {
+namespace {
+
+void OnHandleReady(common::HandleWatcher* watcher,
+                   MojoAsyncWaitCallback callback,
+                   void* closure,
+                   MojoResult result) {
+  delete watcher;
+  callback(closure, result);
+}
+
+MojoAsyncWaitID AsyncWait(MojoAsyncWaiter* waiter,
+                          MojoHandle handle,
+                          MojoWaitFlags flags,
+                          MojoDeadline deadline,
+                          MojoAsyncWaitCallback callback,
+                          void* closure) {
+  // This instance will be deleted when done or cancelled.
+  common::HandleWatcher* watcher = new common::HandleWatcher();
+  watcher->Start(Handle(handle), flags, deadline,
+                 base::Bind(&OnHandleReady, watcher, callback, closure));
+  return reinterpret_cast<MojoAsyncWaitID>(watcher);
+}
+
+void CancelWait(MojoAsyncWaiter* waiter, MojoAsyncWaitID wait_id) {
+  delete reinterpret_cast<common::HandleWatcher*>(wait_id);
+}
+
+MojoAsyncWaiter s_default_async_waiter = {
+  AsyncWait,
+  CancelWait
+};
+
+}  // namespace
+
+MojoAsyncWaiter* GetDefaultAsyncWaiterImpl() {
+  return &s_default_async_waiter;
+}
+
+}  // namespace internal
+}  // namespace mojo
+
 int main(int argc, char** argv) {
   base::AtExitManager at_exit;
   mojo::Environment env;
