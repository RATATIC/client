    #include "Logger.h"

    std::mutex change_message;
    std::condition_variable message_check;

    Logger::Logger(const char* fileName)
    {
    out = std::ofstream(fileName, std::ios::app);
    }

    Logger::~Logger()
    {
    out.close();
    }

    void Logger::makeMessage(const int numberMessage)
    {
    std::unique_lock<std::mutex> locker(change_message);

    switch (numberMessage)
    {
    case 1 :
    log_list.push("\n===== Start Program =====\n\n");
    break;
    case 2 :
    log_list.push("\n===== End Program =====\n");
    changework_main();
    break;
    }

    message_check.notify_one();
    }

    void Logger::makeMessage(const int numberMessage, const std::string functionName)
    {
    std::unique_lock<std::mutex> locker(change_message);

    switch (numberMessage)
    {
    case 3:
    log_list.push(functionName + ": try connection\n");
    break;
    
    case 4:
    log_list.push(functionName + ": connection successful\n");
    break;
    
    case 5:
    log_list.push(functionName + ": get response\n");
    break;
    
    case 6:
    log_list.push(functionName + ": close connection\n");
    break;
    
    case 7:
    log_list.push(functionName + ": error\n");
    break;
    
    case 8:
    log_list.push(functionName + ": try connection and getting response\n");
    break;
    }

    message_check.notify_one();
    }

    void Logger::writeInFile()
    {
    while(!work_main)
    {
	std::unique_lock<std::mutex> locker(change_message);
	
	message_check.wait(locker);
	
    	while (!log_list.empty())
    	{
    		out << log_list.front();
   		log_list.pop();
    	}
    }
    while (!log_list.empty())
    	{
    		out << log_list.front();
   		log_list.pop();
    	}
    }

    void Logger::changework_main()
    {
    work_main = true;
    }


