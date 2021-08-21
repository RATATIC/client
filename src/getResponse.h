#pragma once

#include <curl/curl.h>

#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>

#include "Logger.h"

std::string getResponse_http(Logger& Log);

void getResponse_https(Logger& Log);
