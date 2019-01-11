#ifndef SOLIDPROJECT_EX2_MYPARALLELSERVER_H
#define SOLIDPROJECT_EX2_MYPARALLELSERVER_H

#include <pthread.h>
#include <thread>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>

#include "Server.h"
#include "ClientHandler.h"

class MyParallelServer : public Server {
    void open(int port, ClientHandler* clientHandler);
    static void* start(int port, ClientHandler* clientHandler);
};

#endif //SOLIDPROJECT_EX2_MYPARALLELSERVER_H
