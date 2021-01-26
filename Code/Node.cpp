//
// Created by PRINCE NDHLOVU on 9/28/20.
//

#include "Node.h"


Node::Node() {
}

Node::Node(int num) {
    id = num;
}

Node::Node(int num, double loc[3]) {

    id = num;
    location[0] = loc[0];
    location[1] = loc[1];
    location[2] = loc[2];

}

Node::~Node() {

}

double Node::getWeight(int num) {

    for(int i = 0; i < nodeConnections.size(); i++){
        if(nodeConnections[i].id == num){
            return nodeConnections[i].weight;
        }
    }
    return 0;
}

bool Node::isConnected(int num) {

    for(int i = 0; i < nodeConnections.size();i++){
        if(nodeConnections[i].id == num){
            return true;
        }
    }

    return false;
}

void Node::loadConnections(int num) {

    nodeConnections.emplace_back(Edges(num));

}

void Node::loadWeight(int num, double weights) {
//  Edges* myob = new Edges(num);
    for(int i = 0; i < nodeConnections.size(); i++){
        if(num == nodeConnections[i].id){
            nodeConnections[i].setWeight(weights);
        }
    }
}

void Node::setLocation(double loc[3]) {

    location[0] = loc[0];
    location[1] = loc[1];
    location[2] = loc[2];
}

void Node::print() {

    cout << id << endl;
    cout << location[0] << ", " << location[1] << ", " << location[2] << endl;
    for(int i = 0; i < nodeConnections.size(); i++){
        cout << nodeConnections[i].id << endl;
    }

}