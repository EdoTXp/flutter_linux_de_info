import 'dart:io';

import 'package:flutter/services.dart';

class FlutterLinuxDeInfo {
  static const MethodChannel _channel = MethodChannel('flutter_linux_de_info');

  /// Returns the current Linux Desktop Environment as a [String].
  /// Possible return values include 'GNOME', 'KDE', 'XFCE', etc.
  static Future<String> getDesktopEnvironment() async {
    if (!Platform.isLinux) {
      throw UnsupportedError(
        'getDesktopEnvironment is only supported on Linux platforms.',
      );
    }

    final String de =
        await _channel.invokeMethod<String>('getDesktopEnvironment') ??
        'Unknown';
    return de;
  }
}
