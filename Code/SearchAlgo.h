//
// Created by PRINCE NDHLOVU on 9/28/20.
//

#ifndef CODE_SEARCHALGO_H
#define CODE_SEARCHALGO_H

#include "Graph.h"
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include <iostream>
#include <algorithm>
#include "Node.h"
#include <queue>
#include <stack>
#include <cmath>

class SearchAlgo{

private:
    vector<Node> curr;
    int visitedNum;
    int totalDistance = 0;
    Graph * nodes;

public:
    friend class Search;
    SearchAlgo();
    ~SearchAlgo();
    void Djikstra(const int, const int);
    void aStar(const int, const int);
    int getVisited();
    vector<Node>& getPath();
    void bfsRecursive(const int, const int);
    void dfsRecursive(const int, const int);
    vector<Node>& bfs(vector<bool>&, vector<Node>&, queue<Node>&, const int, const int );
    vector<Node>& dfs(vector<bool>&, vector<Node>&,const int, const int);
    vector<Node> bfsIterative(const int, const int);
    vector<Node> dfsIterative(const int, const int);
    void initGraph(Graph*&);
    void findPath(vector<Node>);
    int miniFunc(const int, vector<float>&, vector<bool>&);

};

#endif //CODE_SEARCHALGO_H
