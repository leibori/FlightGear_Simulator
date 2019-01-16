//
// Created by ori on 1/12/19.
//

#ifndef SOLIDPROJECT_EX2_BESTFIRSTSEARCH_H
#define SOLIDPROJECT_EX2_BESTFIRSTSEARCH_H

#include "algorithm"
#include <list>
#include "CompForMult.h"
#include "InCommonSearcher.h"

using namespace std;

template<class S, class T>
class BestFirstSearch : public InCommonSearcher<S, T> {
public:
    S search(Searchable<T> *searchable) override {
        this->addToOpenList(searchable->getInitialState());
        while (this->getOpenListSize() > 0) {
            State<T> *n = this->popOpenList();
            this->closed.push_back(n);
            if (n->equal(searchable->getGoalState())) {
                return this->backTrace(n, searchable);
            }
            State<T> *father = new State<T>(*n);
            vector<State<T> *> successors = searchable->getAllpossibleStates(father);
            for (auto iter = successors.begin(); iter != successors.end(); iter++) {
                if (!closeContains(*iter, this->closed) && !this->contains(*iter)) {
                    State<T> *s = *iter;
                    //s->setCameForm(father);
                    this->addToOpenList(s);
                } else if (!closeContains(*iter, this->closed)) {
                    this->optionPriority(*iter);
                }
            }
        }
    }


    virtual bool closeContains(State<T> *stateIt, vector<State<T>*> close) {
        for (auto it = close.begin(); it != close.end(); it++) {
            State<T> *s = *it;
            if (s->equal(stateIt)) {
                return true;
            }
        }
        return false;
    }
};

#endif //SOLIDPROJECT_EX2_BESTFIRSTSEARCH_H
