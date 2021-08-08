#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

#include <curl/curl.h>

#include <boost/beast.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

std::string logger(const std::string&, const bool&,const bool&);

void writeLogInFile(std::ofstream&, const std::string);

std::string getResponse_http(std::ofstream&);

void getResponse_https(std::ofstream&);
