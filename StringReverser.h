//
// Created by ori on 1/4/19.
//

#ifndef SOLIDPROJECT_EX2_STRINGREVERSER_H
#define SOLIDPROJECT_EX2_STRINGREVERSER_H

#include <string>
#include "Solver.h"

using namespace std;

class StringReverser : public Solver<string, string> {
    string solve(string problem) override ;
};

#endif //SOLIDPROJECT_EX2_STRINGREVERSER_H
