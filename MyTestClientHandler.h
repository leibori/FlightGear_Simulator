#ifndef SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H
#define SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H

#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <vector>

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "MyMatrix.h"

using namespace std;

template <class P, class S>
class MyTestClientHandler : public ClientHandler {
    Convertor<P,S> *convertor;
    Solver<P,S> *solver;
    CacheManager<P,S> *cacheManager;
public:
    MyTestClientHandler(Convertor<P,S> *convertor1, Solver<P,S> *solver1, CacheManager<P,S> *cacheManager1) {
        convertor = convertor1;
        solver = solver1;
        cacheManager = cacheManager1;
    }
    void handleClient(int socket)  {
        S solution;
        P convertedProblem;
        string line, convertedSolution;
        vector<string> problem;
        char buffer[2];
        bool isFirstLine, stop = false;
        int dataLines, lineIndex;
        while (true) {
            dataLines = 3;
            isFirstLine = true;
            lineIndex = 0;
            do {
                bzero(buffer, 2);
                line = "";
                ssize_t bytes_read;
                do {
                    bytes_read = read(socket, buffer, 1);
                    if (bytes_read < 0) {
                        __throw_bad_exception();
                    }
                    line += buffer[0];
                } while (buffer[0] != *"\n" && buffer[0] != *"\r\n");
                if (line == "end\n" || line == "end\r\n") {
                    stop = true;
                    break;
                } else if (isFirstLine) {
                    isFirstLine = false;
                    for (int i = 0; i < line.size(); i++) {
                        if (line[i] == ',') {
                            dataLines++;
                        }
                    }
                    problem.clear();
                }
                problem.push_back(line);
                lineIndex++;
            } while (lineIndex != dataLines);
            if (stop) {
                break;
            }
            convertedProblem = convertor->conVecStringToProblem(problem);
            if (cacheManager->isExistProb(convertedProblem)) {
                solution = cacheManager->getSol(convertedProblem);
            } else {
                solution = solver->solve(problem);
            }
            convertedSolution = convertor->conSolvToString(solution);
            if (write(socket, convertedSolution.c_str(), (int)(convertedSolution.length())) < 0) {
                throw "error writing data to socket";
            }
        }
    }
};

#endif //SOLIDPROJECT_EX2_MYTESTCLIENTHANDLER_H
