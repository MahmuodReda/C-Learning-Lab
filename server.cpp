#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <map>
#include <functional>

// =========================
// HTTP REQUEST
// =========================
struct HttpRequest
{
    std::string method;
    std::string path;

    static bool parse(const std::string &raw, HttpRequest &out)
    {
        size_t methodEnd = raw.find(' ');
        if (methodEnd == std::string::npos)
            return false;

        size_t pathEnd = raw.find(' ', methodEnd + 1);
        if (pathEnd == std::string::npos)
            return false;

        out.method = raw.substr(0, methodEnd);
        out.path = raw.substr(methodEnd + 1, pathEnd - methodEnd - 1);
        return true;
    }
};

// =========================
// HTTP RESPONSE
// =========================
class HttpResponse
{
public:
    static void sendText(SOCKET client, const std::string &body, int status = 200)
    {
        std::string response =
            "HTTP/1.1 " + std::to_string(status) + " OK\r\n"
                                                   "Content-Type: text/plain\r\n"
                                                   "Content-Length: " +
            std::to_string(body.size()) + "\r\n"
                                          "\r\n" +
            body;

        send(client, response.c_str(), static_cast<int>(response.size()), 0);
    }
};

// =========================
// ROUTER
// =========================
class Router
{
public:
    using Handler = std::function<void(SOCKET, bool &)>;

    static void init()
    {
        routes["/open/calc"] = [](SOCKET c, bool &)
        {
            system("calc");
            HttpResponse::sendText(c, "Calculator opened\n");
        };

        routes["/open/notepad"] = [](SOCKET c, bool &)
        {
            system("notepad");
            HttpResponse::sendText(c, "Notepad opened\n");
        };

        routes["/open/chrome"] = [](SOCKET c, bool &)
        {
            system("\"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe\"");
            HttpResponse::sendText(c, "Chrome opened\n");
        };

        routes["/close/server"] = [](SOCKET c, bool &running)
        {
            running = false;
            HttpResponse::sendText(c, "Server shutting down\n");
        };
    }

    static void dispatch(const HttpRequest &req, SOCKET client, bool &running)
    {
        auto it = routes.find(req.path);
        if (it != routes.end())
        {
            it->second(client, running);
        }
        else
        {
            HttpResponse::sendText(client, "404 Not Found\n", 404);
        }
    }

private:
    static inline std::map<std::string, Handler> routes;
};

// =========================
// SERVER
// =========================
class Server
{
public:
    Server(int port) : port(port), running(true)
    {
        initWinsock();
        createSocket();
        bindSocket();
        listenSocket();
        Router::init();
    }

    void run()
    {
        std::cout << "Server listening on port " << port << "...\n";

        while (running)
        {
            SOCKET client = accept(serverSocket, nullptr, nullptr);
            if (client == INVALID_SOCKET)
                continue;

            char buffer[2048]{};
            int received = recv(client, buffer, sizeof(buffer) - 1, 0);

            if (received > 0)
            {
                std::string raw(buffer, received);

                std::cout << "----- RAW REQUEST -----\n";
                std::cout << raw << "\n";

                HttpRequest request;
                if (HttpRequest::parse(raw, request))
                {
                    Router::dispatch(request, client, running);
                }
                else
                {
                    HttpResponse::sendText(client, "Bad Request\n", 400);
                }
            }

            closesocket(client);
        }
    }

    ~Server()
    {
        closesocket(serverSocket);
        WSACleanup();
    }

private:
    SOCKET serverSocket{};
    int port;
    bool running;

    void initWinsock()
    {
        WSADATA data;
        WSAStartup(MAKEWORD(2, 2), &data);
    }

    void createSocket()
    {
        serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    }

    void bindSocket()
    {
        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);

        bind(serverSocket, reinterpret_cast<sockaddr *>(&addr), sizeof(addr));
    }

    void listenSocket()
    {
        listen(serverSocket, SOMAXCONN);
    }
};

// =========================
// MAIN
// =========================
int main()
{
    Server server(5000);
    server.run();
    return 0;
}

// Server listening on port 5000...
// ----- RAW REQUEST -----
// GET /open/calc HTTP/1.1
// Host: 192.168.1.7:5000
// Connection: keep-alive
// Upgrade-Insecure-Requests: 1
// User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/143.0.0.0 Safari/537.36 Edg/143.0.0.0
// Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
// Accept-Encoding: gzip, deflate
// Accept-Language: ar,en;q=0.9,en-GB;q=0.8,en-US;q=0.7

// ----- RAW REQUEST -----
// GET /favicon.ico HTTP/1.1
// Host: 192.168.1.7:5000
// Connection: keep-alive
// User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/143.0.0.0 Safari/537.36 Edg/143.0.0.0
// Accept: image/avif,image/webp,image/apng,image/svg+xml,image/*,*/*;q=0.8
// Referer: http://192.168.1.7:5000/open/calc
// Accept-Encoding: gzip, deflate
// Accept-Language: ar,en;q=0.9,en-GB;q=0.8,en-US;q=0.7

// ----- RAW REQUEST -----
// GET /close/server HTTP/1.1
// Host: 192.168.1.7:5000
// Connection: keep-alive
// Upgrade-Insecure-Requests: 1
// User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/143.0.0.0 Safari/537.36 Edg/143.0.0.0
// Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
// Accept-Encoding: gzip, deflate
// Accept-Language: ar,en;q=0.9,en-GB;q=0.8,en-US;q=0.7
