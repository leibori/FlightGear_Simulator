#ifndef PROJECT2_SERVER_H
#define PROJECT2_SERVER_H

#include "ClientHandler.h"

class Server {
public:
    virtual void open(int port, ClientHandler* clientHandler) = 0;
};

#endif //PROJECT2_SERVER_H
