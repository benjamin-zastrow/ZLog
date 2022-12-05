#ifndef ZLOG_H
#define ZLOG_H
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm>

class ZLog
{
public:
    ZLog(bool logFileFlag);
    ~ZLog();
private:
    std::ofstream filestream;
    bool logFile;
    std::string getCurrentTimestamp();
};

#endif // ZLOG_H
