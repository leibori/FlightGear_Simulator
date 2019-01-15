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
    P problem;
    S solution;

public:
    virtual ~FileCacheManager() {

    }

    FileCacheManager(const string &path, Convertor<P, S> *convertors, P problem, S solution) : path(path),
                                                                                               convertors(convertors),
                                                                                               problem(problem),
                                                                                               solution(solution) {
        if (!is_empty(path) && !isUsed) {
            loadFromFile();
            isUsed = true;
        }
        if (!isExistSol(solution)){
            savePS(problem,solution);
        }
    }


    bool isExistSol(const S &sol) const override {
        return (allPS.count(convertors->conSolvToString(this->solution)) > 0);
    }

    bool isExistProb(const P &pob) const override {
        return (allPS.count(convertors->conProbToString(this->problem)) > 0);
    }

    void mapAdding(string problem, string solution) {
        string problemS = convertors->conVecProblemToString(problem);
        string solveS = convertors->conSolvToString(solution);
        allPS[problemS] = solveS;

    }

    void savePS(P problem, S solution) override {
        /* Create file . */
        ofstream dataFile;
        dataFile.open(this->path, ios_base::app);

        /* Adding to map. */
        mapAdding(problem, solution);
        /* Write to file */
        string problemS = convertors->conVecProblemToString(problem);
        string solveS = convertors->conSolvToString(solution);
        dataFile << problemS << endl;
        dataFile << solveS << endl;

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
            allPS[problem] = solution;
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