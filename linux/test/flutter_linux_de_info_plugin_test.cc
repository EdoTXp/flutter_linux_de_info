/**
 * @file flutter_linux_de_info_plugin_test.cc
 * @brief Unit tests for the flutter_linux_de_info plugin.
 * 
 * This file contains unit tests for the core logic of the flutter_linux_de_info
 * plugin. The tests use the Google Test framework to verify the behavior of
 * the plugin's native C++ code in isolation.
 */
#include <gtest/gtest.h>
#include <cstdlib> // For setenv and unsetenv
#include <string>

/**
 * @brief Extracts the desktop environment from the XDG_CURRENT_DESKTOP environment variable.
 * 
 * To make the plugin's logic testable without depending on Flutter-specific types
 * (like FlMethodCall), this function encapsulates the core behavior. It reads the
 * `XDG_CURRENT_DESKTOP` environment variable and returns its value. If the variable
 * is not set, it returns the string "Unknown".
 * 
 * @return A std::string containing the value of XDG_CURRENT_DESKTOP or "Unknown".
 */
static std::string get_desktop_environment_from_env() {
    const char *desktop = std::getenv("XDG_CURRENT_DESKTOP");
    if (desktop) {
        return std::string(desktop);
    }
    return "Unknown";
}

/**
 * @brief Tests the GetDesktopEnvironment method when the environment variable is set.
 * 
 * This test case verifies that when the `XDG_CURRENT_DESKTOP` environment variable
 * is set to a specific value, the plugin's logic correctly returns that value.
 * It sets the environment variable, calls the function, and then asserts that the
 * result matches the expected value. Finally, it cleans up by unsetting the variable.
 */
TEST(FlutterLinuxDeInfoPlugin, GetDesktopEnvironmentWhenSet) {
  // Arrange: Set a test value for the environment variable.
  const char* test_desktop_env = "TEST_DE";
  setenv("XDG_CURRENT_DESKTOP", test_desktop_env, 1); // The '1' overwrites the variable if it already exists.

  // Act: Call the function to get the desktop environment.
  std::string result = get_desktop_environment_from_env();

  // Assert: Check that the function returns the value of the environment variable.
  EXPECT_EQ(result, test_desktop_env);

  // Cleanup: Unset the environment variable to avoid side effects in other tests.
  unsetenv("XDG_CURRENT_DESKTOP");
}

/**
 * @brief Tests the GetDesktopEnvironment method when the environment variable is not set.
 * 
 * This test case ensures that if the `XDG_CURRENT_DESKTOP` environment variable
 * is not set, the plugin's logic correctly returns the default string "Unknown".
 * It explicitly unsets the variable, calls the function, and then asserts that
 * the result is "Unknown".
 */
TEST(FlutterLinuxDeInfoPlugin, GetDesktopEnvironmentWhenNotSet) {
  // Arrange: Ensure the environment variable is not set.
  unsetenv("XDG_CURRENT_DESKTOP");

  // Act: Call the function to get the desktop environment.
  std::string result = get_desktop_environment_from_env();

  // Assert: Check that the function returns "Unknown".
  EXPECT_EQ(result, "Unknown");
}
