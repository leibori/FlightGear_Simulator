#ifndef SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H
#define SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H

#include <iostream>

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
    void handleClient(stringstream input, stringstream output)
};

#endif //SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H
