#include <iostream>

#include <curl/curl.h>

#include <boost/beast.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

std::string getResponse_http();

void getResponse_https();
