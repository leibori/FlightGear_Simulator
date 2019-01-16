#ifndef SOLIDPROJECT_EX2_DEPTHFIRSTSEARCH_H
#define SOLIDPROJECT_EX2_DEPTHFIRSTSEARCH_H
#include <vector>
#include <string>
#include <deque>


#include "Searchable.h"
#include "State.h"
#include "Searcher.h"

template <class S, class T>
class DepthFirstSearch : public Searcher<S, T>{
    int nodesEvaluated = 0;
    deque<State<T>*> openList;
public:
    void adjustStateVectors(vector<State<T>*> &visited, vector<State<T>*> &neighbors) {
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < neighbors.size(); j++) {
                if (visited[i]->equal(neighbors[j])) {
                    if (visited[i]->getCost() > neighbors[j]->getCost()) {
                        visited.erase(visited.begin() + i);
                    } else {
                        neighbors.erase(neighbors.begin() + j);
                    }
                }
            }
        }
    }

    string makeDirections(State<T> *currentState,Searchable<T> *searchable) {
        this->openList.clear();
        vector<string> path;
        string toReturn;
        State<T> *startState = searchable->getInitialState();
        State<T> *current = currentState;
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

    S search(Searchable<T> *searchable) override {
        vector<State<T>*> close;
        this->openList.push_back(searchable->getInitialState());
        while (this->openList.size() > 0) {
            State<T>* state = this->popFromStuck();
            if (!this->containsClose(close, state)){
                close.push_back(state);
            }

            if (state->equal(searchable->getGoalState())){
                return makeDirections(state,searchable);
            }
              //  return this->backTrace(state, searchable);

            vector<State<T> *> successors = searchable->getAllpossibleStates(state);
            for (State<T>* s : successors) {
                //
                if (!this->containsClose(close, s) && ! this->openContains(s)) {
                    this->openList.push_back(s);
                }
            }
        }
    }
      bool openContains(State<T> *stateIt) {
          for (auto it = openList.begin(); it != openList.end(); it++) {
              State<T> *s = *it;
              if (s->equal(stateIt)) {
                  return true;
              }
          }
          return false;
      }
    bool containsClose(vector<State<T>*> &close, State<T> *stateIt) {
        for (auto it = close.begin(); it != close.end(); it++) {
            State<T> *s = *it;
            if (s->equal(stateIt)) {
                return true;
            }
        }
        return false;
    }
    int getNumberOfNodesEvaluate() override {
        return nodesEvaluated;
    }
    State<T>* popFromStuck() {
        this->nodesEvaluated++;
        State<T>* s = openList.back();
        openList.pop_back();
        return s;
    }
};
#endif //SOLIDPROJECT_EX2_BREADTHFIRSTSEARCH_H