#include "getResponse.h"

int sock;
struct sockaddr_in client;
int PORT = 80;

std::string getResponse_http(Logger& Log)
{
    struct hostent * host = gethostbyname("google.com");

    if ( (host == NULL) || (host->h_addr == NULL) ) 
    {
        Log.makeMessage(3, std::string(__FUNCTION__));
        
        return "";
    }

    bzero(&client, sizeof(client));
    
    client.sin_family = AF_INET;
    
    client.sin_port = htons( PORT );
    
    memcpy(&client.sin_addr, host->h_addr, host->h_length);
           
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        Log.makeMessage(4, std::string(__FUNCTION__));
        
        return "";
    }
    
    Log.makeMessage(10, std::string(__FUNCTION__));

    if ( connect(sock, (struct sockaddr *)&client, sizeof(client)) < 0 ) 
    {
        close(sock);
        
        Log.makeMessage(7, std::string(__FUNCTION__));
        
        return "";
    }

    std::stringstream ss;
    
    ss << "GET HTTP/1.1\r\n"
       << "Host: google.com\r\n"
       << "\r\n\r\n";
    
    std::string request = ss.str();

    if (send(sock, request.c_str(), request.length(), 0) != (int)request.length()) 
    {
    	close(sock);
    
        Log.makeMessage(9, std::string(__FUNCTION__));
        
        return "";
    }
    
    Log.makeMessage(5, std::string(__FUNCTION__));
    
    char cur;
    
    std::string response;
    
    while ( recv(sock, &cur, 1, 0) > 0 ) 
    {
        response += cur;
    }
    
    Log.makeMessage(6, std::string(__FUNCTION__));
    
    close(sock);
    
    return std::string(response,response.find("Date") + 6, 25);
}
