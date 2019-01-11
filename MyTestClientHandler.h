#ifndef SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H
#define SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <vector>

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "MyMatrix.h"

class MyTestClientHandler : public ClientHandler {
    Solver<MyMatrix, string> *solver;
    CacheManager<MyMatrix, string> *cacheManager;
public:
    MyTestClientHandler(Solver<MyMatrix, string> *solver1, CacheManager<MyMatrix, string> *cacheManager1) {
        solver = solver1;
        cacheManager = cacheManager1;
    }
    bool isNumber(string line);
    void handleClient(int socket);
};

#endif //SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H
