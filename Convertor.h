//
// Created by ori on 1/6/19.
//

#ifndef SOLIDPROJECT_EX2_CONVERTOR_H
#define SOLIDPROJECT_EX2_CONVERTOR_H

#include <string>

using namespace std;

template<class P, class S>
class Convertor {
public:
    /*
     * convert problem to string
     */
    virtual string conProbToString(P problem) = 0;

    /*
     * convert string to problem
     */
    virtual P conStringToProblem(string pro) = 0;

    /*
     * convert solve to string
     */
    virtual string conSolvToString(S solve) = 0;

    /*
     * convert string to solve
     */
    virtual S conStringToSolve(string sol) = 0;

};

#endif //SOLIDPROJECT_EX2_CONVERTOR_H