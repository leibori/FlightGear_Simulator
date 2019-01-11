//
// Created by ori on 1/10/19.
//

#include "MyMatrix.h"

MyMatrix::MyMatrix(vector<string> input, pair<int, int> initsta, pair<int, int> goalSt,
                   Convertor<vector<vector<int>>, string> *convertors) {
    this->conver = convertors;
    this->matrix = conver->conVecStringToProblem(input);
    this->length = matrix.size();
    this->width = matrix[0].size();
    this->goalState = goalSt;
    this->initState = initsta;
}

State<pair<int, int>> MyMatrix::getInitialState() {
    State<pair<int, int>> sta = State<pair<int, int>>(0, initState, nullptr);
    return sta;
}

bool MyMatrix::isGoalState(const State<pair<int, int>> &st) {
    return st.getState() == goalState;
}

State<pair<int, int>> MyMatrix::getGoalState() {
    State<pair<int, int>> goa = State<pair<int, int>>(0, goalState, nullptr);
    return goa;
}

vector<State<pair<int, int>>> MyMatrix::getAllpossibleStates(State<pair<int, int>> &s) {
    int minimumCol = 0;
    int maximumCol = width - 1;
    int minimumRow = 0;
    int maximumRow = length - 1;
    int i = s.getState().first;
    int j = s.getState().second;
    vector<State<pair<int, int>>> statesPosi;

    if (i - 1 >= minimumRow) {

        pair<int, int> up = make_pair(i - 1, j);
        State<pair<int, int>> upState = State<pair<int, int>>(s.getCost() + matrix[i - 1][j], up, &s);
        if (upState.equal(s)==0 && upState.getCost() != -1) {
            statesPosi.push_back(upState);
        }
    }

    if (i + 1 <= maximumRow) {
        pair<int, int> down = make_pair(i + 1, j);
        State<pair<int, int>> downState = State<pair<int, int>>(s.getCost() + matrix[i + 1][j], down, &s);
        if (downState.equal(s)==0 && downState.getCost() != -1) {
            statesPosi.push_back(downState);
        }
    }

    if (j - 1 >= minimumCol) {
        pair<int, int> left = make_pair(i, j - 1);
        State<pair<int, int>> leftState = State<pair<int, int>>(s.getCost() + matrix[i][j - 1], left, &s);
        if (leftState.equal(s)==0 && leftState.getCost() != -1) {
            statesPosi.push_back(leftState);
        }
    }

    if ((j + 1) <= maximumCol) {
        pair<int, int> right = make_pair(i, j + 1);
        State<pair<int, int>> rightState = State<pair<int, int>>(s.getCost() + matrix[i][j + 1], right, &s);
        if (rightState.equal(s)==0 && rightState.getCost() != -1) {
            statesPosi.push_back(rightState);
        }
    }

    return statesPosi;
}


