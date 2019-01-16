#ifndef PROJECT2_SERVER_H
#define PROJECT2_SERVER_H

#include "ClientHandler.h"

template <class P, class S>
class Server {
public:
    virtual void open(int port, ClientHandler<P,S>* clientHandler) = 0;
    virtual void stop() = 0;
};

#endif //PROJECT2_SERVER_H
