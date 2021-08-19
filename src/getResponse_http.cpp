#include "getResponse.h"

namespace http = boost::beast::http;

std::string getResponse_http(Logger& Log)
{
    try
    {
    
    const std::string host = "google.com";
    const std::string target = "";

    boost::asio::io_context io;
    boost::asio::ip::tcp::resolver resolver(io);
    boost::asio::ip::tcp::socket socket(io);

    Log.makeMessage(3, std::string(__FUNCTION__));

    boost::asio::connect(socket, resolver.resolve(host, "80"));
    
    Log.makeMessage(4, std::string(__FUNCTION__));
    
    http::request<http::string_body> req(http::verb::get, target, 11);

    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    
    http::write(socket, req);
    
    std::string response ;
    {
    boost::beast::flat_buffer buffer;
    http::response<http::dynamic_body> res;
    
    Log.makeMessage(5, std::string(__FUNCTION__));
    
    http::read(socket, buffer, res);
    
    for(auto& it : res.base())
    {
    	if(it.name_string() == "Date")
    	{
    	    response = std::string(it.value().to_string(), 6, 19);
    	}
    }
    };
    
    Log.makeMessage(6, std::string(__FUNCTION__));

    socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
    
    return response;
    
    }
    catch(...)
    {
    Log.makeMessage(7, std::string(__FUNCTION__));
    
    return "";
    }
}
