#include "getResponse.h"

static std::size_t consoleWrite(char* data, std::size_t size, std::size_t nmemb, void* userp)
{
	std::size_t realsize = size * nmemb;
	
	std::string readBuffer;
	
	readBuffer.append(data, realsize);
	
	std::cout  << std::endl << readBuffer ; 
	
	return realsize;
}


void getResponse_https(Logger& Log)
{
	CURL *curl;
	
	CURLcode res;
	
	curl = curl_easy_init();
	
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
		
		//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);  
		
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, consoleWrite);
		
		Log.makeMessage(8, std::string(__FUNCTION__));
			
		res = curl_easy_perform(curl);
		
		curl_easy_cleanup(curl);
			
		Log.makeMessage(6, std::string(__FUNCTION__));
	}
}
