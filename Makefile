IBOOST=-I /opt/local/include 
LBOOST=-L /opt/local/lib -lboost_system -lboost_thread -pthread  

all : main

main : main.o getResponse.o
	g++ $(LBOOST) main.o getResponse.o -o main

main.o : main.cpp
	g++ -c main.cpp

getResponse.o : getResponse_http.cpp
	g++ $(IBOOST) -c getResponse_http.cpp

clean :
	rm -rf *.o hello
