--- cc/layers/layer_impl.cc.orig	2014-05-30 12:44:05.127127814 -0500
+++ cc/layers/layer_impl.cc	2014-05-30 12:45:47.843117278 -0500
@@ -1215,21 +1215,21 @@
                                scale_factor * scaled_scroll_bounds.height());
   scaled_scroll_bounds = gfx::ToFlooredSize(scaled_scroll_bounds);
 
-  gfx::Vector2dF max_offset(
+  gfx::Vector2dF max_offset_(
       scaled_scroll_bounds.width() - scroll_clip_layer_->bounds().width(),
       scaled_scroll_bounds.height() - scroll_clip_layer_->bounds().height());
   // We need the final scroll offset to be in CSS coords.
-  max_offset.Scale(1 / scale_factor);
-  max_offset.SetToMax(gfx::Vector2dF());
-  return gfx::ToFlooredVector2d(max_offset);
+  max_offset_.Scale(1 / scale_factor);
+  max_offset_.SetToMax(gfx::Vector2dF());
+  return gfx::ToFlooredVector2d(max_offset_);
 }
 
 gfx::Vector2dF LayerImpl::ClampScrollToMaxScrollOffset() {
-  gfx::Vector2dF max_offset = MaxScrollOffset();
+  gfx::Vector2dF max_offset_ = MaxScrollOffset();
   gfx::Vector2dF old_offset = TotalScrollOffset();
   gfx::Vector2dF clamped_offset = old_offset;
 
-  clamped_offset.SetToMin(max_offset);
+  clamped_offset.SetToMin(max_offset_);
   clamped_offset.SetToMax(gfx::Vector2d());
   gfx::Vector2dF delta = clamped_offset - old_offset;
   if (!delta.IsZero())
