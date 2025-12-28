#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

/**
 * @brief server class to encapsulate server functionality
 */
class server
{
private:
    SOCKET serverSocket;

    /**
     * @brief Handle commands based on the requested path
     *
     * @param path
     * @param clientSocket
     * @param i
     */
    void handleCommand(const std::string &path, const SOCKET &clientSocket, bool &i)

    {
        if (path == "/open/calc")
        {
            int status = system("calc");
            std::cout << "Calculator open status: " << status << std::endl;
            if (status == 0)
            {
                const char *body =
                    "Hallo from C++20 Server\r\n"
                    "Calculator is open \r\n";

                std::string response =
                    "HTTP/1.1 200 OK\r\n"
                    "Content-Type: text/plain\r\n"
                    "Content-Length: " +
                    std::to_string(strlen(body)) + "\r\n"
                                                   "\r\n" +
                    std::string(body);

                send(clientSocket, response.c_str(), response.size(), 0);
            }
            else
            {
                const char *body =
                    "Hallo from C++20 Server\r\n"
                    "Failed to open Calculator \r\n";

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
        if (path == "/open/notepad")
        {
            int status = system("notepad");
            std::cout << "Notepad open status: " << status << std::endl;
            if (status == 0)
            {
                const char *body =
                    "Hallo from C++20 Server\r\n"
                    "Notepad is open \r\n";

                std::string response =
                    "HTTP/1.1 200 OK\r\n"
                    "Content-Type: text/plain\r\n"
                    "Content-Length: " +
                    std::to_string(strlen(body)) + "\r\n"
                                                   "\r\n" +
                    std::string(body);

                send(clientSocket, response.c_str(), response.size(), 0);
            }
            else
            {
                const char *body =
                    "Hallo from C++20 Server\r\n"
                    "Failed to open Notepad \r\n";

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
        if (path == "/open/chrome")
        {
            int status = system("\"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe\"");
            std::cout << "Browser open status: " << status << std::endl;
            if (status == 0)
            {
                const char *body =
                    "Hallo from C++20 Server\r\n"
                    "Browser is open \r\n";

                std::string response =
                    "HTTP/1.1 200 OK\r\n"
                    "Content-Type: text/plain\r\n"
                    "Content-Length: " +
                    std::to_string(strlen(body)) + "\r\n"
                                                   "\r\n" +
                    std::string(body);

                send(clientSocket, response.c_str(), response.size(), 0);
            }
            else
            {
                const char *body =
                    "Hallo from C++20 Server\r\n"
                    "Failed to open Browser \r\n";

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

        if (path == "/close/server")
        {

            std::cout << "close server (Bis bald)" << std::endl;
            i = false;

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
    /**
     * @brief Initialize and run the server
     *
     */
    void server_init(SOCKET &serverSockett)
    {
        std::cout << "Server starting...\n";

        // 1) init Winsock
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        {
            std::cerr << "WSAStartup failed\n";
        }

        // 2) Create socket
        SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        serverSockett = serverSocket;
        if (serverSocket == INVALID_SOCKET)
        {
            std::cerr << "Socket creation failed\n";
            WSACleanup();
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
        }

        // 5) listen
        if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
        {
            std::cerr << "Listen failed\n";
            closesocket(serverSocket);
            WSACleanup();
        }

        std::cout << "Server listening on port 5000...\n";
    }
    /**
     * @brief server loop to accept and handle client requests
     *
     * @param serverSocket
     */
    void serverloop(SOCKET &serverSocket)
    {
        bool i = true;
        while (i != false)
        {

            // 6) accept
            SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
            if (clientSocket == INVALID_SOCKET)
            {
                std::cerr << "Accept failed\n";
                closesocket(serverSocket);
                WSACleanup();
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

                handleCommand(path, clientSocket, i);
            }
            else
            {
                std::cerr << "Receive failed\n";
            }

            // 8) cleanup
            closesocket(clientSocket);
        }
    }
    /**
     * @brief Cleanup server resources
     *
     * @param serverSocket
     */
    void server_cleanup(SOCKET &serverSocket)
    {
        closesocket(serverSocket);
        WSACleanup();
    }

public:
    server()
    {
        // Server socket declaration

        // Initialize and start the server
        server_init(serverSocket);
    }

    void serverloo()
    {
        // Run the server loop to handle client requests
        serverloop(serverSocket);
    }

    ~server()
    {
        // Cleanup server resources
        server_cleanup(serverSocket);
    }
};

int main()
{
    // Create and run the server
    server server_s;
    server_s.serverloo(); // Start server loop

    return 0;
}

// Server starting...
// Server listening on port 5000...
// ----- RAW HTTP REQUEST -----
// GET /open/notepad HTTP/1.1
// cache-control: no-store
// accept: */*
// user-agent: Teste Android/7.6.12(800)
// Host: 192.168.1.7:5000
// Connection: Keep-Alive
// Accept-Encoding: gzip

// ----------------------------
// /open/notepad
// Notepad open status: 0
// ----- RAW HTTP REQUEST -----
// GET /open/chrome HTTP/1.1
// cache-control: no-store
// accept: */*
// user-agent: Teste Android/7.6.12(800)
// Host: 192.168.1.7:5000
// Connection: Keep-Alive
// Accept-Encoding: gzip

// ----------------------------
// /open/chrome
// Browser open status: 0
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
// Calculator open status: 0
// ----- RAW HTTP REQUEST -----
// GET /close/server HTTP/1.1
// cache-control: no-store
// accept: */*
// user-agent: Teste Android/7.6.12(800)
// Host: 192.168.1.7:5000
// Connection: Keep-Alive
// Accept-Encoding: gzip

// ----------------------------
// /close/server
// close server (Bis bald)