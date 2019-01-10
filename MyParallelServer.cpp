#include "MyParallelServer.h"

void MyParallelServer::open(int port, ClientHandler* clientHandler) {
    auto serverArgs = new OpenServerArgs(port, clientHandler);

    pthread_t pthread;
    pthread_create(&pthread, nullptr, MyParallelServer::start, (void*) (serverArgs));
}

void* MyParallelServer::start(void* serverArgs) {
    int port = ((OpenServerArgs*) serverArgs)->getPort();
    ClientHandler* clientHandler = ((OpenServerArgs*) serverArgs)->getClientHandler();

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
        timeout.tv_sec = 10;
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

        auto parallelClientArgs = new ParallelClientArgs(port);

        pthread_t pthread;
        pthread_create(&pthread, nullptr, ClientHandler::handleClient, (void*) (parallelClientArgs));
    }
}
