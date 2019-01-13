//
// Created by ori on 1/8/19.
//

#ifndef SOLIDPROJECT_EX2_SEARCHABLE_H
#define SOLIDPROJECT_EX2_SEARCHABLE_H

#include "State.h"
#include <vector>

using namespace std;

template<class T>
class Searchable {
public:
    virtual State<T> *getInitialState() = 0;

    virtual bool isGoalState(const State<T> &st) = 0;

    virtual State<T> *getGoalState() = 0;

    virtual vector<State<T>*> getAllpossibleStates(State<T> *s) = 0;

};

#endif //SOLIDPROJECT_EX2_SEARCHABLE_H
