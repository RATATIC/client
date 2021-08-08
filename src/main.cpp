#include "getResponse.h"

void changeDate (std::string date)
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
    
    std::ofstream out (fileName, std::ios::app);
        
    std::vector<std::thread> thr_vec;
    
    thr_vec.reserve(2);

    auto writeInFile = [&](std::string message, bool successful, bool function) 
    {
    if(thr_vec.size() > 0)
    {
        if(thr_vec[thr_vec.size() - 1].joinable())
    	{
    		thr_vec[thr_vec.size() - 1].join();
    	}
    }
    
    thr_vec.push_back(std::thread (writeLogInFile, std::ref(out), logger(message, successful, function)));
    };
    
    writeInFile("start", false, false); // writeLogInFile("start", false, false);
    thr_vec[thr_vec.size() - 1].join();
    
    std::string response = getResponse_http(out);

    changeDate(std::string (response, response.find("Date", 0) + 11, 20));

    getResponse_https(out);
    
    writeInFile("end", false, false);
    
    for(auto& it : thr_vec)
    {
    	if(it.joinable())
    	{
    		it.join();
    	}
    }
    
    out.close();
}
