--- chromeos/dbus/nfc_adapter_client.cc.orig	2014-06-03 15:58:38.390422993 -0500
+++ chromeos/dbus/nfc_adapter_client.cc	2014-06-03 17:15:13.799105813 -0500
@@ -16,6 +16,42 @@
 #include "dbus/message.h"
 #include "third_party/cros_system_api/dbus/service_constants.h"
 
+
+/* With shared librairies this specialization get missing. TODO: Review */
+namespace dbus {
+
+//
+// Property<std::vector<uint8> > specialization.
+//
+
+template <>
+bool Property<std::vector<uint8> >::PopValueFromReader(MessageReader* reader) {
+  MessageReader variant_reader(NULL);
+  if (!reader->PopVariant(&variant_reader))
+    return false;
+
+  value_.clear();
+  const uint8* bytes = NULL;
+  size_t length = 0;
+  if (!variant_reader.PopArrayOfBytes(&bytes, &length))
+    return false;
+  value_.assign(bytes, bytes + length);
+  return true;
+}
+
+template <>
+void Property<std::vector<uint8> >::AppendSetValueToWriter(
+    MessageWriter* writer) {
+  MessageWriter variant_writer(NULL);
+  writer->OpenVariant("ay", &variant_writer);
+  variant_writer.AppendArrayOfBytes(set_value_.data(), set_value_.size());
+  writer->CloseContainer(&variant_writer);
+}
+
+}
+
+
+
 namespace chromeos {
 
 NfcAdapterClient::Properties::Properties(
