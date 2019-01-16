#include <iostream>
#include <fstream>
#include <regex>
#include <string>

#include "MyParallelServer.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "Convertor.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "Searchable.h"
#include "MatrixConvertor.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 2 && regex_match(argv[1], regex("^\\d+"))) {
        std::ofstream o("TestIt.txt",ios::app);

        Server<Searchable<pair<int, int>>*, string> *parallelServer = new
                MyParallelServer<Searchable<pair<int, int>>*, string>();
        Convertor<Searchable<pair<int, int>>*, string>* convertor = new MatrixConvertor();
        CacheManager<Searchable<pair<int, int>>*, string> *manager = new FileCacheManager<Searchable<pair<int, int>>*, string>("TestIt.txt", convertor);
        Solver<Searchable<pair<int, int>>*, string>* solver = new MatrixSearchableSolver<Searchable<pair<int, int>>*, string>();
        ClientHandler<Searchable<pair<int, int>>*, string>* handler = new MyTestClientHandler<Searchable<pair<int,
                int>>*, string>(convertor, solver, manager);

        parallelServer->open(atoi(argv[1]), handler);
        parallelServer->stop();

        delete handler;
        delete manager;
        delete convertor;
        delete parallelServer;
    } else {
        throw invalid_argument("Invalid arguments");
    }

    return 0;
}