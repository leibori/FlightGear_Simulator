#ifndef SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H
#define SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <vector>

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
    Solver *solver;
    CacheManager *cacheManager;
public:
    MyTestClientHandler(Solver *solver1, CacheManager *cacheManager1) {
        solver = solver1;
        cacheManager = cacheManager1;
    }
    bool isNumber(string line);
    void handleClient(int socket);
};

#endif //SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H
