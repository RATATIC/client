#include "getResponse.h"

namespace http = boost::beast::http;

std::string getResponse_http(std::string& nameOfFunc)
{
    nameOfFunc = std::string(__FUNCTION__);

    const std::string host = "google.com";
    const std::string target = "";

    boost::asio::io_context io;
    boost::asio::ip::tcp::resolver resolver(io);
    boost::asio::ip::tcp::socket socket(io);

    boost::asio::connect(socket, resolver.resolve(host, "80"));

    http::request<http::string_body> req(http::verb::get, target, 11);

    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    http::write(socket, req);

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

    return response;
}
