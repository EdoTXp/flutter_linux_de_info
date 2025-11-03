#ifndef FLUTTER_PLUGIN_FLUTTER_LINUX_DE_INFO_PLUGIN_H_
#define FLUTTER_PLUGIN_FLUTTER_LINUX_DE_INFO_PLUGIN_H_

#include <flutter_linux/flutter_linux.h>

G_BEGIN_DECLS

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

G_DECLARE_FINAL_TYPE(FlutterLinuxDEInfoPlugin, flutter_linux_de_info_plugin, FLUTTER_LINUX_DE_INFO, PLUGIN, GObject)

FLUTTER_PLUGIN_EXPORT void flutter_linux_de_info_plugin_register_with_registrar(
    FlPluginRegistrar* registrar);

G_END_DECLS

#endif  // FLUTTER_PLUGIN_FLUTTER_LINUX_DE_INFO_PLUGIN_H_