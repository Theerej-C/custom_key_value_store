#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>
#include <storage.h>
#include <hashmap.h>
int main()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        perror("socket");
        return 1;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddress,
             sizeof(serverAddress)) < 0)
    {
        perror("bind");
        return 1;
    }

    if (listen(serverSocket, 5) < 0)
    {
        perror("listen");
        return 1;
    }

    int clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket < 0)
    {
        perror("accept");
        return 1;
    }

    char buffer[1024];

    std::string PATH = "db/db.txt";
    HashMap map(30);
    load_from_file(map, PATH);

    while (true)
    {
        int bytes = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        buffer[bytes] = '\0';
        std::stringstream ss(buffer);
        std::string s;

        while (ss >> s)
        {
            if (s == "put")
            {
                std::cout << "first operation\n";
            }
            else if (s == "get")
            {
                // std::cout << "second operation\n";
            }
            else if (s == "exit")
            {
                // std::cout << "Third option, exiting\n";
                close(clientSocket);
                close(serverSocket);
                return 0;
            }
        }
    }

    close(clientSocket);
    close(serverSocket);
    return 0;
}
