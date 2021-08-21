all : main

main : main.o getResponse_http.o getResponse_https.o Logger.o
	g++ -pthread main.o getResponse_http.o getResponse_https.o Logger.o -o main -lcurl

main.o : main.cpp
	g++ -c main.cpp

getResponse_http.o : getResponse_http.cpp
	g++ -c getResponse_http.cpp
	
getResponse_https.o : getResponse_https.cpp
	g++ -c getResponse_https.cpp -lcurl
	
Logger.o : Logger.cpp
	g++ -c Logger.cpp

clean :
	rm -rf *.o main
