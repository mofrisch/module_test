// file: greeter.cppm

export module greeter;

import std;

export void greet(std::string_view who) {
  std::println("Hello, {}!", who);
}
