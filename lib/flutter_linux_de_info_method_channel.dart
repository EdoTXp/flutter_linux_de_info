import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'flutter_linux_de_info_platform_interface.dart';

/// An implementation of [FlutterLinuxDeInfoPlatform] that uses method channels.
class MethodChannelFlutterLinuxDeInfo extends FlutterLinuxDeInfoPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('flutter_linux_de_info');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }
}
