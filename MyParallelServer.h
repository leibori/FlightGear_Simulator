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

class MyParallelServer : public Server {
    void open(int port, ClientHandler* clientHandler);
    static void* start(void* serverArgs);
    static void* singleClientCom(void* serverArgs);

};

#endif //SOLIDPROJECT_EX2_MYPARALLELSERVER_H
