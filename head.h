//
// Created by Olivier on 02/02/2021.
//

#ifndef ADVENT_LEARN_HEAD_H
#define ADVENT_LEARN_HEAD_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <regex>
#include <cstdlib>
#include <cmath>

using namespace std;

template<typename T>
void printVector(const vector<T> & v){
    for(auto const & e : v){
        cout << e;
    }
    cout << endl;
}

#endif //ADVENT_LEARN_HEAD_H
