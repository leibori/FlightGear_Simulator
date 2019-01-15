#ifndef SOLIDPROJECT_EX2_OPENSERVERARGS_H
#define SOLIDPROJECT_EX2_OPENSERVERARGS_H

#include "ClientHandler.h"

template <class P, class S>
class OpenServerArgs {
    ClientHandler<P,S> *clientHandler;
    int port;
public:
    OpenServerArgs(int port1, ClientHandler<P,S> *clientHandler1) {
        clientHandler = clientHandler1;
        port = port1;
    }
    int getPort() { return port; }
    ClientHandler<P,S>* getClientHandler() { return clientHandler; }
};

#endif //SOLIDPROJECT_EX2_OPENSERVERARGS_H
