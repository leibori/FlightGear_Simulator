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
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include <iostream>
#include <fstream>

using namespace std;
vector<string> splitIt(string str, string token) {
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

int main() {
   /* string line1 = "4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8";
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
    string line13 = "10,10";*/

   string testIt ="15, 7, 7, 6, 9, 5, 2, 6, 1, 2,15, 1, 7, 9, 8, 5,15, 6, 5, 5, 9,-1, 2, 3, 2, 5,15, 3\n"
                  " 2, 3, 5, 3, 4, 5, 4, 2,15, 6, 9, 9, 8, 3, 5, 1, 1,-1, 1, 7, 4, 7, 5, 4, 9,15, 7, 4\n"
                  " 7,15, 8, 5, 9, 2, 3, 8,15, 5, 3, 7, 6, 9, 4, 5, 2, 6, 5, 9, 5, 7, 4, 5, 3, 4, 4, 5\n"
                  " 3, 1, 3, 4, 3, 4, 1, 1, 4,15, 7, 4, 2, 5, 9, 3, 6, 4, 4, 8, 5, 3, 1, 7, 5, 7, 5, 5\n"
                  " 7, 3, 5, 4, 7, 9, 9,15, 4, 3, 7, 5,-1, 2, 4, 2, 1, 9, 4, 5,-1, 3, 4, 3,-1,-1, 3,-1\n"
                  " 3, 9, 2,15, 7,15, 1,15, 3,15, 4, 6, 2, 8, 8, 5, 5, 9, 5, 8, 7,-1, 3, 4, 2, 6, 3, 6\n"
                  " 3, 7, 5,15,15, 7, 2,15, 2, 8, 6, 1, 8, 6, 5, 1, 2,-1, 1, 5, 2, 8, 6, 9, 3, 6,15, 7\n"
                  " 4, 1, 9, 4,15, 5,15, 1, 3,15, 9, 4, 9, 2, 3, 2,15, 3, 3, 8, 1, 3, 1, 5, 5, 6, 9, 6\n"
                  " 4,15, 2, 9, 9,15, 6,15, 7,15, 6, 7, 1, 1,15, 9, 4, 5, 9, 4, 5, 6, 3, 1, 6,15, 5, 3\n"
                  " 8, 5, 2,15, 1,15, 1, 7, 5, 1, 9, 5, 4, 8, 6, 6, 6, 6, 5, 8,15, 1, 3, 5, 6, 5, 3, 9\n"
                  " 8, 7, 5, 7, 7, 4, 5, 1, 5,15, 8, 1, 1, 5, 7, 3,15, 5,15, 3, 7, 6, 8, 9, 1, 8, 9, 5\n"
                  " 5, 4, 6, 5, 5, 3, 7, 3, 1, 5, 8, 9, 3, 4, 8, 8, 9, 2, 4,15,-1, 5, 7, 8, 2, 5, 5, 4\n"
                  " 3, 6,-1, 7,-1, 7, 6, 8, 7, 5, 5, 1, 5, 6, 1, 4, 8, 3,15, 3, 1, 5,15,-1, 4, 9, 2, 8\n"
                  " 7, 9, 3, 6, 5, 7, 7, 5, 9, 6, 2, 1, 3,15, 5, 2, 9, 5, 4, 3,15, 6,-1, 2, 5, 9, 2, 4\n"
                  " 5, 4, 3, 2,-1, 3, 7, 8,-1, 2, 5, 3, 5, 2, 9, 2, 5, 4,15, 8, 6, 2, 8, 8, 6, 5, 9, 8\n"
                  " 2, 1, 8, 5, 7,-1, 5, 9, 2, 7, 4,15,15, 5, 1, 8, 6, 5, 7, 1, 6, 5, 3, 5, 3, 3, 5, 2\n"
                  " 8, 1, 5, 9, 5, 4, 1, 9, 1, 7, 1,15, 5, 3, 2,15, 7, 3, 7, 5, 5, 7, 5, 6,15, 5,-1, 1\n"
                  " 1, 5, 7, 5, 6, 8, 2, 5, 6, 2,15, 2, 8, 8, 5, 5, 6, 8, 5, 8, 4, 2, 8, 1, 2, 9, 1, 2\n"
                  " 7, 4, 2, 4, 9, 3, 7, 8, 9, 9,15, 9, 7, 8, 2, 5, 2, 5, 4, 2,-1,15,15,15, 2, 7, 5, 3\n"
                  "15, 5,15, 4, 3, 3, 1, 4, 3, 5, 1,15, 2, 5, 4, 3, 8, 8, 4, 5, 5, 2,-1, 4, 4, 7,15, 8\n"
                  " 3, 7, 7, 4, 4, 9, 1, 3, 5, 3, 8, 6, 1, 4, 9, 7, 5, 5, 8, 9, 8, 3,15, 1,15, 5, 6, 8\n"
                  " 2, 8, 8, 1, 5, 1, 4, 5, 5, 2, 6, 2, 8, 3, 2, 2, 2, 4, 4, 8, 5, 1, 6,15, 7, 9, 3, 1\n"
                  " 1, 7, 6, 7, 9,15, 1, 5, 5, 4, 3, 5, 7,15, 7, 5, 2,15, 9, 2, 6, 6, 9, 1, 8, 5, 4, 2\n"
                  "15, 2, 5, 1, 4, 6, 5, 9, 1, 1, 4, 8, 6, 7, 2, 7, 6, 1, 6, 8, 8, 5, 5, 3, 3, 9, 5,15\n"
                  " 5, 9, 4, 3, 7, 5, 2, 7, 5, 2, 1, 4, 9, 8, 5, 4, 7, 3,15,-1, 5, 4, 9, 8, 8, 2, 4, 5\n"
                  " 3, 2,15, 7, 5, 6, 6, 4, 5, 5, 7, 5, 5, 5, 9, 8, 1, 2, 5, 1, 7, 5, 6, 3,15, 5, 4, 7\n"
                  " 1, 4, 5,15, 2, 6, 6, 7, 4, 2, 3, 2, 4,15, 7, 4,15, 4, 6, 8, 2, 1, 7, 3,15, 8, 8, 5\n"
                  " 2, 1, 8, 5, 9, 4, 3, 5, 3, 4, 5, 1, 8, 9, 5, 9, 2, 8, 8, 7,15, 1, 9,15, 6, 8, 4, 2\n"
                  "0,0\n"
                  "27,27";
    vector<string> matrix = splitIt(testIt,"\n");
   // vector<string> matrix ={line1,line2,line3,line4,line5,line6,line7,line8,line9,line10,line11,line12,line13};
    Convertor<Searchable<pair<int, int>> *, string> *conve = new MatrixConvertor();
    Searchable<pair<int, int>> *mt = new MyMatrix(matrix);
    State<pair<int, int>> *s = new State<pair<int, int>>(3, mt->getInitialState()->getState(), nullptr);
    vector<State<pair<int, int>> *> x;
    x = mt->getAllpossibleStates(s);
    //Searcher<string, pair<int, int>> *b = new Astar<string, pair<int, int>>();
    Searcher<string,pair<int, int>> *b = new DepthFirstSearch<string,pair<int, int>>();
    string sol = b->search(mt);
    int yupido = b->getNumberOfNodesEvaluate();

    std::ofstream o("TestIt.txt",ios::app);

    CacheManager<Searchable<pair<int, int>> *, string> *cash = new FileCacheManager<Searchable<pair<int, int>> *, string>("TestIt.txt", conve);

    if( cash->isExistSol(mt)){
        string sollllo = cash->getSol(mt);
    }
    else{
        cash->savePS(mt,sol);
    }

    return 0;
}