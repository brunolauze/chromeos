--- content/renderer/accessibility/blink_ax_tree_source.cc.orig	2014-06-03 07:41:49.719475202 -0500
+++ content/renderer/accessibility/blink_ax_tree_source.cc	2014-06-03 07:42:52.994471919 -0500
@@ -441,13 +441,13 @@
     dst->AddIntAttribute(ui::AX_ATTR_SCROLL_X, scroll_offset.width());
     dst->AddIntAttribute(ui::AX_ATTR_SCROLL_Y, scroll_offset.height());
 
-    const gfx::Size& min_offset = document.frame()->minimumScrollOffset();
-    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_X_MIN, min_offset.width());
-    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_Y_MIN, min_offset.height());
-
-    const gfx::Size& max_offset = document.frame()->maximumScrollOffset();
-    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_X_MAX, max_offset.width());
-    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_Y_MAX, max_offset.height());
+    const gfx::Size& min_offset_ = document.frame()->minimumScrollOffset();
+    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_X_MIN, min_offset_.width());
+    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_Y_MIN, min_offset_.height());
+
+    const gfx::Size& max_offset_ = document.frame()->maximumScrollOffset();
+    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_X_MAX, max_offset_.width());
+    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_Y_MAX, max_offset_.height());
   }
 
   if (dst->role == ui::AX_ROLE_TABLE) {
