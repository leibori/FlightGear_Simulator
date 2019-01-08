//
// Created by ori on 1/8/19.
//

#ifndef SOLIDPROJECT_EX2_SEARCHER_H
#define SOLIDPROJECT_EX2_SEARCHER_H

#include "Searchable.h"

template<typename solution, class T>
class Searcher {
public:
    virtual solution search(Searchable<T> searchable) = 0;

    virtual int getNumberOfNodesEvaluate() = 0;
};

#endif //SOLIDPROJECT_EX2_SEARCHER_H
