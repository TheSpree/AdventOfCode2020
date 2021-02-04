//
// Created by Olivier on 02/02/2021.
//

#include "head.h"

void day1(){
    ifstream MyReadFile("../inputs/day1input");
    string text;
    vector<int> list({});
    while(getline(MyReadFile, text)){
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        list.push_back(text.parse)
    }
    for(auto it : list){
        for(auto it2 : list){
            if(it + it2 == 2020){
                cout << it << ", " << it2 << endl;
                cout << it*it2 << endl;
            }
            for(auto it3 : list){
                if(it + it2 + it3 == 2020){
                    cout << it << ", " << it2 << ", " << it3 << endl;
                    cout << it*it2*it3 << endl;
                    return;
                }
            }
        }
    }
}
