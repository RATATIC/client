#include "getResponse.h"

int main()
{
    std::string response = getResponse_http();

    std::string date(response, response.find("Date", 0) + 11, 20);
    
    date = "sudo date -s \"" + date + "\"";
    
    system (date.c_str());
    
}
