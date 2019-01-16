//
// Created by ori on 1/8/19.
//

#ifndef SOLIDPROJECT_EX2_SEARCHER_H
#define SOLIDPROJECT_EX2_SEARCHER_H

#include "Searchable.h"

template<class S, class T>
class Searcher {
public:
    virtual S search(Searchable<T>* searchable) = 0;

    virtual int getNumberOfNodesEvaluate() = 0;

    virtual ~Searcher() = default;
};

#endif //SOLIDPROJECT_EX2_SEARCHER_H
