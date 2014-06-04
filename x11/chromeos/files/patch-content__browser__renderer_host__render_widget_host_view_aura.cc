--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2014-06-03 07:32:54.087513066 -0500
+++ content/browser/renderer_host/render_widget_host_view_aura.cc	2014-06-03 07:33:37.065511100 -0500
@@ -626,7 +626,7 @@
   if (host)
     return reinterpret_cast<gfx::NativeViewId>(host->GetAcceleratedWidget());
 #endif
-  return static_cast<gfx::NativeViewId>(NULL);
+  return reinterpret_cast<gfx::NativeViewId>(NULL);
 }
 
 gfx::NativeViewAccessible RenderWidgetHostViewAura::GetNativeViewAccessible() {
