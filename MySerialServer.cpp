#include "MySerialServer.h"

void MySerialServer::open(int port, ClientHandler clientHandler) {
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

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("Failed to accept server connection.");
        exit(1);
    }

    do {
        string data;
        char buffer[2];
        ssize_t bytes_read;
        bytes_read = read(newsockfd, buffer, 1);
        while (buffer[0] != *"\n") {
            if (bytes_read < 0) {
                __throw_bad_exception();
            }
            data += buffer[0];
            bytes_read = read(newsockfd, buffer, 1);
        }
        //ClientHandler handle the input from the server and returns an appropriate output.
    } while (true);
}