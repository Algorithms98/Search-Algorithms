//
// Created by PRINCE NDHLOVU on 9/14/20.
//

#ifndef CODE_SORTINGALGOS_H
#define CODE_SORTINGALGOS_H

#include <vector>
#include "Algorithm.h"
#include "Sort.h"

using namespace std;

class SortingAlgos {

private:
    static void merge(vector<int>&, int , int ,int);
    static void mergeSorter(vector<int>& , int, int);

public:
    SortingAlgos(){};
    ~SortingAlgos(){};
    static void bubbleSort(vector<int>&);
    static void insertionSort(vector<int>&);
    static void mergeSort(vector<int>&);

};

#endif //CODE_SORTINGALGOS_H
