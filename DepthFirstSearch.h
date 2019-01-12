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
    void adjustStateVectors(vector<State<T>> &visited, vector<State<T>> &neighbors);
    string makeDirections(State<T> *currentState);
    string search(Searchable<T> *searchable);
};

#endif //SOLIDPROJECT_EX2_BREADTHFIRSTSEARCH_H
