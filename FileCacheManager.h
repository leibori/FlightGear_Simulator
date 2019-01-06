//
// Created by edan on 1/5/19.
//

#ifndef SOLIDPROJECT_EX2_FILECACHEMANAGER_H
#define SOLIDPROJECT_EX2_FILECACHEMANAGER_H

#include <string>
#include <unordered_map>
#include <fstream>
#include "CacheManager.h"
#include "Convertor.h"

template<typename P, typename S>
class FileCacheManager : public CacheManager<P, S> {
    static bool isUsed;
    string path;
    Convertor<P, S> *convertors;
    unordered_map<P, S> allPS;
public:
    FileCacheManager(const string &path, Convertor<P, S> *convertors) : path(path), convertors(convertors) {
        if (!is_empty(path) && !isUsed) {
            loadFromFile();
            isUsed = true;
        }
    }

    bool isExist(const S &sol) const override {
        return (allPS.count(sol) > 0);
    }

    void savePS(P problem, S solution) override {
        /* Create file . */
        ofstream dataFile;
        dataFile.open(this->path, ios_base::app);

        /* Adding to map. */
        allPS[problem] = solution;

        /* Write to file */
        dataFile << convertors->conProbToString(problem) << endl;
        dataFile << convertors->conSolvToString(solution) << endl;

        /* Close file. */
        dataFile.close();
    }

    S loadPS(P problem, S solution) override{
        if(isExist(solution)){
            return allPS[problem];
        }
        else{
            throw runtime_error("No such solution");
        }
    }

private:
    bool is_empty(const string &pFile) {
        ifstream data;
        data.open(pFile);
        return data.peek() == std::ifstream::traits_type::eof();
    }

    void loadFromFile() {
        string problem;
        string solution;
        ifstream data;
        data.open(this->path);

        if (!data.good()) {
            return;
        }

        /* Read a line from file. */
        while (getline(data, problem)) {
            getline(data, solution);
            allPS[convertors->conStringToProblem(problem)] = convertors->conStringToSolve(solution);
        }

        data.close();
    }
};

#endif //SOLIDPROJECT_EX2_FILECACHEMANAGER_H