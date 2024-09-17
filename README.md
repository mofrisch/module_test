# Project Structure Documentation

This document provides an overview of the current project structure, including directories and files, with brief explanations of their purposes.

## Directory Layout

# Project Structure Documentation

This document provides an overview of the current project structure, including directories and files, with brief explanations of their purposes.

## Directory Layout

```text
cpp_modules_test/
├── CMakeLists.txt          # Build configuration file
├── include/                # Module interfaces (.cppm files)
│   └── logger.cppm         # Logger module interface unit
├── src/                    # Source files (.cpp files)
│   ├── logger.cpp          # Logger module implementation unit
│   └── main.cpp            # Main application source
├── tests/                  # Test code
│   └── LogTest.cpp         # Unit tests for the logger module
└── doc/                    # Documentation directory
    └── ...                 # Documentation files (e.g., README.md, Doxygen config)
```

## Directories and Files

### **CMakeLists.txt**

- The root CMake configuration file that defines how the project is built.
- Specifies project settings, compiler standards, and build targets for executables and libraries.

### **include/**

- Contains module interface units (`.cppm` files), similar to header files.
- Public interfaces are declared here, making them accessible to other parts of the project.

#### **logger.cppm**

- The module interface for the `logger` module.
- Declares the `Log` class and the `LogLevel` enumeration.

### **src/**

- Contains source files (`.cpp`), including module implementation units and the main application code.

#### **logger.cpp**

- The module implementation unit for the `logger` module.
- Provides definitions for the functions and methods declared in `logger.cppm`.

#### **main.cpp**

- The main application source file.
- Demonstrates the use of the `logger` module.

### **tests/**

- Contains test code, separate from the main application source.
- Utilizes Google Test framework for unit testing.

#### **LogTest.cpp**

- Unit tests for the `logger` module.
- Tests various functionalities of the `Log` class.

### **doc/**

- Contains project documentation.
- May include user guides, developer documentation, and configuration files for documentation generation tools like Doxygen.

## Build and Test Instructions

### **Prerequisites**

- **CMake** version 3.14 or newer.
- A C++ compiler with C++20 module support (e.g., GCC 11+, Clang 10+).
- **Doxygen** (optional) for generating documentation.
- Internet connection (for initial Google Test download via CMake).

### **Building the Project**

1. **Create a build directory and navigate into it:**

   ```bash
   mkdir build
   cd build
   ```

2. **Configure the project using CMake:**

   ```bash
   cmake ..
   ```

3. **Build the project:**

   ```bash
   cmake --build .
   ```

### **Running the Application**

- Execute the main application:

  ```bash
  ./main
  ```

### **Running the Tests**

- Run all tests using CTest:

  ```bash
  ctest
  ```

- Or run the test executable directly:

  ```bash
  ./LogTest
  ```

## Project Configuration Details

### **CMake Configuration**

- **Modules and Libraries:**
    - The `logger` module is added as a static library.
    - Module interface and implementation files are specified.

      ```cmake
      add_library(logger STATIC
          include/logger.cppm
          src/logger.cpp
      )
      ```

- **Executable Targets:**
    - The `main` executable depends on the `logger` module.
    - The `LogTest` executable is set up for testing.

      ```cmake
      add_executable(main src/main.cpp)
      add_executable(LogTest tests/LogTest.cpp)
      ```

- **Compiler Features and Include Directories:**
    - C++20 standard is enforced.
    - The `include/` directory is added to the include paths.

      ```cmake
      target_compile_features(logger PUBLIC cxx_std_20)
      target_include_directories(logger PUBLIC include)
      ```

- **Google Test Integration:**
    - Google Test is fetched using CMake's `FetchContent` module.
    - Tests are linked against `GTest::gtest_main`.

      ```cmake
      FetchContent_Declare(
          googletest
          URL https://github.com/google/googletest/archive/release-1.12.1.zip
      )
      FetchContent_MakeAvailable(googletest)
      ```

- **Testing Support:**
    - Testing is enabled, and tests are added to the build.

      ```cmake
      enable_testing()
      add_test(NAME LogTest COMMAND LogTest)
      ```

### **Module Interface (`include/logger.cppm`)**

- Declares the `Log` class and `LogLevel` enumeration.
- Contains public member functions and variables.

### **Module Implementation (`src/logger.cpp`)**

- Defines the methods declared in `logger.cppm`.
- Implements the singleton pattern and logging functionalities.

## Additional Notes

- **Documentation Generation:**
    - The `doc/` directory is reserved for project documentation.
    - Tools like Doxygen can be used to generate API documentation.

- **Project Practices:**
    - **Modularization:** Utilizes C++20 modules for better encapsulation and compilation times.
    - **Directory Organization:** Separates interfaces, implementations, tests, and documentation for clarity.
    - **Testing:** Employs Test-Driven Development (TDD) principles, writing tests alongside implementation.

- **Compiler Requirements:**
    - Ensure that the chosen compiler fully supports C++20 modules to avoid build issues.

- **Build System:**
    - CMake is used for cross-platform build configuration.
    - The project structure is designed to be scalable and maintainable.

## Getting Started

1. **Clone the Repository:**

   ```bash
   git clone <repository_url>
   cd cpp_modules_test
   ```

2. **Follow the Build and Test Instructions** provided above to set up and verify the project.

## Contributing

- Contributions are welcome. Please follow the project's coding standards and ensure that all tests pass before submitting a pull request.

## License

- This project is licensed under the [MIT License](LICENSE).

---

*This document provides a comprehensive overview of the project's structure and should help new contributors understand the layout and build process.*
```