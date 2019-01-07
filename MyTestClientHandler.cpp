#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(stringstream input, stringstream output) {
    string line, solution;
    bool endCommunication = false;

    while (true) {
        getline(input, line);
        if (line == "end") {
            break;
        }
        if (cacheManager->isExist(line)) {
            solution = cacheManager->loadPS(line, );
        } else {
            solution = solver->solve(line);
        }
        output << solution << flush;
    }
}