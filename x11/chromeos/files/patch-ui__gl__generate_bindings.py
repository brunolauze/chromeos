--- ui/gl/generate_bindings.py.orig	2014-06-07 11:11:04.160437922 -0500
+++ ui/gl/generate_bindings.py	2014-06-07 11:14:26.720423177 -0500
@@ -1325,6 +1325,9 @@
   file.write("struct Extensions%s {\n" % set_name.upper())
   for extension in sorted(used_extensions):
     file.write('  bool b_%s;\n' % extension)
+  
+  file.write('    bool b_GL_ARB_sync;\n');
+  file.write('    bool b_GL_ARB_timer_query;\n');
   file.write('};\n')
   file.write('\n')
 
@@ -1494,6 +1497,8 @@
     # as a separator
     file.write('  ext.b_%s = extensions.find("%s ") != std::string::npos;\n' %
         (extension, extension))
+    file.write('  ext.b_GL_ARB_sync = extensions.find("GL_ARB_sync ") != std::string::npos;\n');
+    file.write('  ext.b_GL_ARB_timer_query = extensions.find("GL_ARB_timer_query ") != std::string::npos;\n');
 
   def WrapOr(cond):
     if ' || ' in cond:
