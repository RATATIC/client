#pragma once

#include <curl/curl.h>

#include <boost/beast.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "Logger.h"

std::string getResponse_http(Logger& Log);

void getResponse_https(Logger& Log);
