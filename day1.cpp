//
// Created by Olivier on 02/02/2021.
//

#include "head.h"

void day1(){
    vector<int> list({});
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
