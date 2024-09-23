#ifndef PEERRECEIVER_H_
#define PEERRECEIVER_H_
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <regex.h>
#include <thread>
#include <iostream>

class Server
{

private:
    std::string ServerName = "";
    std::string ServerPort = "";
    int sockfd = 0, newsockfd = 0, portno = 0;

public:
    Server(std::string, std::string);
    void StartServer();
};

#endif /* PEERRECEIVER_H_ */
