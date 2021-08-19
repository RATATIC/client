#include "getResponse.h"

void getResponse_https(Logger& Log)
{
	CURL *curl;
	
	CURLcode res;
	
	curl = curl_easy_init();
	
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
		
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
		
		Log.makeMessage(8, std::string(__FUNCTION__));
			
		res = curl_easy_perform(curl);
		
		curl_easy_cleanup(curl);
			
		Log.makeMessage(6, std::string(__FUNCTION__));
	}
}
