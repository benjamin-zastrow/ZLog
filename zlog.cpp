#include "zlog.h"

ZLog::ZLog(bool logFileFlag)
{
    if(logFileFlag == true) {
        // open logfile for writing
        logFile = true;

        std::string filename = "LOG-" + getCurrentTimestamp() + ".log";

        filestream.open(filename, std::ios::app);
        if(filestream.good()) {
            std::cout << "[" << getCurrentTimestamp() << "] --- LOGFILE OPENED ---\n";
            filestream << "[" << getCurrentTimestamp() << "] --- LOGFILE OPENED ---\n";
        }
        else {
            std::cout << "[" << getCurrentTimestamp() << "] --- FAILED TO OPEN LOGFILE --> PERFORMING IN CONSOLE-LOG-MODE ONLY ---\n";
        }
    }
    else {
        logFile = false;
    }
}
ZLog::~ZLog()
{
    filestream << "[" << getCurrentTimestamp() << "] --- LOGFILE CLOSED ---\n";
    filestream.close();
}
std::string ZLog::getCurrentTimestamp() {
    std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(p);
    std::string timestamp = std::ctime(&t);
    timestamp.erase(remove(timestamp.begin(), timestamp.end(), ' '), timestamp.end());
    timestamp.erase(remove(timestamp.begin(), timestamp.end(), ':'), timestamp.end());
    timestamp.resize(timestamp.size()-2);


    return timestamp;
}
