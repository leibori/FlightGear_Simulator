#include "MyTestClientHandler.h"

bool MyTestClientHandler::isNumber (string line) {
    auto it = line.begin();
    while (it != line.end() && isdigit(*it)) ++it;
    return !line.empty() && it == line.end();
}

void MyTestClientHandler::handleClient(int socket) {
    string line, solution;
    vector<string> problem;
    char buffer[2];
    bool isFirstLine;
    int dataLines, lineIndex = -1;
    while (true) {
        isFirstLine = true;
        bzero(buffer, 2);
        line = "";
        string data;
        ssize_t bytes_read;
        do {
            bytes_read = read(socket, buffer, 1);
            if (bytes_read < 0) {
                __throw_bad_exception();
            }
            line += buffer[0];
        } while (buffer[0] != *"\n" && buffer[0] != *"\r\n");
        lineIndex++;
        problem.push_back(line);
        if (line == "end\n" || line == "end\r\n") {
            break;
        } else if (isNumber(line) && isFirstLine) {
            isFirstLine = false;
            dataLines = atoi(line.c_str()) + 2;
            lineIndex = 0;
            problem.clear();
        }
        if (lineIndex != dataLines) {
            continue;
        }

        if (cacheManager->isExist(line)) {
            solution = cacheManager->loadPS(line);
        } else {
            solution = solver->solve(line);
        }
        if (write(socket, solution.c_str(), (int)(solution.length())) < 0) {
            throw "error writing data to socket";
        }
    }
}