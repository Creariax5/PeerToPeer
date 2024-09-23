#include "server.h"

#include <iostream>
#include <thread>
#include <unistd.h>
#include <memory>
#include <exception>

// The PeerReceiver Thread act like a server
void StartServer(std::string ServerName, std::string ServerPort)
{
    std::unique_ptr<Server> rec(new Server(ServerName, ServerPort));
    rec->StartServer();
}

// The PeerSender Thread will connect to other peer
void StartClient()
{
    std::cout << "StartThePeerSender ... \n";
}

int main()
{
    std::string ServerName = "";
    std::string ServerPort = "";
    std::cout << "Enter the peer hostname \n";
    std::cin >> ServerName;
    std::cout << "Enter the peer receiver port \n";
    std::cin >> ServerPort;

    std::thread PeerReceiver(StartServer, ServerName, ServerPort);
    std::thread StartTheSender(StartClient);
    std::cout << " ---START---\n";
    PeerReceiver.join();
    StartTheSender.join();
    std::cout << "---END---" << std::endl;
    return 0;
}
