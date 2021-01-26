//
// Created by PRINCE NDHLOVU on 9/28/20.
//

#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {

}

AdjacencyList::~AdjacencyList() {

}

Node & AdjacencyList::getNode(int node) {
    return adjacencyList[node];
}

void AdjacencyList::makeGraph(string graph, string position, string weight) {

    fstream graphText(graph);
    string line, temp;
    vector<double> data;

    if(!graphText.is_open()){
        cout << "Could not open the file with graph text " << endl;
        return;
    }

    while(!graphText.eof()){

        getline(graphText, line);
        stringstream ss(line);

        while(ss){

            if(!getline(ss, temp, ',')){
                break;
            }
            int put = stoi(temp);
            data.push_back(put);

            //data.push_back(stoi(temp));
        }

        adjacencyList.insert(make_pair(data[0] - 1, Node(data[0])));

        for(int i = 0; i < data.size(); i++){
            adjacencyList[data[0] -1].loadConnections(data[i]);
        }

        data.clear();
    }
    graphText.close();

    fstream positionText(position);

    if(!positionText.is_open()){
        cout << "Could not open the position text file " << endl;
        return;
    }

    while(!positionText.eof()){

        getline(positionText, line);
        stringstream ss(line);

        while(ss){

            if(!getline(ss, temp, ',')){
                break;
            }
            int put = stoi(temp);
            data.push_back(put);

           // data.push_back(stoi(temp));
        }

        if(data.size() == 4){
            double temp[3];
            for(int i = 0; i < 3; i++){
                temp[i] = data[i+1];
            }
            adjacencyList[data[0] -1].setLocation(temp);
            data.clear();
        }
    }
    positionText.close();

    fstream weightText(weight);

    if(!weightText.is_open()){
        cout << "Could not open weight text file " << endl;
        return;
    }

    while(!weightText.eof()){

        getline(weightText, line);
        stringstream ss(line);

        while(ss){

            if(!getline(ss, temp, ',')){
                break;
            }
            int put = stoi(temp);
            data.push_back(put);

            //data.push_back(stoi(temp));
        }


            adjacencyList[data[0] -1].loadWeight(data[1], data[2]);

        data.clear();
    }
    weightText.close();

}

int AdjacencyList::size() {

    return adjacencyList.size();
}

void AdjacencyList::print() {

    for(int i = 0; i < adjacencyList.size(); i++){
        adjacencyList[i].print();
    }

}

Node &AdjacencyList::operator[](int node) {
    return adjacencyList[node];
}

