//
// Created by ori on 1/10/19.
//

#include "MatrixConvertor.h"
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

vector<vector<int>> MatrixConvertor::conVecStringToProblem(vector<string> pro) {
    for (auto &it : pro) {
        vector<int> line;
        vector<string> afterSplit = splitIt(it,",");
        for (auto &it : afterSplit) {
            line.push_back(std::stoi(it));
        }
        matrix.push_back(line);
    }
    return matrix;
}

string MatrixConvertor::conSolvToString(string solve) {
    return solve;
}

MatrixConvertor::MatrixConvertor() = default;



