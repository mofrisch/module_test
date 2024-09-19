// file: ./main.cpp

import log;

Log &my_log=Log::instance();

auto main() -> int {
    my_log.setLogLevel(LogLevel::Debug);
    my_log.log(LogLevel::Debug, "Debug message");
    my_log.log(LogLevel::Info, "Info message");
    my_log.log(LogLevel::Warning, "Warning message");
    my_log.log(LogLevel::Error, "Error message");
    return 0;
}
