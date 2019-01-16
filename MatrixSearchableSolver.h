#ifndef SOLIDPROJECT_EX2_SEARCHABLESOLVER_H
#define SOLIDPROJECT_EX2_SEARCHABLESOLVER_H

#include "AStar.h"
#include "Solver.h"

template <class Problem, class Solution>
class MatrixSearchableSolver : public Solver<Problem,Solution> {
    Astar<Solution,pair<int,int>>* astar = new Astar<Solution,pair<int,int>>();
public:
    Solution solve(Problem problem) {
        return astar->search(problem);
    }
};

#endif //SOLIDPROJECT_EX2_SEARCHABLESOLVER_H
