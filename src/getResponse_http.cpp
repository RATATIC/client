#include "getResponse.h"

namespace http = boost::beast::http;

std::string getResponse_http(std::ofstream& out)
{
    std::vector<std::thread> thr_vec;
    
    thr_vec.reserve(7);
    
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

    const std::string host = "google.com";
    const std::string target = "";

    boost::asio::io_context io;
    boost::asio::ip::tcp::resolver resolver(io);
    boost::asio::ip::tcp::socket socket(io);

    writeInFile("Try to connection " + host, false, false);

    boost::asio::connect(socket, resolver.resolve(host, "80"));
    
    writeInFile("Connection", true, false);
    
    http::request<http::string_body> req(http::verb::get, target, 11);

    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    
    writeInFile("Sending request", false, false);
    
    http::write(socket, req);
    
    writeInFile("Getting response", false, false);
    
    std::string response ;
    {
    boost::beast::flat_buffer buffer;
    http::response<http::dynamic_body> res;
    http::read(socket, buffer, res);

    std::ostringstream os;

    os <<res;

    response = os.str();
    };

    socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
    
    writeInFile("Close connection", true, false);
    
    for(auto& it : thr_vec)
    {
    	if(it.joinable())
    	{
    		it.join();
    	}
    }
    
    writeInFile(std::string(__FUNCTION__), false, true);
    
    for(auto& it : thr_vec)
    {
    	if(it.joinable())
    	{
    	it.join();
    	}
    }
    
    return response;
}
