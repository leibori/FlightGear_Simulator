//
// Created by ori on 1/10/19.
//

#include "MatrixConvertor.h"

Searchable<pair<int, int>>* MatrixConvertor::conVecStringToProblem(vector<string> pro) {
    MyMatrix *matrix = new MyMatrix(pro);
    return matrix;
}

string MatrixConvertor::conSolvToString(string solve) {
    return solve;
}

string MatrixConvertor::conVecProblemToString(Searchable<pair<int, int>>* problem) {
    vector<string> temp = problem->getOriginalVector();
    string toReturn;
    for (auto i : temp) {
        toReturn.append(i);
        toReturn.append("|");
    }
    string st = toReturn.substr(0, toReturn.size() - 1);
    return st;
}

string MatrixConvertor::conStringToSol(string solve) {
    return solve;
}
//split by specific token
vector<string>MatrixConvertor:: splitIt(string str, string token) {
    vector<string> result;
    while (str.size()) {
        int index = str.find(token);
        if (index != string::npos) {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)result.push_back(str);
        } else {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

MatrixConvertor::MatrixConvertor() = default;


