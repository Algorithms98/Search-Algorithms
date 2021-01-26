//
// Created by PRINCE NDHLOVU on 9/28/20.
//

#include "SearchAlgo.h"

SearchAlgo::SearchAlgo() {
    visitedNum = 0;
}

SearchAlgo::~SearchAlgo() {

}

void SearchAlgo::aStar(const int start, const int end) {

    curr.clear();
    visitedNum = 0;

    int length = nodes->size();
    vector<float> weight(length, 1000);
    vector<bool> seen(length, false);
    weight[start-1] = 0;
    int minimum = 1 + miniFunc(length,weight, seen);
    seen[minimum-1] = true;

    for(int i = 0; i < pow(length, 2); i++){

         minimum = 0 + miniFunc(length,weight, seen);
        vector<Edges> exploredPaths = nodes->getNode(minimum).nodeConnections;
        seen[minimum-1] = true;

        if(minimum == end){
            curr.push_back(minimum);
            totalDistance = weight[end-1];
            ++visitedNum;
        }

        for(int j = 0; j < exploredPaths.size(); j++){
            float temp = nodes->getNode(minimum).getWeight(exploredPaths[i].id);
            if(weight[minimum-1] + nodes->getNode(minimum).getWeight(exploredPaths[j].id) < weight[exploredPaths[j].id - 1]  && !seen[exploredPaths[j].id]){
                for(int k =0;j < curr.size(); k++){
                    if(minimum == curr[k].id){
                        curr.push_back(minimum);
                        ++visitedNum;
                    }
                }

                weight[exploredPaths[j].id - 1] = temp * nodes->getNode(minimum).getWeight(exploredPaths[j].id)+ weight[minimum-1];

                if(minimum == end){
                    totalDistance = weight[end-1];
                }
            }
        }
    }

}

void SearchAlgo::Djikstra(const int start, const int end) {

    curr.clear();
    visitedNum = 0;
    int length = nodes->size();
    vector<float> weight(length, 1000);
    vector<bool> seen(length, false);
    weight[start-1] = 0;

    int dest = pow(length, 2);


    for(int i = 0; i < dest; i++){

        int minimum = 0 + miniFunc(length,weight, seen);
        vector<Edges> exploredPaths = nodes->getNode(minimum).nodeConnections;
        seen[minimum-1] = true;

        if(minimum == end){
            curr.push_back(minimum);
            totalDistance = weight[end-1];
            ++visitedNum;
        }

        for(int j = 0; j < exploredPaths.size(); j++){

            if(((weight[minimum-1] + nodes->getNode(minimum).getWeight(exploredPaths[j].id) )< weight[exploredPaths[j].id - 1])  && !seen[exploredPaths[j].id]){
                for(int k =0;j < curr.size(); k++){
                    if(minimum == curr[k].id){
                        curr.push_back(minimum);
                        ++visitedNum;
                    }
                }

                weight[exploredPaths[j].id - 1] =  nodes->getNode(minimum).getWeight(exploredPaths[j].id)+ weight[minimum-1];

                if(minimum == end){
                    totalDistance = weight[end-1];
                    cout << "Total Distance :" << totalDistance << endl;
                }
            }
        }
    }

}

vector<Node> SearchAlgo::bfsIterative(const int start, const int end) {
    curr.clear();
    int length = nodes->size();
    vector<bool> seen(length, false);
    vector<Edges> findConnections;
    queue<Node> nodeQue;
    nodeQue.push(nodes->getNode(start - 1));
    while(!nodeQue.empty()){
        Node currNode = nodeQue.front();
        curr.push_back(currNode);
        if(end == currNode.id){
            visitedNum = curr.size();
            findPath(curr);
            return curr;
        }
        seen[currNode.id - 1] = true;
        nodeQue.pop();
        findConnections = nodes->getNode(currNode.id-1).nodeConnections;
        for(int i = findConnections.size()-1; i >= 0; i--){
            if(findConnections[i].id != -1){
                if(!(seen[findConnections[i].id - 1])){
                    seen[findConnections[i].id - 1] = true;
                    nodeQue.push(nodes->getNode(findConnections[i].id - 1));
                }
            }
        }
    }

    visitedNum = curr.size();
    findPath(curr);
    return curr;
}

