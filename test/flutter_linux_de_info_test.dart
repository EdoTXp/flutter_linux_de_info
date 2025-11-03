import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';
import 'package:flutter_linux_de_info/flutter_linux_de_info.dart';
import 'package:flutter_test/flutter_test.dart';

void main() {
  TestWidgetsFlutterBinding.ensureInitialized();

  const MethodChannel channel = MethodChannel('flutter_linux_de_info');
  final FlutterLinuxDeInfo flutterLinuxDeInfo = FlutterLinuxDeInfo();
  final messengerBinding = TestDefaultBinaryMessengerBinding.instance;

  setUp(() {
    debugDefaultTargetPlatformOverride = TargetPlatform.linux;

    messengerBinding.defaultBinaryMessenger.setMockMethodCallHandler(channel, (
      MethodCall methodCall,
    ) async {
      if (debugDefaultTargetPlatformOverride == TargetPlatform.linux) {
        if (methodCall.method == 'getDesktopEnvironment') {
          return 'XFCE';
        }
      } else {
        throw PlatformException(
          code: 'UNSUPPORTED_PLATFORM',
          message:
              'getDesktopEnvironment is only supported on Linux platforms.',
        );
      }
      return null;
    });
  });

  tearDown(() {
    messengerBinding.defaultBinaryMessenger.setMockMethodCallHandler(
      channel,
      null,
    );
    debugDefaultTargetPlatformOverride = null;
  });

  group('Test if Plugin FlutterLinuxDeInfo works', () {
    test('getDesktopEnvironment returns a String', () async {
      final de = await flutterLinuxDeInfo.getDesktopEnvironment();
      expect(de, 'XFCE');
    });

    test(
      'getDesktopEnvironment on non-Linux throws UnsupportedError',
      () async {
        debugDefaultTargetPlatformOverride = TargetPlatform.windows;
        expect(
          () async => await flutterLinuxDeInfo.getDesktopEnvironment(),
          throwsA(isA<PlatformException>()),
        );
      },
    );
  });
}
