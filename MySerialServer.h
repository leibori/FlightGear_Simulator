#ifndef SOLIDPROJECT_EX2_MYSERIALSERVER_H
#define SOLIDPROJECT_EX2_MYSERIALSERVER_H

#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>

#include "Server.h"
#include "ClientHandler.h"
#include "OpenServerArgs.h"

class MySerialServer : public Server {
    void open(int port, ClientHandler* clientHandler);
    static void* start(void* serverArgs);
};

#endif //SOLIDPROJECT_EX2_MYSERIALSERVER_H
