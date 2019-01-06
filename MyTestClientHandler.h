#ifndef SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H
#define SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
    Solver solver;
    CacheManager cacheManager;
public:
    MyTestClientHandler(Solver solver1, CacheManager cacheManager1);
    void handleClient(/*InputStream input, OutputStream output*/)
};

#endif //SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H
