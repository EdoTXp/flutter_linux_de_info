import 'package:flutter_test/flutter_test.dart';
import 'package:flutter_linux_de_info/flutter_linux_de_info.dart';
import 'package:flutter_linux_de_info/flutter_linux_de_info_platform_interface.dart';
import 'package:flutter_linux_de_info/flutter_linux_de_info_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockFlutterLinuxDeInfoPlatform
    with MockPlatformInterfaceMixin
    implements FlutterLinuxDeInfoPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final FlutterLinuxDeInfoPlatform initialPlatform = FlutterLinuxDeInfoPlatform.instance;

  test('$MethodChannelFlutterLinuxDeInfo is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelFlutterLinuxDeInfo>());
  });

  test('getPlatformVersion', () async {
    FlutterLinuxDeInfo flutterLinuxDeInfoPlugin = FlutterLinuxDeInfo();
    MockFlutterLinuxDeInfoPlatform fakePlatform = MockFlutterLinuxDeInfoPlatform();
    FlutterLinuxDeInfoPlatform.instance = fakePlatform;

    expect(await flutterLinuxDeInfoPlugin.getPlatformVersion(), '42');
  });
}
