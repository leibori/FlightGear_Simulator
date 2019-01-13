//
// Created by ori on 1/11/19.
//

#ifndef SOLIDPROJECT_EX2_COMPFORMULT_H
#define SOLIDPROJECT_EX2_COMPFORMULT_H

#include "State.h"

template <class T>
class CompForMult {
public:
    /*checking if first state is smaller then the second one*/
    bool operator()(State<T>* const st,State<T>* const sta)const{
        return st->getCost()< sta->getCost();
    }
};
#endif //SOLIDPROJECT_EX2_COMPFORMULT_H
