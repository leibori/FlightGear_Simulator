//
// Created by ori on 1/10/19.
//

#ifndef SOLIDPROJECT_EX2_MYMATRIX_H
#define SOLIDPROJECT_EX2_MYMATRIX_H
#include "Searchable.h"
#include "unordered_set"
#include "Convertor.h"
#include <list>
#include <vector>

using namespace std;
class MyMatrix : public Searchable<pair<int,int>>{
    vector<vector<int>> matrix;
    vector<string> original;
    int length;
    int width;
    pair<int, int> initState;
    pair<int, int> goalState;
    public:
    MyMatrix(vector<string> input);

    State<pair<int, int>>* getInitialState() override;

    bool isGoalState(const State<pair<int, int>> &st) override;

    State<pair<int, int>> *getGoalState() override;

    vector<State<pair<int,int>>*> getAllpossibleStates( State<pair<int, int>> *s) override;

    vector<string> getOriginalVector() override;

private:
    vector<string>splitIt(string str, string token);

};
#endif //SOLIDPROJECT_EX2_MYMATRIX_H
