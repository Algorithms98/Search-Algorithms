//
// Created by PRINCE NDHLOVU on 9/28/20.
//

#ifndef CODE_ADJACENCYMATRIX_H
#define CODE_ADJACENCYMATRIX_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Graph.h"
#include "Node.h"

class AdjacencyMatrix: public Graph{

private:
    vector<Node> adjacencyMatrixv;
public:
    AdjacencyMatrix();
    ~AdjacencyMatrix();
    Node& getNode(int);
    Node&operator[](int);
    void print();
    int size();
    void makeGraph(string, string, string);

};

#endif //CODE_ADJACENCYMATRIX_H
