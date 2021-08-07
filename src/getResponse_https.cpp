#include "getResponse.h"

void getResponse_https(std::string& nameOfFunc)
{
	nameOfFunc = std::string(__FUNCTION__);

	CURL *curl;
	
	CURLcode res;
	
	curl = curl_easy_init();
	
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
		
		res = curl_easy_perform(curl);
		
		curl_easy_cleanup(curl);
	}
}
