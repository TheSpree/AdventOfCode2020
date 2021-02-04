//
// Created by Olivier on 04/02/2021.
//

#include "../head.h"
using namespace std;

void day10();
unsigned long long step(const vector<int> & listOfSteps);

void day10(){
    ifstream MyReadFile("../inputs/day10input");
    string text;
    vector<int> adapterList{};
    while(getline(MyReadFile, text)) {
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        adapterList.push_back(stoi(text));
    }
    MyReadFile.close();
    adapterList.push_back(0);
    sort(adapterList.begin(), adapterList.end());
    adapterList.push_back(adapterList.back()+3);

    long nbOneDiff, nbThreeDiff;
    nbThreeDiff = 0;
    nbOneDiff = 0;
    for(int i = 0; i < adapterList.size()-1; ++i){
        int difference = adapterList.at(i+1)-adapterList.at(i);
        switch (difference) {
            case 1:
                nbOneDiff += 1;
                break;
            case 3:
                nbThreeDiff += 1;
                break;
            default:
                break;
        }
    }
    long multiply (nbOneDiff * nbThreeDiff);
    cout << "Used all : " << multiply << "(" << nbOneDiff << ", " << nbThreeDiff  << ")"<< endl;
    // Part 2
    cout << step(adapterList) << endl;
}

//bottom up algorithm for the problem : "count the ways to reach the nth stair" with the constraint added
unsigned long long step(const vector<int> & listOfSteps){
    vector<int> table{};
    table.push_back(1);
    table.push_back(1);
    table.push_back(2);
    for (int i = 3; i<listOfSteps.back()+1; ++i){
        table.push_back(0);
        if(find(listOfSteps.begin(), listOfSteps.end(), i) != listOfSteps.end()){
            int j = 1;
            while (j <= 3 && (i-j) >= 0 ){
                table.at(i) += table.at(i-j);
                ++j;
            }
        }
    }
    return table.at(listOfSteps.back());
}