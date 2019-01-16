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

   string testIt =" 7, 9, 4, 3, 7, 1, 4, 2, 7, 8, 2, 3, 1, 3, 6, 8, 6, 5, 4,-1, 5, 8, 2, 9, 6, 9, 5, 6, 6, 7\n"
                  " 6, 6, 4,-1, 3, 6, 6, 7, 6, 9, 6, 1, 3, 1, 3, 1, 5,-1, 2,-1, 5, 6, 1, 9,16, 7, 4, 8, 2,-1\n"
                  " 9, 6, 6, 5, 9, 6, 5, 1, 9, 6,16,-1,16, 2, 2, 3, 5, 6,-1, 8, 4, 4, 4, 4, 8, 8,-1,16, 2, 6\n"
                  " 1, 7, 4, 2, 9, 5, 8, 2, 1, 9, 1, 8, 8, 6, 2,-1,-1, 5, 5, 7, 8, 4, 8, 8, 9, 5,16, 1, 6,-1\n"
                  " 6, 6, 3, 6, 7, 6, 3,16, 8, 7, 5, 6, 2, 3, 8, 8, 3, 1,-1, 7,16, 1, 5,-1,-1, 3,-1, 5, 1, 7\n"
                  " 9, 6, 4, 6, 4,16, 1, 5, 3, 8,-1,-1,-1,16,-1, 8,-1, 4, 7, 3, 4, 1, 6, 3, 7, 6, 6, 1, 4, 6\n"
                  " 4, 6, 9, 6, 7, 5, 6, 3, 6,16, 2, 9, 4, 6,-1, 3, 6, 6, 6, 3,-1, 1,16, 7,16, 8,-1,16, 6,-1\n"
                  " 6, 3, 5, 5, 9, 2, 7, 6, 5, 4, 2, 2, 8,16, 2, 6, 6, 6, 7, 4, 4, 3,-1, 9, 1,-1,16, 6,-1, 4\n"
                  " 9, 6,16, 1, 1, 8, 4, 9, 6,-1, 6, 1, 4,-1, 5, 5, 1, 3, 1, 4, 6, 5, 6, 7, 4,-1, 6, 5, 5, 4\n"
                  " 8, 4,16, 1, 2,16, 6, 1, 5, 1,-1, 6, 4, 8, 2, 3, 6, 8, 7, 7, 3, 7, 2, 6, 8, 9, 1, 6, 2, 1\n"
                  " 4, 7, 7, 6, 9, 1, 5,16, 2, 9, 9, 6, 6, 3, 6, 6, 5, 6, 8, 3, 7, 3, 5, 6, 6, 3, 6, 3, 6, 8\n"
                  " 4, 8, 9, 1, 9, 4, 6, 1, 5, 6, 7, 7, 1, 5, 9, 8, 7, 6, 6, 6, 5, 4, 8, 2, 8,-1, 2, 3, 2, 2\n"
                  " 6, 1, 7, 7, 1, 5, 2, 5, 4,16, 4, 9, 2, 4, 5, 1, 6, 7, 2, 3, 4, 4,16, 6, 5, 3, 6, 7, 6,16\n"
                  " 5, 5, 7, 5, 8, 7, 4, 6, 9, 6, 3, 9, 4, 6, 3,16, 5, 6, 2,16, 6, 4, 4, 1, 3, 6, 4,16, 1, 6\n"
                  " 8, 4, 8, 6, 2, 3, 5, 9, 5, 9, 5, 2, 8, 1, 4, 8, 4, 6, 6, 5, 9, 2, 6, 7, 7, 1,16, 8,16, 1\n"
                  " 6, 9, 5, 3, 6, 3, 6,16, 3, 8, 2, 6, 8,16, 1, 5, 5, 7, 6, 4, 7, 6, 2,16, 6, 6, 5, 1, 1, 5\n"
                  " 7, 6, 8, 3, 2, 6, 9, 9, 6, 8, 7,16, 1, 1, 5, 1, 9, 7, 7, 5, 5,16, 1, 2, 2, 3, 4, 7, 8, 2\n"
                  "16, 6, 8, 9, 2, 9, 6,16, 2, 9, 6, 3, 1, 9,16, 6,16, 7, 9, 1, 5, 9,16, 5, 6, 5, 8, 1, 1, 1\n"
                  " 1, 2, 8, 9, 9, 6,16, 7,16, 3, 2, 6, 9, 2, 8, 5, 7, 2, 6, 1, 8, 5, 1, 3, 8, 6, 2, 8, 8,16\n"
                  " 9, 8, 1,16, 2, 9,16, 2, 6, 2, 9, 8, 1, 9, 1, 8, 3, 6, 4, 1,16, 5, 8, 2, 9, 6, 2, 9, 3, 9\n"
                  " 2, 1,16, 1,16, 6, 5, 6,16, 5, 3, 7, 2,16, 6, 4,16, 6, 8, 1, 5,16, 8, 4, 6, 2, 4, 6, 9, 7\n"
                  " 2, 5, 5, 1, 9, 7, 6, 9, 4, 5, 6, 7, 1, 6, 4, 5,16, 8, 7, 1, 8, 3, 7, 7, 3, 4, 6, 2, 3, 5\n"
                  " 9, 5, 7, 5, 6, 4, 2, 8, 7, 7, 3, 2, 8, 6, 4, 3, 7, 8, 6, 4, 9, 6, 6, 1, 7, 6,16, 1,16,16\n"
                  " 9, 6, 3,16, 3, 9, 7, 5, 6, 6, 1, 2, 3, 5, 4, 8, 6, 1, 9, 5, 7, 7, 9, 6,-1, 1, 6, 4, 3,16\n"
                  " 7, 1, 1, 6, 6, 5, 6, 6, 9, 8, 3, 4,16, 5, 4, 1,16, 8, 9, 6, 5, 3, 5, 7,-1, 1, 6, 1,16,16\n"
                  " 3, 1, 6, 2, 8, 3, 5, 3, 4, 6, 9, 1, 6, 5, 3, 6, 1, 6, 6, 2,16, 9, 1, 9, 6, 6, 6, 9, 6, 4\n"
                  " 1, 7, 7, 6,16, 3, 3, 6, 3, 1, 6,16, 5, 6,16, 1, 9, 6, 6, 6, 7, 2, 9,16, 2, 6, 1, 5,16, 1\n"
                  " 6, 6, 5, 6, 6, 3, 4,16, 2, 9, 1,16, 2, 4, 9, 3, 8, 6, 6,16, 4, 2, 2, 6, 7, 4, 4, 6, 5, 3\n"
                  " 6,16, 8, 2, 9, 6, 4, 2, 4, 7, 6, 8, 9, 8, 1, 1, 5, 6, 9, 9, 7,16, 5, 1, 7, 1, 6,16, 7, 1\n"
                  " 2,-1, 9, 4, 2, 8, 1, 1, 6, 4, 1,16, 6, 1, 9,16, 4, 6, 6, 5, 9, 9, 6, 6, 6, 7, 1, 8, 6, 3\n"
                  "0,0\n"
                  "29,29";
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