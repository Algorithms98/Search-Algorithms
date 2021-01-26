//
// Created by PRINCE NDHLOVU on 9/28/20.
//

#ifndef CODE_GRAPH_H
#define CODE_GRAPH_H

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class Graph {

public:

    virtual void makeGraph(string, string, string) = 0;
    virtual void print() = 0;
    virtual int size() = 0;
    virtual Node& getNode(int) = 0;
    virtual Node&operator[](int) = 0;

};


#endif //CODE_GRAPH_H
