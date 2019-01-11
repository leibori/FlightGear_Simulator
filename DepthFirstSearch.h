#ifndef SOLIDPROJECT_EX2_DEPTHFIRSTSEARCH_H
#define SOLIDPROJECT_EX2_DEPTHFIRSTSEARCH_H

#include <vector>
#include <string>

#include "Searchable.h"
#include "State.h"

class DepthFirstSearch {
    int nodesEvaluated = 0;
public:
    void adjustStateVectors(vector<State<pair<int, int>>> &visited, vector<State<pair<int, int>>> &neighbors);
    string makeDirections(State<pair<int, int>> *currentState);
    string search(Searchable<pair<int, int>> *searchable);
};

#endif //SOLIDPROJECT_EX2_BREADTHFIRSTSEARCH_H
