//
// Created by PRINCE NDHLOVU on 9/28/20.
//

#ifndef CODE_SEARCH_H
#define CODE_SEARCH_H


#include "Algorithm.h"
#include "SearchAlgo.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "Node.h"
#include "Graph.h"
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

class Search: public Algorithm {

private:
    SearchAlgo searching;
    chrono::duration<double> time;
    vector<double> cost;
    vector<int> visitedNodes;
    vector<int> numPaths;
    vector<double> timeTaken;
    vector<Node> currentPath;
    vector<int> dist;
    int nodes;
    int selectedAlgo;
    Graph* nodesOnGraph;
    double price = 0.00;
    double distance = 0.00;
    int currStop;

public:
    Search();
    ~Search();
    void Load(string);
    void Execute(const int, const int);
    void Display();
    void Stats();
    void Select(int);
    void Save();
    void Configure();
    int size();
    double getCost();
    double getDistance();
    double calDistance(double[3], double[3]);

};


#endif //CODE_SEARCH_H
