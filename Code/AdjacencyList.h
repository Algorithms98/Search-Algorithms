//
// Created by PRINCE NDHLOVU on 9/28/20.
//

#ifndef CODE_ADJACENCYLIST_H
#define CODE_ADJACENCYLIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include "Graph.h"
#include "Node.h"

using namespace std;

class AdjacencyList: public Graph {

private:
    map<int, Node> adjacencyList;

public:
    AdjacencyList();
    ~AdjacencyList();
    Node& getNode(int);
    Node&operator[](int);
    void print();
    int size();
    void makeGraph(string, string, string);

};


#endif //CODE_ADJACENCYLIST_H
