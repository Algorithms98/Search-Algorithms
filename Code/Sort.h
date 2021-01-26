//
// Created by PRINCE NDHLOVU on 9/14/20.
//

#ifndef CODE_SORT_H
#define CODE_SORT_H

#include "Algorithm.h"
#include "SortingAlgos.h"
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;


class Sort: public Algorithm {

private:

    vector<void (*) (vector<int>&) > algos;
    chrono::duration<double> time;
    int num;
    vector<int> nums;
    int sortAlgo;
    string filename;

public:

    Sort();
    ~Sort();
    void Load(string);
    void Execute();
    void Display();
    void Stats();
    void Select(int);
    void Save();
    void Configure();

};

#endif //CODE_SORT_H
