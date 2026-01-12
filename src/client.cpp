// C++ program to illustrate the client application in the
// socket programming
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    // creating socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // sending connection request
    connect(clientSocket, (struct sockaddr *)&serverAddress,
            sizeof(serverAddress));

    // sending data
    const char *message = "";
    std::cout << "options: put,get,exit";
    while (true)
    {
        std::string options;
        std::cout << "db>";
        std::cin >> options;
        if (options == "put")
        {
            message = "put";
            std::string key, value;
            std::cin >> key >> value;
            send(clientSocket, message, strlen(message), 0);
            // message = (const char*)key;
            // send(clientSocket, message, strlen(message), 0);
            // send(clientSocket, message, strlen(message), 0);
        }
        else if (options == "get")
        {
            message = "get";
        }
        else if (options == "exit")
        {
            message = "exit";
            close(clientSocket);
            return 0;
        }
        else
        {
            std::cout << "Please enter Proper option";
        }
    }
    // closing socket
    close(clientSocket);

    return 0;
}