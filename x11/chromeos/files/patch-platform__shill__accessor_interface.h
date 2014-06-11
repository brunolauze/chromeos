--- platform/shill/accessor_interface.h.orig	2014-06-09 14:46:40.085275374 -0500
+++ platform/shill/accessor_interface.h	2014-06-09 14:47:28.733308762 -0500
@@ -60,27 +60,27 @@
 
 // Using a smart pointer here allows pointers to classes derived from
 // AccessorInterface<> to be stored in maps and other STL container types.
-typedef std::tr1::shared_ptr<AccessorInterface<bool>> BoolAccessor;
-typedef std::tr1::shared_ptr<AccessorInterface<int16>> Int16Accessor;
-typedef std::tr1::shared_ptr<AccessorInterface<int32>> Int32Accessor;
+typedef std::shared_ptr<AccessorInterface<bool>> BoolAccessor;
+typedef std::shared_ptr<AccessorInterface<int16>> Int16Accessor;
+typedef std::shared_ptr<AccessorInterface<int32>> Int32Accessor;
 // See comment above RpcIdentifiers typedef, for the reason why the
 // RpcIdentifiersAccessor exists (even though it has the same
 // underlying type as StringsAccessor).
-typedef std::tr1::shared_ptr<
+typedef std::shared_ptr<
     AccessorInterface<RpcIdentifier>> RpcIdentifierAccessor;
-typedef std::tr1::shared_ptr<
+typedef std::shared_ptr<
     AccessorInterface<std::vector<std::string>>>RpcIdentifiersAccessor;
-typedef std::tr1::shared_ptr<AccessorInterface<std::string>> StringAccessor;
-typedef std::tr1::shared_ptr<AccessorInterface<Stringmap>> StringmapAccessor;
-typedef std::tr1::shared_ptr<AccessorInterface<Stringmaps>> StringmapsAccessor;
-typedef std::tr1::shared_ptr<AccessorInterface<Strings>> StringsAccessor;
-typedef std::tr1::shared_ptr<
+typedef std::shared_ptr<AccessorInterface<std::string>> StringAccessor;
+typedef std::shared_ptr<AccessorInterface<Stringmap>> StringmapAccessor;
+typedef std::shared_ptr<AccessorInterface<Stringmaps>> StringmapsAccessor;
+typedef std::shared_ptr<AccessorInterface<Strings>> StringsAccessor;
+typedef std::shared_ptr<
     AccessorInterface<KeyValueStore>> KeyValueStoreAccessor;
-typedef std::tr1::shared_ptr<AccessorInterface<uint8>> Uint8Accessor;
-typedef std::tr1::shared_ptr<AccessorInterface<uint16>> Uint16Accessor;
-typedef std::tr1::shared_ptr<AccessorInterface<Uint16s>> Uint16sAccessor;
-typedef std::tr1::shared_ptr<AccessorInterface<uint32>> Uint32Accessor;
-typedef std::tr1::shared_ptr<AccessorInterface<uint64>> Uint64Accessor;
+typedef std::shared_ptr<AccessorInterface<uint8>> Uint8Accessor;
+typedef std::shared_ptr<AccessorInterface<uint16>> Uint16Accessor;
+typedef std::shared_ptr<AccessorInterface<Uint16s>> Uint16sAccessor;
+typedef std::shared_ptr<AccessorInterface<uint32>> Uint32Accessor;
+typedef std::shared_ptr<AccessorInterface<uint64>> Uint64Accessor;
 
 }  // namespace shill
 
