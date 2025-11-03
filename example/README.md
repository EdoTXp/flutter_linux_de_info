# Example for flutter_linux_de_info

This project demonstrates the usage of the `flutter_linux_de_info` plugin. It showcases how to retrieve and display the current Linux Desktop Environment using the plugin's `getDesktopEnvironment()` method.

## How to Run

To run this example application:

1. Navigate to the `example/` directory in your terminal:

   ```bash
   cd example/
   ```

2. Get the project dependencies:

   ```bash
   flutter pub get
   ```

3. Run the application on your Linux desktop:

   ```bash
   flutter run -d linux
   ```

The application will display the detected Desktop Environment (e.g., GNOME, KDE, XFCE) or "Unknown" if it cannot be determined.

## Key Files

- `lib/main.dart`: The main entry point of the example application, demonstrating the plugin's usage.
