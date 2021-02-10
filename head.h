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
#include <cstdarg>

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

vector<string> split(string text, const string & separator, const string & separator2){
    vector<string> splitted;
    while(text.find(separator) != string::npos && text.find(separator2) != string::npos){
        if(text.find(separator) < text.find(separator2)){
            splitted.push_back(text.substr(0, text.find(separator)));
            text.erase(0, text.find(separator)+separator.size());
        }else{
            splitted.push_back(text.substr(0, text.find(separator2)));
            text.erase(0, text.find(separator2)+separator2.size());
        }
    }
    splitted.push_back(text);
    return splitted;
}

vector<string> extractPattern(string text, const vector<string> & pattern){
    vector<string> extractedString{};
    bool patternMatched = true;
    for (int i = 0; i < pattern.size()-1 && patternMatched; ++i) {
        if(text.find(pattern.at(i+1), text.find(pattern.at(i))) == string::npos){
            patternMatched = false;
        }
    }
    if(!patternMatched){
        cout << "Pattern not matched." << endl;
        return extractedString;
    }else{
        for(const string & p : pattern){
            string extracted = text.substr(0, text.find(p));
            if (!extracted.empty()){
                extractedString.push_back(extracted);
            }
            text.erase(0, (text.find(p)+p.size()));
        }
        if (!text.empty()){
            extractedString.push_back(text);
        }
    }
    return extractedString;
}


#endif //ADVENT_LEARN_HEAD_H
