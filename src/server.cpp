#include "server.h"
#include <iostream>

Server::Server(std::string ServerName, std::string ServerPort)
{

    this->ServerName = ServerName;
    this->ServerPort = ServerPort;
}

void Server::StartServer()
{
    // Création du Socket
    sockfd = socket(AF_UNSPEC, SOCK_STREAM, 0);
    if (sockfd < 0)
        std::cerr << "ERROR opening socket" << strerror(errno) << "\n";

    // Initialisation de l'Adresse du Serveur
    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(ReceiverPort.c_str());
    serv_addr.sin_family = AF_UNSPEC;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    std::cout << sockfd;
    std::cout << ServerName;
    std::cout << ":";
    std::cout << ServerPort;
    std::cout << " started \n";
}

/*void PeerReceiver::StartReceiver()
{
    // Changer le Répertoire de Travail
    if (chdir(SERVER_SHARED_DIR) < 0)
        cerr << "ERROR Shared Dir  " << strerror(errno) << "\n";

    // Création du Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        std::cerr << "ERROR opening socket" << strerror(errno) << "\n";

    // Initialisation de l'Adresse du Serveur
    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(ReceiverPort.c_str());
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Liaison du Socket
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        std::cerr << "ERROR on binding" << std::endl;

    // Écoute des Connexions
    listen(sockfd, 10);
    clilen = sizeof(cli_addr);

    // Acceptation des Connexions
    cout << "---- PEER Receiver started at Port ---- " << portno << endl;
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
        std::cerr << "ERROR on accept" << strerror(errno) << "\n";

    // Réception et Traitement des Commandes
    char cmd[MAX_COMMAND_LEN];
    recv(newsockfd, cmd, MAX_COMMAND_LEN, 0);
    while (strcmp(cmd, "exit"))
    {
        if (!strcmp(cmd, "ls"))
        {
            listfiles(newsockfd);
        }
        else
        {
            // cout << "File to upload is " << cmd << endl;
            FileReaderAndReceiver(cmd, newsockfd);
        }

        memset(cmd, 0, sizeof(cmd));
        recv(newsockfd, cmd, MAX_COMMAND_LEN, 0);
    }
    close(newsockfd);
    close(sockfd);
}*/