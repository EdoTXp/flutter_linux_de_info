/**
 * @file flutter_linux_de_info_plugin.cc
 * @brief Implements the native Linux side of the flutter_linux_de_info plugin.
 * This file uses the GObject type system for its structure and lifecycle,
 * which is the standard for GTK and Flutter Linux plugins.
 */
#include "include/flutter_linux_de_info/flutter_linux_de_info_plugin.h"
#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>
#include <string>
#include <cstdlib>

#define FLUTTER_LINUX_DE_INFO_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), flutter_linux_de_info_plugin_get_type(), FlutterLinuxDEInfoPlugin))

/**
 * @brief The private data structure for the FlutterLinuxDEInfoPlugin.
 */
struct _FlutterLinuxDEInfoPlugin
{
  GObject parent_instance;
};

G_DEFINE_TYPE(FlutterLinuxDEInfoPlugin, flutter_linux_de_info_plugin, g_object_get_type())

/**
 * @brief Handles method calls from the Flutter side of the plugin.
 * @param self A #FlutterLinuxDEInfoPlugin instance.
 * @param method_call The method call to handle, received from Flutter.
 *
 * This function is the primary entry point for logic when a method is invoked
 * from the Dart code. It deciphers the method name and executes the
 * corresponding native code.
 *
 * It currently handles the "getDesktopEnvironment" method, which retrieves the
 * value of the `XDG_CURRENT_DESKTOP` environment variable. If the variable is
 * not set, it returns "Unknown". The result is then sent back to the Flutter
 * side as a success response. For any other method name, it responds with a
 * "Not Implemented" error.
 */
static void flutter_linux_de_info_plugin_handle_method_call(
    FlutterLinuxDEInfoPlugin *self,
    FlMethodCall *method_call)
{
  const gchar *method = fl_method_call_get_name(method_call);

  if (strcmp(method, "getDesktopEnvironment") == 0)
  {
    const char *desktop = std::getenv("XDG_CURRENT_DESKTOP");
    std::string result = desktop ? desktop : "Unknown";

    g_autoptr(FlValue) response = fl_value_new_string(result.c_str());
    fl_method_call_respond_success(method_call, response, nullptr);
  }
  else
  {
    fl_method_call_respond_not_implemented(method_call, nullptr);
  }
}

/**
 * @brief The dispose function for the plugin instance.
 * @param object The GObject to dispose.
 *
 * This function is called when the plugin instance is being finalized (i.e.,
 * its reference count has dropped to zero). It's the place to clean up
 * any resources allocated by this specific instance. It must chain up to the
 * parent class's dispose function to ensure proper cleanup.
 */
static void flutter_linux_de_info_plugin_dispose(GObject *object)
{
  G_OBJECT_CLASS(flutter_linux_de_info_plugin_parent_class)->dispose(object);
}

/**
 * @brief The class initialization function for the plugin.
 * @param klass The #FlutterLinuxDEInfoPluginClass to initialize.
 *
 * This function is called once to set up the class, including connecting
 * the dispose function.
 */
static void flutter_linux_de_info_plugin_class_init(FlutterLinuxDEInfoPluginClass *klass)
{
  G_OBJECT_CLASS(klass)->dispose = flutter_linux_de_info_plugin_dispose;
}

/**
 * @brief The instance initialization function for the plugin.
 * @param self The #FlutterLinuxDEInfoPlugin instance to initialize.
 */
static void flutter_linux_de_info_plugin_init(FlutterLinuxDEInfoPlugin *self) {}

FLUTTER_PLUGIN_EXPORT void flutter_linux_de_info_plugin_register_with_registrar(FlPluginRegistrar *registrar)
{
  FlStandardMethodCodec *codec = fl_standard_method_codec_new();
  FlMethodChannel *channel = fl_method_channel_new(
      fl_plugin_registrar_get_messenger(registrar),
      "flutter_linux_de_info",
      FL_METHOD_CODEC(codec));

  FlutterLinuxDEInfoPlugin *plugin = FLUTTER_LINUX_DE_INFO_PLUGIN(
      g_object_new(flutter_linux_de_info_plugin_get_type(), nullptr));

  // Set the method call handler for the channel.
  // A lambda function is used here to capture the plugin instance.
  // g_object_ref and g_object_unref are used to manage the lifecycle of the
  // plugin object, ensuring it stays alive as long as the channel exists.
  fl_method_channel_set_method_call_handler(channel, [](FlMethodChannel *channel, FlMethodCall *call, gpointer user_data)
                                            { flutter_linux_de_info_plugin_handle_method_call(
                                                  FLUTTER_LINUX_DE_INFO_PLUGIN(user_data), call); },

                                            g_object_ref(plugin), g_object_unref);

  // The plugin object is no longer needed in this scope, so unref it.
  // The method channel now holds a reference, so the object won't be destroyed.
  g_object_unref(plugin);
}