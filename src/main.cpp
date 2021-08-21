#include "getResponse.h"

void changeDate (std::string& date)
{   
    date = "sudo date -s \"" + date + "\"";
    
    system (date.c_str());
}

int main(int argc, char** argv)
{
    char* fileName;
    
    if(argc == 2)
    {
    	fileName = argv[1];
    }
    else
    {
    	std::cout<< "Enter file name "<<std::endl;
    	std::cin >> fileName;
    }
     
    Logger Log(fileName);

    auto func_log = [&]()
    {
    	Log.writeInFile();
    };
    
    std::thread thr(func_log);
    
    Log.makeMessage(1);
   
    std::string date = getResponse_http(Log);

    if(!date.empty())
    {
    	changeDate(date);
    }
    
    getResponse_https(Log);   
    
    Log.makeMessage(2);
    
    thr.join();
}
