#include <iostream>
#include <string>

#include <set>
#include <string>
#include "MyMatrix.h"
#include "MatrixConvertor.h"
#include "Searcher.h"
#include "State.h"
#include "Convertor.h"
#include "Searchable.h"

#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"

using namespace std;
int main() {

    string line1 = "1,2,100";
    string line2 = "200,3,4";
    string line3 = "1000,500000,5";

    vector<string> matrix = {line1,line2,line3};
    pair<int, int> enter = make_pair(0,0);
    pair<int, int> exit = make_pair(2,2);
    Convertor<vector<vector<int>>,string>* convertors = new MatrixConvertor() ;
    Searchable<pair<int, int>>* mt = new MyMatrix(matrix,enter,exit,convertors);
    //string move[4] = {"Up","Down","Left","Right"};


    BreadthFirstSearch<pair<int, int>> bfs;
    cout << bfs.search(mt) << endl;
    //State<vector<int>> s = State<vector<int>>(enter, 3, NULL);
    //list<State<vector<int>>> x;
    //x = mt->getAllPossibleStates(s);
    //ISearcher<vector<State<vector<int>>>,vector<int>> b = new BestFirstSearch<vector<State<vector<int>>*>,vector<int>>();
    //vector<State<vector<int>>*> sol = b->search(mt);
/*
    State<int> a = State<int>();
    State<int> b = State<int>();
    State<int> c = State<int>();
    State<int> d = State<int>();
    a.setCost(100);
    b.setCost(4);
    c.setCost(50);
    d.setCost(75);

    set<State<int>,CompareCost<int>> ss;
    ss.insert(a);
    ss.insert(b);
    ss.insert(c);
    ss.insert(d);

    while (!ss.empty())
    {
        auto it = ss.begin();
        State<int> sa = *it;
        cout << sa.getCost() << endl;
        ss.erase(it);
    }
*/

    /*
    string str = "hello";
    StringReverser sr = StringReverser(str);
    sr.reverseStr();
    cout << sr.reverseStr() << endl;*/
    return 0;
}