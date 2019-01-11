#ifndef SOLIDPROJECT_EX2_MYSERIALSERVER_H
#define SOLIDPROJECT_EX2_MYSERIALSERVER_H

#include <thread>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>

#include "Server.h"
#include "ClientHandler.h"

class MySerialServer : public Server {
    void open(int port, ClientHandler* clientHandler);
    static void* start(int port, ClientHandler* clientHandler);
};

#endif //SOLIDPROJECT_EX2_MYSERIALSERVER_H
