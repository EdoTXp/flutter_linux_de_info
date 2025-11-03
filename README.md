# 🐧 Flutter Linux DE Info

A simple Flutter plugin to get the current Desktop Environment on Linux.

---

## 📝 About This Project

This project began as a personal study to understand the intricacies of building Flutter plugins for the Linux desktop platform. The primary goal was to gain hands-on experience with the native C++ integration and communication bridge provided by Flutter.

The core objectives of this study were:

- **Method Channel Communication:** To master the use of `MethodChannel` for invoking native code from Dart and returning results.
- **Native C++ Implementation:** To write clean, efficient C++ code that integrates with the Linux environment.
- **Plugin Structure:** To understand the standard structure and configuration of a Flutter Linux plugin.
- **Simple, Focused Logic:** To create a minimal and understandable example that serves as a solid foundation for more complex plugins.

This plugin is a practical demonstration of these learnings, providing a straightforward utility while serving as a clear educational example.

---

## 🏗️ Architecture & Technologies

The plugin is built with a clear separation between its Dart API and the native Linux implementation, connected by Flutter's platform channel system.

- 🌐 **Core Technologies:**
  - **Dart:** The language for the plugin's public-facing API.
  - **Flutter:** The framework enabling cross-platform development.
  - **C++:** The language used for the native Linux implementation.

- ⚙️ **Key Components:**
  - **MethodChannel:** The communication bridge that allows Dart code to invoke the native C++ function.
  - **GObject:** The underlying type system used for the plugin's structure on the Linux side, following Flutter's recommended practices.

- 🧩 **Principles & Practices:**
  - **Simplicity:** The plugin focuses on a single, well-defined task to keep the implementation clear and easy to follow.
  - **Encapsulation:** The native logic is entirely encapsulated within the C++ implementation, exposing only a clean API to the Dart side.

---

## 🚀 Usage

To use this plugin, add `flutter_linux_de_info` as a dependency in your `pubspec.yaml` file.

Here is an example of how to call the plugin from your Dart code to get the desktop environment string:

```dart
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_linux_de_info/flutter_linux_de_info.dart';

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key});

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  String _desktopEnvironment = 'Loading...';
  final _flutterLinuxDeInfoPlugin = FlutterLinuxDeInfo();

  @override
  void initState() {
    super.initState();
    _getDEInfo();
  }

  Future<void> _getDEInfo() async {
    String de;
    try {
      // Call the plugin's method
      de = await _flutterLinuxDeInfoPlugin.getDesktopEnvironment();
    } on PlatformException catch (e) {
      // The plugin is only supported on Linux.
      de = 'Failed to get DE: ${e.message}';
    }

    if (!mounted) return;

    setState(() {
      _desktopEnvironment = de;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Linux DE Info'),
      ),
      body: Center(
        child: Text(
          'Current Desktop Environment: $_desktopEnvironment',
          style: Theme.of(context).textTheme.headlineMedium,
        ),
      ),
    );
  }
}
```

## How It Works

The plugin's Dart code makes a method call over a `MethodChannel`. The native C++ code on the Linux side listens for this call, retrieves the value of the `XDG_CURRENT_DESKTOP` environment variable, and returns it as a string. If the variable is not set, it returns the default value "Unknown".

---

## 🔄 Future Updates

This README document will be updated if any new features or significant architectural changes are made to the project.

---

## 🙏 Credits & Acknowledgements

- **Author & Maintainer:** Edoardo Fabrizio De Iovanna
