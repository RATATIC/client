#include "getResponse.h"

std::mutex mtx;


std::string logger (const std::string& message, const bool& successful,const bool& function)
{
	if(message == "start")
		return "==========Start Program==========\n\n";
	
	if(message == "end")
		return "==========End Program==========\n\n";
	
	if(function)
		return "Function " + message + " completed successfully\n\n" ;
		
	if(successful)
		return message + " successful\n";
		
	return message + "\n";
}

void writeLogInFile(std::ofstream& out,const std::string message)
{
	mtx.lock();
	
	out << message;
	
	mtx.unlock();
}
