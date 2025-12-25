CXX = g++
CXXFLAGS = -Wall -Wextra -g3
LDFLAGS = -lws2_32

all: server client

server: server.cpp
	$(CXX) $(CXXFLAGS) server.cpp -o server.exe $(LDFLAGS)

client: client.cppmake.\server.exe
	$(CXX) $(CXXFLAGS) client.cpp -o client.exe $(LDFLAGS)

clean:
	del *.exe
