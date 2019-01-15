#include <iostream>
#include <string>
#include "State.h"
#include <set>
#include <string>
#include "MyMatrix.h"
#include "MatrixConvertor.h"
#include "Searcher.h"
#include "Convertor.h"
#include "Searchable.h"
#include "AStar.h"
#include "BestFirstSearch.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string line1 = "4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8";
    string line2 = "4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4";
    string line3 = "4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7";
    string line4 = "3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7";
    string line5 = "0, 3, 7, 3, 7,-1, 4, 8, 9, 1, 1";
    string line6 = "7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9";
    string line7 = "6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8";
    string line8 = "10, 8, 0, 2, 3, 8, 0, 10, 10, 2, 7";
    string line9 = "5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1";
    string line10 = "7, 7, 5, 10, 8, 10, 1, 6, 9, 9, 1";
    string line11 = "5,10, 1,10, 7, 7, 3,10, 8, 0, 6";
    string line12 = "0,0";
    string line13 = "10,10";

    vector<string> matrix = {line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11, line12,
                             line13};
    Convertor<Searchable<pair<int, int>> *, string> *conve = new MatrixConvertor();
    Searchable<pair<int, int>> *mt = new MyMatrix(matrix);
    State<pair<int, int>> *s = new State<pair<int, int>>(3, mt->getInitialState()->getState(), nullptr);
    vector<State<pair<int, int>> *> x;
    x = mt->getAllpossibleStates(s);
    Searcher<string, pair<int, int>> *b = new Astar<string, pair<int, int>>();
    string sol = b->search(mt);
    std::ofstream o("TestIt.txt",ios::app);

    CacheManager<Searchable<pair<int, int>> *, string> *cash = new FileCacheManager<Searchable<pair<int, int>> *, string>("TestIt.txt", conve);

    if( cash->isExistSol(mt)){
        string sollllo = cash->getSol(mt);
    }
    else{
        cash->savePS(mt,sol);
    }



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