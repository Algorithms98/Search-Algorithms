#include <iostream>
#include "Search.h"
using namespace std;

int main(int argc, char* argv[]) {

    int start = atoi(argv[1]);
    int destination = atoi(argv[2]);

//    int start = 5;
//    int destination = 12;

    enum Algo{DJIKSTRA = 1, ASTAR, BFSRECURSIVE, DFSRECURSIVE, BFSITERATIVE, DFSITERATIVE };

    Search* matrix = new Search();
    Search *list = new Search();


    list->Load("list");
    matrix->Load("matrix");


    for(int i = DJIKSTRA; i <= DFSITERATIVE; i++ ){

        matrix->Select(i);
        matrix->Execute(start, destination);
        matrix->Stats();
        list->Select(i);
        list->Execute(start, destination);
        list->Stats();
    }


    return 0;
}
