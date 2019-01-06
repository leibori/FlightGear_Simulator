#ifndef PROJECT2_CLIENTHANDLER_H
#define PROJECT2_CLIENTHANDLER_H

#include <iostream>

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(istream input, ostream output) = 0;
};

#endif //PROJECT2_CLIENTHANDLER_H
