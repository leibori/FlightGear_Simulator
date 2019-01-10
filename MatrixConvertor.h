//
// Created by ori on 1/10/19.
//

#ifndef SOLIDPROJECT_EX2_MATRIXCONVERTOR_H
#define SOLIDPROJECT_EX2_MATRIXCONVERTOR_H
#include <vector>
#include "Convertor.h"
using namespace std;
class MatrixConvertor : public Convertor <vector<vector<int>>,string>{
    vector<vector<int>> matrix;
    int length;
    int width;
public:
    MatrixConvertor();

    vector<string>splitIt(string str, string token);

    vector<vector<int>> conVecStringToProblem(vector<string> pro) override;

    string conSolvToString(string solve) override;


};
#endif //SOLIDPROJECT_EX2_MATRIXCONVERTOR_H
