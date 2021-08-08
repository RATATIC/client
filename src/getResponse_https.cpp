#include "getResponse.h"

void getResponse_https(std::ofstream& out)
{
	std::vector<std::thread> thr_vec;
    
	thr_vec.reserve(5);
	
	auto writeInFile = [&](const std::string& message, bool successful, bool function)
    	{
   		if(thr_vec.size() > 0)
  		{
     		      if(thr_vec[thr_vec.size() - 1].joinable())
    			{
		    		thr_vec[thr_vec.size() - 1].join();
    			}
    		}
    		thr_vec.push_back(std::thread(writeLogInFile, std::ref(out), logger(message, successful, function)));
    	};
	
	writeInFile("Begin " + std::string (__FUNCTION__), false, false);
	
	CURL *curl;
	
	CURLcode res;
	
	curl = curl_easy_init();
	
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
		
		writeInFile("Try connection to example.com", false, false);
			
		res = curl_easy_perform(curl);
		
		writeInFile("Connection", true, false);
		
		curl_easy_cleanup(curl);
		
		writeInFile("Close connection", true, false);
	}
	
	writeInFile(std::string (__FUNCTION__), false, true);
	
	for(auto& it : thr_vec)
    	{
    		if(it.joinable())
    		{
    			it.join();
    		}
    	}
}
