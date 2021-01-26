//
// Created by PRINCE NDHLOVU on 9/30/20.
//

#ifndef CODE_ALGORITHM_H
#define CODE_ALGORITHM_H

#include <iostream>
#include <string>
using namespace std;

class Algorithm{

public:

    virtual void Load(string) = 0;
    virtual void Execute(const int, const int) = 0;
    virtual void Display() = 0;
    virtual void Stats() = 0;
    virtual void Select(int) = 0;
    virtual void Save() = 0;
    virtual void Configure() = 0;

//    Load [Takes a filename in and can read input data file, can be implemented differently as long as it loads file]
//    Execute [Executes the search algorithm]
//    Display [Prints solution to screen]
//    Stats [Prints algorithm name, execution time and number of records analyzed to screen in a readable format]
//    Select [enum , int, id or string passed as input and loads corresponding algorithm to interface]
//    Save [Saves solution to file path given as input]
//    Configure [Future expandability ]
};

#endif //CODE_ALGORITHM_H
