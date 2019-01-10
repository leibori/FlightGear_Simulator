#import "DepthFirstSearch.h"

void DepthFirstSearch::adjustStateVectors(vector<State<pair<int, int>>> &visited, vector<State<pair<int, int>>> &neighbors) {
    vector<State<pair<int, int>>>::iterator iterator1;
    vector<State<pair<int, int>>>::iterator iterator2;
    for (iterator1 = visited.begin(); iterator1 != visited.end(); iterator1++) {
        for (iterator2 = neighbors.begin(); iterator2 != neighbors.end(); iterator2++) {
            if (iterator1->equal(*iterator2)) {
                if (iterator1->getCost() > iterator2->getCost()) {
                    visited.erase(iterator1);
                } else {
                    neighbors.erase(iterator2);
                }
            }
        }
    }
}

string DepthFirstSearch::makeDirections(State<pair<int, int>> *currentState) {
    State<pair<int, int>> *former;
    string directions = "";
    if (currentState == nullptr) {
        return "No path available";
    }
    while (currentState->getCameForm() != nullptr) {
        former = currentState->getCameForm();
        if (former->getState().first > currentState->getState().first) {
            directions = "Down," + directions;
        } else if (former->getState().first < currentState->getState().first) {
            directions = "Up," + directions;
        } else if (former->getState().second > currentState->getState().second) {
            directions = "Left," + directions;
        } else if (former->getState().second < currentState->getState().second) {
            directions = "Right," + directions;
        }
    }
    return directions.substr(0,directions.length() - 1);
}

string DepthFirstSearch::search(Searchable<pair<int, int>> searchable) {
    vector<State<pair<int, int>>>::iterator iterator1;
    vector<State<pair<int, int>>> closedStates;
    vector<State<pair<int, int>>> neighbors;
    vector<State<pair<int, int>>> stateStack;
    State<pair<int, int>> currentState = searchable.getInitialState();
    State<pair<int, int>> *shortest = nullptr;
    double minCost;
    bool minFound = false;
    stateStack.push_back(currentState);
    nodesEvaluated = 0;
    while (!stateStack.empty()) {
        currentState = stateStack.back();
        stateStack.pop_back();
        nodesEvaluated++;
        if (currentState.equal(searchable.getGoalState())) {
            if (!minFound) {
                minFound = true;
                minCost = currentState.getCost();
                shortest = &currentState;
            } else if (currentState.getCost() < minCost) {
                minCost = currentState.getCost();
                shortest = &currentState;
            }
        } else {
            neighbors = searchable.getAllpossibleStates(currentState);
            adjustStateVectors(closedStates, neighbors);
            adjustStateVectors(stateStack, neighbors);
        }
        closedStates.push_back(currentState);
        for (iterator1 = neighbors.begin(); iterator1 != neighbors.end(); iterator1++) {
            stateStack.push_back(*iterator1);
        }
    }
    return makeDirections(shortest);
}
