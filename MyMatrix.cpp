//
// Created by ori on 1/10/19.
//

#include "MyMatrix.h"

MyMatrix::MyMatrix(vector<string> getIt) {

    vector<string> start = splitIt(getIt[getIt.size()-2],",");
    vector<string >end=  splitIt(getIt[getIt.size()-1],",");
    this->initState =  std::make_pair(stoi(start[0]), stoi(start[1]));
    this->goalState =std::make_pair(stoi(end[0]), stoi(end[1]));
    vector<string> prop =getIt;
    prop.erase(prop.end()-2, prop.end());
    vector<vector<int>> matTemp;
    for (auto iter = prop.begin(); iter != prop.end(); iter++) {
        vector<int> line;
        vector<string> afterSplit = splitIt(*iter,",");
        for (auto &it : afterSplit) {
            line.push_back(std::stoi(it));
        }
        matTemp.push_back(line);
    }
    this->matrix = matTemp;
    this->length = matrix.size();
    this->width = matrix[0].size();
    this->original = getIt;
}

State<pair<int, int>> *MyMatrix::getInitialState() {
    State<pair<int, int>> *sta = new State<pair<int, int>>(0, initState, nullptr);
    return sta;
}

bool MyMatrix::isGoalState(const State<pair<int, int>> &st) {
    return st.getState() == goalState;
}

State<pair<int, int>> *MyMatrix::getGoalState() {
    State<pair<int, int>> *goa = new State<pair<int, int>>(0, goalState, nullptr);
    return goa;
}

vector<State<pair<int, int>>*> MyMatrix::getAllpossibleStates(State<pair<int, int>> *s) {
    int minimumCol = 0;
    int maximumCol = width - 1;
    int minimumRow = 0;
    int maximumRow = length - 1;
    string direc;
    int i = s->getState().first;
    int j = s->getState().second;
    vector<State<pair<int, int>>*> statesPosi;
    if (i - 1 >= minimumRow) {

        pair<int, int> up = make_pair(i - 1, j);
        State<pair<int, int>>* upState = new State<pair<int, int>>(s->getCost() + matrix[i - 1][j], up, s);
        direc = "up";
        upState->setDirection(direc);
        if (s->getDirection() != "none") {
            if (!upState->equal(s->getCameForm()) && (matrix[i - 1][j] != -1)) {
                statesPosi.push_back(upState);
            }
        } else {
            if (matrix[i - 1][j] != -1) {
                statesPosi.push_back(upState);
            }
        }

    }

    if (i + 1 <= maximumRow) {
        pair<int, int> down = make_pair(i + 1, j);
        State<pair<int, int>>* downState = new State<pair<int, int>>(s->getCost() + matrix[i + 1][j], down, s);
        direc = "down";
        downState->setDirection(direc);
        if (s->getDirection() != "none") {
            if (!downState->equal(s->getCameForm()) && (matrix[i + 1][j] != -1)) {
                statesPosi.push_back(downState);
            }
        } else {
            if (matrix[i + 1][j] != -1) {
                statesPosi.push_back(downState);
            }
        }
    }

    if (j - 1 >= minimumCol) {
        pair<int, int> left = make_pair(i, j - 1);
        State<pair<int, int>>* leftState = new State<pair<int, int>>(s->getCost() + matrix[i][j - 1], left, s);
        direc = "left";
        leftState->setDirection(direc);
        if (s->getDirection() != "none") {
            if (!leftState->equal(s->getCameForm()) && (matrix[i][j - 1] != -1)) {
                statesPosi.push_back(leftState);
            }
        } else {
            if (matrix[i][j - 1] != -1) {
                statesPosi.push_back(leftState);
            }
        }
    }

    if ((j + 1) <= maximumCol) {
        pair<int, int> right = make_pair(i, j + 1);
        State<pair<int, int>>* rightState = new State<pair<int, int>>(s->getCost() + matrix[i][j + 1], right, s);
        direc = "right";
        rightState->setDirection(direc);
        if (s->getDirection() != "none") {
            if (!rightState->equal(s->getCameForm()) && (matrix[i][j + 1] != -1)) {
                statesPosi.push_back(rightState);
            }
        } else {
            if (matrix[i][j + 1] != -1) {
                statesPosi.push_back(rightState);
            }
        }
    }

    return statesPosi;
}
//split by specific token
vector<string>MyMatrix:: splitIt(string str, string token) {
    vector<string> result;
    while (str.size()) {
        int index = str.find(token);
        if (index != string::npos) {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)result.push_back(str);
        } else {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

vector<string> MyMatrix::getOriginalVector() {
    return original;
}



