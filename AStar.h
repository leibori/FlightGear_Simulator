//
// Created by ori on 1/14/19.
//

#ifndef SOLIDPROJECT_EX2_ASTAR_H
#define SOLIDPROJECT_EX2_ASTAR_H
#include "algorithm"
#include <list>
#include "CompForMult.h"
#include "InCommonSearcher.h"

using namespace std;

template<class S, class T>
class Astar : public InCommonSearcher<S,T>   {
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
                    T nowS = s->getState();
                    T goalS = searchable->getGoalState()->getState();
                   auto manhattan = manhattanDistance(nowS,goalS);
                    auto costIt = s->getCost();
                    if (s->getCameForm()->getDirection() != "none"){
                        auto fatherManhattan = manhattanDistance(s->getCameForm()->getState(),goalS);
                        SetAstarCost(manhattan, static_cast<int>(s->getCost()), fatherManhattan, s);
                    } else{
                        SetAstarCost(manhattan, static_cast<int>(s->getCost()), 0, s);
                    }
                    this->addToOpenList(s);
                } else if (!closeContains(*iter, this->closed)) {
                    this->optionMinimum(*iter);
                }
            }
        }
    }

    bool closeContains(State<T> *stateIt, vector<State<T>*> close) {
        for (auto it = close.begin(); it != close.end(); it++) {
            State<T> *s = *it;
            if (s->equal(stateIt)) {
                return true;
            }
        }
        return false;
    }
    auto manhattanDistance (T begin ,T end ){
        return abs(get<0>(end)-get<0>(begin)) + abs(get<1>(end)-get<1>(begin));
    }
    void SetAstarCost(int distance,int cost, int upperDistance,State<T> *stateIt){
        stateIt->setCost(distance + cost - upperDistance);
    }
};
#endif //SOLIDPROJECT_EX2_ASTAR_H
