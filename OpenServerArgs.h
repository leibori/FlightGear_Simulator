#ifndef SOLIDPROJECT_EX2_OPENSERVERARGS_H
#define SOLIDPROJECT_EX2_OPENSERVERARGS_H

#include "ClientHandler.h"

class OpenServerArgs {
    ClientHandler *clientHandler;
    int port;
public:
    OpenServerArgs(int port1, ClientHandler *clientHandler1) {
        clientHandler = clientHandler1;
        port = port1;
    }
    int getPort() { return port; }
    ClientHandler* getClientHandler() { return clientHandler; }
};

#endif //SOLIDPROJECT_EX2_OPENSERVERARGS_H
