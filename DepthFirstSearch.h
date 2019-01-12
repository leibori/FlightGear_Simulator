#ifndef SOLIDPROJECT_EX2_DEPTHFIRSTSEARCH_H
#define SOLIDPROJECT_EX2_DEPTHFIRSTSEARCH_H

#include <vector>
#include <string>

#include "Searchable.h"
#include "State.h"

template <class T>
class DepthFirstSearch {
    int nodesEvaluated = 0;
public:
    void adjustStateVectors(vector<State<T>> &visited, vector<State<T>> &neighbors) {
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < neighbors.size(); j++) {
                if (visited[i].equal(neighbors[j])) {
                    if (visited[i].getCost() > neighbors[j].getCost()) {
                        visited.erase(visited.begin() + i);
                    } else {
                        neighbors.erase(neighbors.begin() + j);
                    }
                }
            }
        }
    }

    string makeDirections(State<T> *currentState) {
        string directions = "";
        if (currentState == nullptr) {
            return "No path available";
        }
        while (currentState->getCameForm() != nullptr) {
            directions = currentState->getDirection() + "," + directions;
            currentState = currentState->getCameForm();
        }
        return directions.substr(0,directions.length() - 1);
    }

    string search(Searchable<T> *searchable) {
        vector<State<T>> closedStates;
        vector<State<T>> neighbors;
        vector<State<T>> stateStack;
        State<T> *shortest = nullptr;
        double minCost;
        bool minFound = false;
        stateStack.push_back(searchable->getInitialState());
        nodesEvaluated = 0;
        while (!stateStack.empty()) {
            nodesEvaluated++;
            State<T> currentState = stateStack[stateStack.size() - 1];
            stateStack.pop_back();
            if (currentState.equal(searchable->getGoalState())) {
                if (!minFound) {
                    minFound = true;
                    minCost = currentState.getCost();
                    shortest = new State<T>(currentState);
                } else if (currentState.getCost() < minCost) {
                    minCost = currentState.getCost();
                    shortest = new State<T>(currentState);
                }
            } else {
                State<T> *copy = new State<T>(currentState);
                neighbors = searchable->getAllpossibleStates(copy);
                adjustStateVectors(closedStates, neighbors);
                adjustStateVectors(stateStack, neighbors);
                for (int i = 0; i < neighbors.size(); i++) {
                    stateStack.push_back(neighbors[i]);
                }
            }
            closedStates.push_back(currentState);
        }
        return makeDirections(shortest);
    }
};

#endif //SOLIDPROJECT_EX2_BREADTHFIRSTSEARCH_H
