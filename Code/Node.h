//
// Created by PRINCE NDHLOVU on 9/28/20.
//

#ifndef CODE_NODE_H
#define CODE_NODE_H

#include <vector>
#include <iostream>
#include "Edges.h"
using namespace std;

class Node{

private:
    int id;
    double location[3];
    vector<Edges> nodeConnections;
    friend class AdjacencyMatrix;
    friend class Search;
    friend class SearchAlgo;

public:
    Node();
    ~Node();
    Node(int);
    Node(int, double[3]);
    void print();
    bool isConnected(int);
    double getWeight(int);
    void loadWeight(int, double );
    void loadConnections(int);
    void setLocation(double[3]);

};

#endif //CODE_NODE_H
