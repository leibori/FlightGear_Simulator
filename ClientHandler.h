#ifndef PROJECT2_CLIENTHANDLER_H
#define PROJECT2_CLIENTHANDLER_H

#include <string>

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(stringstream input, stringstream output) = 0;
};

#endif //PROJECT2_CLIENTHANDLER_H
