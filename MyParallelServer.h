#ifndef SOLIDPROJECT_EX2_MYPARALLELSERVER_H
#define SOLIDPROJECT_EX2_MYPARALLELSERVER_H

#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>

#include "Server.h"
#include "ClientHandler.h"
#include "OpenServerArgs.h"
#include "ParallelClientArgs.h"

template <class P, class S>
class MyParallelServer : public Server<P,S> {
public:
    void open(int port, ClientHandler<P,S>* clientHandler) {
        auto serverArgs = new OpenServerArgs<P,S>(port, clientHandler);

        pthread_t pthread;
        pthread_create(&pthread, nullptr, MyParallelServer::start, (void*) (serverArgs));
    }

    static void* start(void* serverArgs) {
        int port = ((OpenServerArgs<P,S>*) serverArgs)->getPort();
        ClientHandler<P,S>* clientHandler = ((OpenServerArgs<P,S>*) serverArgs)->getClientHandler();

        int sockfd, newsockfd, clilen;
        struct sockaddr_in serv_addr, cli_addr;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        /* Check of creation succeeded*/
        if (sockfd < 0) {
            perror("Failed to open connection.");
            exit(1);
        }

        /* Initialize m_socket structure */
        bzero((char *) &serv_addr, sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons((uint16_t)((size_t)port));

        /* Now bind the host address using bind() call.*/
        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("Failed to bind server connection.");
            exit(1);
        }

        while (true) {
            listen(sockfd,5);
            clilen = sizeof(cli_addr);

            timeval timeout;
            timeout.tv_sec = 120;
            timeout.tv_usec = 0;

            setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

            newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

            if (newsockfd < 0) {
                if (errno == EWOULDBLOCK)	{
                    cout << "timeout!" << endl;
                    exit(2);
                }	else	{
                    perror("other error");
                    exit(3);
                }
            }

            auto commArgs = new OpenServerArgs<P,S>(newsockfd, clientHandler);

            pthread_t pthread;
            pthread_create(&pthread, nullptr, MyParallelServer::singleClientCom, (void*) (commArgs));
        }
    }

    static void* singleClientCom(void* commArgs) {
        int socketfd = ((OpenServerArgs<P,S>*) commArgs)->getPort();
        ClientHandler<P,S>* clientHandler = ((OpenServerArgs<P,S>*) commArgs)->getClientHandler();

        clientHandler->handleClient(socketfd);
    }

};

#endif //SOLIDPROJECT_EX2_MYPARALLELSERVER_H
