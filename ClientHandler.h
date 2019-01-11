#ifndef PROJECT2_CLIENTHANDLER_H
#define PROJECT2_CLIENTHANDLER_H

#include <string>

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(void* socket) = 0;
};

#endif //PROJECT2_CLIENTHANDLER_H
