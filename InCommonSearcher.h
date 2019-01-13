//
// Created by ori on 1/11/19.
//

#ifndef SOLIDPROJECT_EX2_INCOMMONSEARCHER_H
#define SOLIDPROJECT_EX2_INCOMMONSEARCHER_H

#include <set>
#include "CompForMult.h"
#include "Searcher.h"
#include "State.h"
using namespace std;
template <class S, class T>
class InCommonSearcher : public Searcher<S, T>{
    int evaluatedNodes;
protected:
    std::multiset<State<T>*,CompForMult<T>> openList;
public:
    InCommonSearcher() : evaluatedNodes(0) {};

   virtual S search(Searchable<T> *searchable) =0;

protected:
    State<T>*popOpenList(){
        evaluatedNodes++;
        auto iter = openList.begin();
        State<T>* getIt = *iter;
        openList.erase(*iter);
        return getIt;
    }
    int getOpenListSize(){
        return (int)openList.size();
    }
    int getNumberOfNodesEvaluate() override {
        return evaluatedNodes;
    }
    void addToOpenList(State<T>* stateAdd){
        openList.insert(stateAdd);
    }
    bool contains(State<T> *stateIt){
        return static_cast<bool>(openList.count(stateIt));
    }


};
#endif //SOLIDPROJECT_EX2_INCOMMONSEARCHER_H