vector<Node> SearchAlgo::dfsIterative(const int start, const int end) {
    curr.clear();
    int length = nodes->size();
    vector<bool> seen(length, false);
    vector<Edges> findConnections;
    stack<Node> nodeStack;
    nodeStack.push(nodes->getNode(start-1));
    while(!nodeStack.empty()){
        Node currNode = nodeStack.top();
        curr.push_back(currNode);
        seen[currNode.id - 1] = true;
        nodeStack.pop();
        ++visitedNum;

        if(end == currNode.id){
            return curr;
        }
        findConnections = nodes->getNode(currNode.id-1).nodeConnections;
        for(int i = findConnections.size()-1; i >= 0; i--){
            if(findConnections[i].id != -1){
                if(!(seen[findConnections[i].id - 1])){
                    seen[findConnections[i].id - 1] = true;
                    nodeStack.push(nodes->getNode(findConnections[i].id - 1));
                }
            }
        }

    }
    return curr;
}

void SearchAlgo::bfsRecursive(const int start, const int end) {

    curr.clear();
    visitedNum = 0;
    queue<Node> nodeQue;
    int length = nodes->size();
    vector<bool> seen(length, false);
    nodeQue.push(nodes->getNode(start-1));
    bfs(seen,curr,nodeQue,start,end);
    visitedNum = curr.size();
    findPath(curr);

}

void SearchAlgo::dfsRecursive(const int start, const int end) {

    curr.clear();
    visitedNum = 0;
    int length = nodes->size();
    vector<bool> seen(length, false);
    dfs(seen,curr,start,end);

}

vector<Node> &SearchAlgo::bfs(vector<bool> & seen, vector<Node> & currentPath, queue<Node> & nodeQue, const int start, const int end) {
    seen[start - 1] = true;
    vector<Edges> findConnections;
    Node currNode = nodeQue.front();
    currentPath.push_back(currNode);

    if(end == start){
        return currentPath;
    }
    findConnections = nodes->getNode(currNode.id - 1).nodeConnections;
    for(int i = 0; i < findConnections.size(); i++){
     if(findConnections[i].id != -1){
         if(!(seen[findConnections[i].id - 1])){
             seen[findConnections[i].id - 1] = true;
             nodeQue.push(nodes->getNode(findConnections[i].id - 1));
         }
     }
    }
    nodeQue.pop();
    return bfs(seen, currentPath,nodeQue ,nodeQue.front().id,  end);
}

vector<Node> &SearchAlgo::dfs(vector<bool> & seen, vector<Node> & currentPath, const int start, const int end) {
    seen[start - 1] = true;
    vector<Edges> findConnections;
    ++visitedNum;
    currentPath.push_back(nodes->getNode(start-1));

    if(end == start){
        return currentPath;
    }

    findConnections = nodes->getNode(start-1 ).nodeConnections;
    for(int i = 0; i < findConnections.size(); i++){
        if(findConnections[i].id != -1){
            if(!(seen[findConnections[i].id - 1])){
               return dfs(seen, currentPath, findConnections[i].id, end);
            }
        }
    }

    return currentPath;
}

void SearchAlgo::initGraph(Graph *& obj) {
    nodes = obj;
}

void SearchAlgo::findPath(vector<Node> path) {

    int two_steps_back = path.size()-2;
    int one_step_back = path.size()-1;
    vector<Node> temp;
    temp.push_back(path[one_step_back]);

    while(two_steps_back > 0){

        if(nodes->getNode(path[one_step_back].id -1).isConnected(path[two_steps_back].id)){
            temp.push_back(path[two_steps_back]);
            one_step_back = two_steps_back;
        }
        two_steps_back--;
    }
    temp.push_back(path[0]);
    reverse(temp.begin(), temp.end());
    path = temp;
}

int SearchAlgo::miniFunc(const int num, vector<float>& path, vector<bool>& seen) {

   int index = -1;
   double minimum = 1000.00;
    for(int i = 0; i < num; i++){
        if(!seen[i] && path[i] <= minimum){
            minimum = path[i];
            index = i;
        }
    }
    return index;
}

int SearchAlgo::getVisited() {
    return visitedNum;
}

vector<Node>& SearchAlgo::getPath() {
    return curr;
}


