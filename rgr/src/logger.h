#pragma once
#include <string>
void log_init(const std::string& file );
void log_error(const std::string& msg );
void log_warning(const std::string& msg);
void log_info(const std::string& msg);
void log_close();