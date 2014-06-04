--- components/storage_monitor/storage_monitor_freebsd.h.orig	2014-05-30 11:43:05.472372837 -0500
+++ components/storage_monitor/storage_monitor_freebsd.h	2014-05-30 12:04:50.088349571 -0500
@@ -0,0 +1,54 @@
+// Copyright 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+// StorageMonitorFreeBSD processes mount point change events, notifies listeners
+// about the addition and deletion of media devices, and answers queries about
+// mounted devices.
+// StorageMonitorFreeBSD lives on the UI thread, and uses ???
+// the FILE thread to get mount point change events.
+
+#ifndef COMPONENTS_STORAGE_MONITOR_STORAGE_MONITOR_FREEBSD_H_
+#define COMPONENTS_STORAGE_MONITOR_STORAGE_MONITOR_FREEBSD_H_
+
+#include <map>
+#include <string>
+
+#include "base/basictypes.h"
+#include "base/compiler_specific.h"
+#include "base/files/file_path.h"
+#include "base/files/file_path_watcher.h"
+#include "base/memory/scoped_ptr.h"
+#include "base/memory/weak_ptr.h"
+#include "components/storage_monitor/storage_monitor.h"
+#include "content/public/browser/browser_thread.h"
+
+namespace storage_monitor {
+
+class StorageMonitorFreeBSD : public StorageMonitor {
+ public:
+  // Should only be called by browser start up code.
+  // Use StorageMonitor::GetInstance() instead.
+  explicit StorageMonitorFreeBSD();
+  virtual ~StorageMonitorFreeBSD();
+
+  // Must be called for StorageMonitorFreeBSD to work.
+  virtual void Init() OVERRIDE;
+
+  virtual device::MediaTransferProtocolManager*
+      media_transfer_protocol_manager();
+
+ private:
+  // StorageMonitor implementation.
+  virtual bool GetStorageInfoForPath(const base::FilePath& path,
+                                     StorageInfo* device_info) const OVERRIDE;
+
+  scoped_ptr<device::MediaTransferProtocolManager>
+    media_transfer_protocol_manager_;
+
+  DISALLOW_COPY_AND_ASSIGN(StorageMonitorFreeBSD);
+};
+
+} // namespace storage_monitor
+
+#endif  // COMPONENTS_STORAGE_MONITOR_STORAGE_MONITOR_FREEBSD_H_
