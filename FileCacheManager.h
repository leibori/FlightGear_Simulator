//
// Created by ori on 1/5/19.
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
    unordered_map<string, string> allPS;
public:
    FileCacheManager(const string &path, Convertor<P, S> *convertors) : path(path), convertors(convertors) {
        if (!is_empty(path) && !isUsed) {
            loadFromFile();
            isUsed = true;
        }
    }

    bool isExistSol(const S &sol) const override {
        return (allPS.count(convertors->conSolvToString(sol)) > 0);
    }

    bool isExistProb(const P &pob) const override {
        return (allPS.count(convertors->conProbToString(pob)) > 0);
    }
    void mapAdding(string problem, string solution)  {
        allPS[problem] = solution;

    }

    void savePS(P problem, S solution) override {
        /* Create file . */
        ofstream dataFile;
        dataFile.open(this->path, ios_base::app);

        /* Adding to map. */
        allPS[convertors->conProbToString(problem)] = convertors->conSolvToString(solution);

        /* Write to file */
        dataFile << problem << endl;
        dataFile << solution << endl;

        /* Close file. */
        dataFile.close();
    }

    S getSol(P problem) override {
        if (isExistProb(problem)) {
            return convertors->conStringToSolve(allPS[problem]);
        } else {
            throw runtime_error("No such solution to problem");
        }
    }

    void loadFromFile() override {
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
            allPS[convertors->conProbToString(problem)] = solution;
        }

        data.close();
    }

private:
    bool is_empty(const string &pFile) {
        ifstream data;
        data.open(pFile);
        return data.peek() == std::ifstream::traits_type::eof();
    }


};

#endif //SOLIDPROJECT_EX2_FILECACHEMANAGER_H