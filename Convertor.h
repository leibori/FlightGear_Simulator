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
     * convert string to problem
     */
    virtual P conVecStringToProblem(vector<string> pro) = 0;

    /*
    * convert problem to string
    */
    virtual string conVecProblemToString(P problem) = 0;


    /*
     * convert solve to string
     */
    virtual string conSolvToString(S solve) = 0;
    /*
   * convert string to solve
   */
    virtual S conStringToSol(string solve) = 0;


    virtual ~Convertor() = default;;

};

#endif //SOLIDPROJECT_EX2_CONVERTOR_H
