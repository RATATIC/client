#include <fstream>
#include <thread>
#include <vector>

#include "getResponse.h"

std::string logger(std::string message)
{
	if(message == "start")
		return "==========Start Program==========\n\n";
	
	if(message == "end")
		return "\n==========End Program==========\n\n";
	
	return "Function " + message + " completed successfully\n" ;
}

void changeDate (std::string& date, std::string& nameOfFunc)
{
    nameOfFunc = std::string(__FUNCTION__);
    
    date[13] += 3;

    date = "sudo date -s \"" + date + "\"";
    
    system (date.c_str());
}

int main(int argc, char** argv)
{
    std::string nameOfFunc;
    
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
    
    std::ofstream out (fileName, std::ios::app);
    
    
    std::vector<std::thread> thr_vec;
    
    auto writeMessage = [&](std::string message)
    {
    	out << message;
    };
    
    thr_vec.push_back(std::thread (writeMessage, logger("start")));

    std::string response = getResponse_http(nameOfFunc);
    
    thr_vec[thr_vec.size() - 1].join();    
    thr_vec.push_back(std::thread (writeMessage, logger(nameOfFunc)));

    std::string date (response, response.find("Date", 0) + 11, 20);

    changeDate(date, nameOfFunc);
    
    thr_vec[thr_vec.size() - 1].join();
    thr_vec.push_back(std::thread (writeMessage, logger(nameOfFunc)));

    getResponse_https(nameOfFunc);
    
    thr_vec[thr_vec.size() - 1].join();
    thr_vec.push_back(std::thread (writeMessage, logger(nameOfFunc)));
    
    thr_vec[thr_vec.size() - 1].join();
    thr_vec.push_back(std::thread (writeMessage, logger("end")));
    
    for(auto& it : thr_vec)
    {
    	if(it.joinable())
    	{
    		it.join();
    	}
    }
}
