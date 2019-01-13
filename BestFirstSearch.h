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
        multiset<State<T>*, CompForMult<T>> closed;
        while (this->getOpenListSize() > 0) {
            State<T>* n = this->popOpenList();
            closed.insert(n);
            if (n->equal(searchable->getGoalState())) {
                return backTrace(n, searchable);
            }
            State<T> *father = n;
            vector<State<T>*> successors = searchable->getAllpossibleStates(father);
            for (auto iter = successors.begin(); iter != successors.end(); iter++) {
                if (!closeContains(*iter,closed) && !this->contains(*iter)) {
                    State<T> *s = *iter;
                    s->setCameForm(father);
                    this->addToOpenList(s);
                } else if (!closeContains(*iter,closed)) {
                    saveMin(*iter);
                }
            }
        }
    }

    S backTrace(State<T>* s, Searchable<T> *searchable) {
        vector<string> path;
        string toReturn;
        State<T> *startState = searchable->getInitialState();
        //State<T> *current = new State<T>(s.getState(), s.getCost(), s.getCameFrom(), s.getCameFromDir());
        State<T> *current = s;
        while (!(current->equal(startState))) {
            path.push_back(current->getDirection());
            current = current->getCameForm();
        }
        reverse(path.begin(), path.end());
        for (auto i : path) {
            toReturn.append(i);
            toReturn.append(",");
        }
        string st = toReturn.substr(0, toReturn.size() - 1);
        return st;

    }

    void saveMin(State<T>* currState) {
        for (auto it = InCommonSearcher<S, T>::openList.begin(); it != InCommonSearcher<S, T>::openList.end(); it++) {
            State<T> *s = *it;
            if (s->equal(currState)) {
                if (currState->getCost() < s->getCost()) {
                    InCommonSearcher<S, T>::openList.erase(it);
                    s->setCameForm(currState->getCameForm());
                    this->addToOpenList(currState);
                }
                return;
            }
        }
        this->addToOpenList(currState);
        return;
    }
    bool closeContains(State<T> *stateIt, multiset<State<T>*, CompForMult<T>> close){
        return static_cast<bool>(close.count(stateIt));
    }
};

#endif //SOLIDPROJECT_EX2_BESTFIRSTSEARCH_H
