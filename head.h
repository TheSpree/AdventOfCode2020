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
    if (v.size()>=1){
        cout << v.at(0) ;
        for(int i = 1; i < v.size(); ++i){
            cout << ", " << v.at(i);
        }
        cout << endl;
    }else{
        cout << "Vector is empty" <<endl;
    }

}

vector<string> split(string text, const string & separator){
    vector<string> splitted;
    while(text.find(separator) != string::npos){
        splitted.push_back(text.substr(0, text.find(separator)));
        text.erase(0, text.find(separator)+separator.size());
    }
    splitted.push_back(text);
    return splitted;
}


#endif //ADVENT_LEARN_HEAD_H
