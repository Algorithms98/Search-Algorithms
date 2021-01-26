//
// Created by PRINCE NDHLOVU on 9/28/20.
//

#include "Search.h"

Search::Search() {

}

Search::~Search() {

}

//Load data into the adjacency list and matrix
void Search::Load(string type) {

    string file1 = "/Users/princendhlovu/Desktop/lab-2-searching-Algorithms98/Data/SampleGraph/graph.txt";
    string file2 = "/Users/princendhlovu/Desktop/lab-2-searching-Algorithms98/Data/SampleGraph/positions.txt";
    string file3 = "/Users/princendhlovu/Desktop/lab-2-searching-Algorithms98/Data/SampleGraph/weights.txt";

//    string file1 = "/Users/princendhlovu/Desktop/lab-2-searching-Algorithms98/Data/large100/largeGraph.txt";
//    string file2 = "/Users/princendhlovu/Desktop/lab-2-searching-Algorithms98/Data/large100/largePositions.txt";
//    string file3 = "/Users/princendhlovu/Desktop/lab-2-searching-Algorithms98/Data/large100/largeWeights.txt";


    if(type == "list"){
        nodesOnGraph = new AdjacencyList();
        currStop = 1;
    } else if(type == "matrix"){
        nodesOnGraph = new AdjacencyMatrix();
        currStop = 2;
    }else{
        cout << "Enter list or matrix.  \n";
        return;
    }

    if(type == "list"){
        nodesOnGraph->makeGraph(file1, file2, file3);
        currentPath.clear();
        searching.initGraph(nodesOnGraph);
    } else if(type == "matrix"){
        nodesOnGraph->makeGraph(file1, file2, file3);
        currentPath.clear();
        searching.initGraph(nodesOnGraph);
    }else{
        cout << "This is the conditional in Load method of Search.cpp \n";
        return;
    }

}

void Search::Configure() {

}

void Search::Execute(const int start, const int destination) {

    currentPath.clear();
    chrono::high_resolution_clock::time_point time1, time2;

    time1 = chrono::high_resolution_clock::now();

   switch(selectedAlgo){
       case 1:
           //searching.Djikstra(start, destination);
           break;
       case 2:
          // searching.aStar(start, destination);
           break;
       case 3:
           searching.bfsRecursive(start, destination);
           break;
       case 4:
           searching.dfsRecursive(start, destination);
           break;
       case 5:
           searching.bfsIterative(start, destination);
           break;
       case 6:
           searching.dfsIterative(start, destination);
           break;
       default:
           cout << "This wasn't necessary probably \n";
           break;
   }

    time2 = chrono::high_resolution_clock::now();

    time = chrono::duration_cast<std::chrono::duration<double>>(time2 - time1);

    currentPath = searching.getPath();

    if(currentPath.size() == 0){
        price = 0;
        nodes = 0;
        distance = 0;
        cost.push_back(0);
        visitedNodes.push_back(0);
        numPaths.push_back(0);
        timeTaken.push_back(0);
        dist.push_back(0);
    } else{
        cost.push_back(getCost());
        visitedNodes.push_back(searching.getVisited());
        numPaths.push_back(currentPath.size());
        timeTaken.push_back(time.count());
        dist.push_back(getDistance());
    }
}

void Search::Select(int num) {

    selectedAlgo = num;
}

void Search::Stats() {

    switch(selectedAlgo){
        case 1:
            cout << " Djikstra " << endl;
            break;
        case 2:
            cout << "A* " << endl;
            break;
        case 3:
            cout << "BFS Recursive " << endl;
            break;
        case 4:
            cout << "DFS Recursive " << endl;
            break;
        case 5:
            cout << "BFS Iterative "<< endl;
            break;
        case 6:
            cout << "DFS Iterative " << endl;
            break;

    }

    switch(currStop){
        case 1:
            cout << "Adjacency List " << endl;
            break;
        case 2:
            cout << "Adjacency Matrix " << endl;
            break;
    }

    cout << "Path: ";

    if(currentPath.size() == 0){

        cout << "No path was found";

    }else{

        for(int i = 0; i < currentPath.size(); i++){

            if(i < currentPath.size() - 1){
                cout << currentPath[i].id << ", ";
            }

            else{
                cout << currentPath[i].id;
            }
        }
    }

    cout << endl;
    cout << "Number of nodes in explored path: " << searching.getVisited() << endl;
    cout << "Number of nodes in returned path: " << currentPath.size() << endl;
    cout << "Total time of execution: " << time.count() << endl;
    cout << "Cost of path: " << price << endl;
    double x = getDistance();
    cout << "Distance of path: " << x << endl;
    cout << endl;
    cout << endl;

}

int Search::size() {
    int num = nodesOnGraph->size();
    return num;
}

double Search::getCost() {

    for(int i = 0; i < currentPath.size() - 1; i++){
        price += currentPath[i].getWeight(currentPath[i+1].id);
    }

    return price;
}

double Search::getDistance() {

    if(searching.totalDistance == 0){
        for(int i = 0; i < currentPath.size(); i++){
            distance += calDistance(nodesOnGraph->getNode(currentPath[i].id - 1).location, nodesOnGraph->getNode(currentPath[i+1].id - 1).location );
        }
        return distance;
    }
    else{
        return searching.totalDistance;
    }
}

double Search::calDistance(double num0[3], double num1[3]) {

    double a = (num0[0] - num1[0]) * (num0[0] - num1[0]);
    double b = (num0[1] - num1[1]) * (num0[1] - num1[1]);
    double c = (num0[2] - num1[2]) * (num0[2] - num1[2]);

    return a+b+c;
}

void Search::Save() {

}

void Search::Display() {

    cout << "The graphs have been traversed " << endl;
}



