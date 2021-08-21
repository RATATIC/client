    #pragma once

    #include <iostream>
    #include <thread>
    #include <chrono>
    #include <fstream>
    #include <mutex>
    #include <condition_variable>
    #include <queue>

    class Logger
    {
    public:
    Logger(const char*);
    
     ~Logger();

    void makeMessage(int);

    void makeMessage(int, const std::string);

    void writeInFile();

    void changework_main();

    private:
    std::ofstream out;

    std::queue<std::string> log_list;

    bool work_main;
    };


