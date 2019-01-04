//
// Created by ori on 1/4/19.
//
#include <string>
#include <algorithm>
#include "StringReverser.h"
using namespace std;

string StringReverser::solve(string problem){
        string res = problem;
        reverse(res.begin(), res.end());
        return res;
}
