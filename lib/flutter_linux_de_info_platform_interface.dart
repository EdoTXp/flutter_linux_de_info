import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'flutter_linux_de_info_method_channel.dart';

abstract class FlutterLinuxDeInfoPlatform extends PlatformInterface {
  /// Constructs a FlutterLinuxDeInfoPlatform.
  FlutterLinuxDeInfoPlatform() : super(token: _token);

  static final Object _token = Object();

  static FlutterLinuxDeInfoPlatform _instance = MethodChannelFlutterLinuxDeInfo();

  /// The default instance of [FlutterLinuxDeInfoPlatform] to use.
  ///
  /// Defaults to [MethodChannelFlutterLinuxDeInfo].
  static FlutterLinuxDeInfoPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [FlutterLinuxDeInfoPlatform] when
  /// they register themselves.
  static set instance(FlutterLinuxDeInfoPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
