import 'package:flutter/material.dart';
import 'package:flutter_linux_de_info/flutter_linux_de_info.dart';

void main() {
  runApp(const MaterialApp(home: HomePage()));
}

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  String _de = 'Carregando...';

  @override
  void initState() {
    super.initState();
    _loadDE();
  }

  Future<void> _loadDE() async {
    final env = await FlutterLinuxDeInfo.getDesktopEnvironment();
    setState(() => _de = env);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Desktop Environment Info')),
      body: Center(child: Text('DE atual: $_de')),
    );
  }
}
