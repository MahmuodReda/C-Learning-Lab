#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <functional>
#include <cwchar>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>
#include <psdk_inc/_wsadata.h>
#include <minwindef.h>
#include <psdk_inc/_socket_types.h>
#include <psdk_inc/_ip_types.h>
#include <inaddr.h>
#include <c++/15.2.0/bits/basic_string.h>
#include <c++/15.2.0/bits/ranges_base.h>
#include <cstdlib>
int main()
{
    std::cout << "Server starting...\n";

    // 1) init Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed\n";
        return 1;
    }

    // 2) Create socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET)
    {
        std::cerr << "Socket creation failed\n";
        WSACleanup();
        return 1;
    }

    // 3) address setup
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(5000);

    // 4) bind
    if (bind(serverSocket, (sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "Bind failed\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // 5) listen
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cerr << "Listen failed\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server listening on port 5000...\n";
    std::cout << "Client connected!\n";
    int i = 0;
    while (i != 10)

    {

        // 6) accept
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET)
        {
            std::cerr << "Accept failed\n";
            closesocket(serverSocket);
            WSACleanup();
            return 1;
        }

        // 7) recv
        char bufferr[2048];
        int bytesReceived = recv(clientSocket, bufferr, sizeof(bufferr) - 1, 0);
        std::string buffer = bufferr;
        if (bytesReceived > 0)
        {
            buffer[bytesReceived] = '\0';

            std::cout << "----- RAW HTTP REQUEST -----\n";
            std::cout << buffer << "\n";
            std::cout << "----------------------------\n";

            size_t start = buffer.find("GET ") + 4;
            size_t end = buffer.find(" HTTP/1.1", start);
            std::string path = buffer.substr(start, end - start);
            std::cout << path << std::endl;

            if (path == "/open/calc")
            {
                const char *body =
                    "Hallo from C++20 Server\r\n"
                    "(Mahmoud Reda)\r\n";

                std::string response =
                    "HTTP/1.1 200 OK\r\n"
                    "Content-Type: text/plain\r\n"
                    "Content-Length: " +
                    std::to_string(strlen(body)) + "\r\n"
                                                   "\r\n" +
                    std::string(body);

                send(clientSocket, response.c_str(), response.size(), 0);

                // system("calc");
            }
            if (path == "/close/server")
            {

                std::cout << "close server (Bis bald)" << std::endl;
                i = 10;

                const char *body =
                    "Close server (Bis bald)\r\n"
                    "(Mahmoud Reda)\r\n";

                std::string response =
                    "HTTP/1.1 200 OK\r\n"
                    "Content-Type: text/plain\r\n"
                    "Content-Length: " +
                    std::to_string(strlen(body)) + "\r\n"
                                                   "\r\n" +
                    std::string(body);

                send(clientSocket, response.c_str(), response.size(), 0);
            }
        }
        else
        {
            std::cerr << "Receive failed\n";
        }

        // 8) cleanup
        closesocket(clientSocket);
    }
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

// Server starting...
// Server listening on port 5000...
// Client connected!
// ----- RAW HTTP REQUEST -----
// GET /open/calc HTTP/1.1
// cache-control: no-store
// accept: */*
// user-agent: Teste Android/7.6.12(800)
// Host: 192.168.1.7:5000
// Connection: Keep-Alive
// Accept-Encoding: gzip

// ----------------------------
// /open/calc
// ----- RAW HTTP REQUEST -----
// GET /open/calc HTTP/1.1
// cache-control: no-store
// accept: */*
// user-agent: Teste Android/7.6.12(800)
// Host: 192.168.1.7:5000
// Connection: Keep-Alive
// Accept-Encoding: gzip

// ----------------------------
// /open/calc
// ----- RAW HTTP REQUEST -----
// GET /open/calc HTTP/1.1
// cache-control: no-store
// accept: */*
// user-agent: Teste Android/7.6.12(800)
// Host: 192.168.1.7:5000
// Connection: Keep-Alive
// Accept-Encoding: gzip

// ----------------------------
// /open/calc
// ----- RAW HTTP REQUEST -----
// GET /open/calc HTTP/1.1
// cache-control: no-store
// accept: */*
// user-agent: Teste Android/7.6.12(800)
// Host: 192.168.1.7:5000
// Connection: Keep-Alive
// Accept-Encoding: gzip

// ----------------------------
// /open/calc
// ----- RAW HTTP REQUEST -----
// GET /open/calc HTTP/1.1
// cache-control: no-store
// accept: */*
// user-agent: Teste Android/7.6.12(800)
// Host: 192.168.1.7:5000
// Connection: Keep-Alive
// Accept-Encoding: gzip

// ----------------------------
// /open/calc
// ----- RAW HTTP REQUEST -----
// GET /close/server HTTP/1.1
// cache-control: no-store
// accept: */*
// user-agent: Teste Android/7.6.12(800)
// Host: 192.168.1.7:5000
// Connection: Keep-Alive
// Accept-Encoding: gzip

// U╝☺
// ----------------------------
// /close/server
// close server (Bis bald)