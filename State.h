//
// Created by ori on 1/8/19.
//

#ifndef SOLIDPROJECT_EX2_STATE_H
#define SOLIDPROJECT_EX2_STATE_H
#include <string>
using namespace std;
template <class T>
class State {
    double cost{};
    T stateId;
    State<T> *cameForm;
    string direction;
public:

    State(double cost, T stateId, State<T> *cameForm) : cost(cost), stateId(stateId), cameForm(cameForm) {
        this->direction = nullptr;
    }

    double getCost() const {
        return cost;
    }

    void setCost(double cost) {
        State::cost = cost;
    }

    T getState() const {
        return stateId;
    }

    void setState(T state) {
        State::stateId = state;
    }

    State<T> *getCameForm() const {
        return cameForm;
    }
    void setCameForm(State<T> *cameForm) {
        State::cameForm = cameForm;
    }

    const string &getDirection() const {
        return direction;
    }

    void setDirection(const string &direc) {
        this->direction = direc;
    }

    bool equal (State<T> state){
        return this->stateId == state.stateId;
    }
};
#endif //SOLIDPROJECT_EX2_STATE_H
