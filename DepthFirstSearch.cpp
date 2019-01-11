#import "DepthFirstSearch.h"

void DepthFirstSearch::adjustStateVectors(vector<State<pair<int, int>>> &visited, vector<State<pair<int, int>>> &neighbors) {

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

string DepthFirstSearch::makeDirections(State<pair<int, int>> *currentState) {
    State<pair<int, int>> *former;
    string directions = "";
    if (currentState == nullptr) {
        return "No path available";
    }
    while (currentState->getCameForm() != nullptr) {
        former = currentState->getCameForm();
        if (former->getState().first > currentState->getState().first) {
            directions = "Up," + directions;
        } else if (former->getState().first < currentState->getState().first) {
            directions = "Down," + directions;
        } else if (former->getState().second > currentState->getState().second) {
            directions = "Left," + directions;
        } else if (former->getState().second < currentState->getState().second) {
            directions = "Right," + directions;
        }
        currentState = former;
    }
    return directions.substr(0,directions.length() - 1);
}

string DepthFirstSearch::search(Searchable<pair<int, int>> *searchable) {
    vector<State<pair<int, int>>>::iterator iterator1;
    vector<State<pair<int, int>>> closedStates;
    vector<State<pair<int, int>>> neighbors;
    vector<State<pair<int, int>>> stateStack;
    State<pair<int, int>> *shortest = nullptr;
    double minCost;
    bool minFound = false;
    stateStack.push_back(searchable->getInitialState());
    nodesEvaluated = 0;
    while (!stateStack.empty()) {
        nodesEvaluated++;
        State<pair<int, int>> currentState = stateStack[stateStack.size() - 1];
        stateStack.pop_back();
        if (currentState.equal(searchable->getGoalState())) {
            if (!minFound) {
                minFound = true;
                minCost = currentState.getCost();
                shortest = new State<pair<int, int>>(currentState);
            } else if (currentState.getCost() < minCost) {
                minCost = currentState.getCost();
                shortest = new State<pair<int, int>>(currentState);
            }
        } else {
            State<pair<int, int>> *copy = new State<pair<int, int>>(currentState);
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
