#include <iostream> 
#include <fstream>
#include <ctime>
#include <string>

static std::ofstream logfile;

void log_init(const std::string& file) {
    logfile.open(file, std::ios::app);
}

static void write_log(const std::string& level, const std::string& msg) {
    if (logfile.is_open() == 0) {
        return;
    }

    time_t now = time(NULL);
    std::string time_str = ctime(&now);
    time_str.pop_back();

    logfile << '[' << time_str << ']' << '[' << level << ']' << msg << std::endl;

    if ( level == "ERROR") {
        std::cerr << msg  << std::endl;
    }
}


void log_error(const std::string& msg) {
    write_log("ERROR", msg);
}
void log_warning(const std::string& msg) {
    write_log("WARNING", msg);
}
void log_info(const std::string& msg) {
    write_log("INFO", msg);
}

void log_close( ) {
    if ( logfile.is_open()) {
        logfile.close();
    }
}