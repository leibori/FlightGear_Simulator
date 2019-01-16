//
// Created by ori on 1/10/19.
//

#ifndef SOLIDPROJECT_EX2_MATRIXCONVERTOR_H
#define SOLIDPROJECT_EX2_MATRIXCONVERTOR_H
#include <vector>
#include "Convertor.h"
#include "MyMatrix.h"
#include "Searchable.h"
using namespace std;
class MatrixConvertor : public Convertor <Searchable<pair<int, int>>* ,string>{
    vector<Searchable<pair<int, int>>*>garbagePointers;
public:
    MatrixConvertor();

    Searchable<pair<int, int>>* conVecStringToProblem(vector<string> pro) override;

    string conVecProblemToString(Searchable<pair<int, int>>* problem) override;

    string conSolvToString(string solve) override;

    string conStringToSol(string solve) override;

    virtual ~MatrixConvertor();

private:
//split by specific token
    vector<string> splitIt(string str, string token) ;

};
#endif //SOLIDPROJECT_EX2_MATRIXCONVERTOR_H
