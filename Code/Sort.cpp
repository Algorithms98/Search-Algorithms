//
// Created by PRINCE NDHLOVU on 9/14/20.
//

#include "Sort.h"
Sort::Sort() {

    algos.push_back(SortingAlgos::bubbleSort);
    algos.push_back(SortingAlgos::mergeSort);
    algos.push_back(SortingAlgos::insertionSort);
}

Sort::~Sort() {

}

void Sort::Load(string name) {

    nums.clear();
    filename.clear();

    ifstream file(name);
    filename = name;
    string n;

    if(!file.is_open()){
        cout << "Could not open File" << endl;
    }else {

        while (!file.eof()) {
            file >> num;
            nums.push_back(num);
        }
    }
    cout <<"Filename: " << name << " : "<< nums.size() << endl;
    file.close();
}

void Sort::Execute() {

    chrono::high_resolution_clock::time_point time1, time2;

    time1 = chrono::high_resolution_clock::now();

    (*algos[sortAlgo])(nums);

    time2 = chrono::high_resolution_clock::now();

    time = chrono::duration_cast<std::chrono::duration<double>>(time2 - time1);

    Save();
}

void Sort::Display() {

    for(int i = 0; i < nums.size() - 1; i++){
        cout << nums[i] << endl;
    }
}

void Sort::Stats() {

    if(sortAlgo == 0){
        cout << "Bubble Sort Algorithm" << endl;
    }else if(sortAlgo == 1){
        cout << "Insertion Sort Algorithm" << endl;
    }else if(sortAlgo == 2){
        cout << "Merge Sort Algorithm" << endl;
    }

    cout << "Time: " << time.count() << " File " << filename << endl;
}

void Sort::Select(int n) {
    sortAlgo = n;
}

void Sort::Save() {

    ofstream file("saved.txt");

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
        file << nums[i] << endl;
    }
    file.close();
}

void Sort::Configure() {}