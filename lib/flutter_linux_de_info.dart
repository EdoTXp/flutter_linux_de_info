
import 'flutter_linux_de_info_platform_interface.dart';

class FlutterLinuxDeInfo {
  Future<String?> getPlatformVersion() {
    return FlutterLinuxDeInfoPlatform.instance.getPlatformVersion();
  }
}
