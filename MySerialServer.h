#ifndef SOLIDPROJECT_EX2_MYSERIALSERVER_H
#define SOLIDPROJECT_EX2_MYSERIALSERVER_H

#include "Server.h"
#include "ClientHandler.h"

class MySerialServer : public Server {
    void open(int port, ClientHandler clientHandler);
};

#endif //SOLIDPROJECT_EX2_MYSERIALSERVER_H
