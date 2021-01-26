//
// Created by PRINCE NDHLOVU on 9/30/20.
//

#ifndef CODE_EDGES_H
#define CODE_EDGES_H


class Edges {

private:
    int id;
    double weight;
public:
    friend class Node;
    friend class SearchAlgo;
    Edges();
    ~Edges();
    Edges(int);
    Edges(int, double);
    void setWeight(double);
    void setId(int);


};


#endif //CODE_EDGES_H
