IBOOST = -I /opt/local/include 
LBOOST = -L /opt/local/lib -lboost_system -lboost_thread -pthread  

ICURL = -I /usr/local/include
LCURL = -L /usr/local/lib -lcurl


all : main

main : main.o getResponse_http.o getResponse_https.o logger.o
	g++ $(LBOOST) main.o getResponse_http.o getResponse_https.o logger.o -o main -lcurl

main.o : main.cpp
	g++ -c main.cpp

getResponse_http.o : getResponse_http.cpp
	g++ $(IBOOST) -c getResponse_http.cpp
	
getResponse_https.o : getResponse_https.cpp
	g++ -c getResponse_https.cpp -lcurl
	
logger.o : logger.cpp
	g++ -c logger.cpp

clean :
	rm -rf *.o main
