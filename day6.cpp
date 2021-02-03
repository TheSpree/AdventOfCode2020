//
// Created by Olivier on 02/02/2021.
//
#include "head.h"

void day6(){
    ifstream MyReadFile("./day6input");
    string text;
    vector<vector<char>> groups{{}};
    vector<pair<int, vector<char>>> groups2{{}};
    int i = 0;
    while (getline(MyReadFile, text)){
        if(text.length()>1){
            for(const auto & c : text){
                groups.at(i).push_back(c);
                groups2.at(i).second.push_back(c);
            }
            groups2.at(i).first += 1;
        }else{
            ++i;
            groups.emplace_back();
            groups2.emplace_back();
        }
    }
    int total_answers = 0;
    for(vector<char> v : groups){
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        v.erase(v.begin(), v.begin()+1);
        total += v.size();
    }
    int total = 0;
    for(pair<int, vector<char>> v : groups2){
        sort(v.second.begin(), v.second.end());
        v.second.erase(remove(v.second.begin(), v.second.end(), '\n'), v.second.end());
        v.second.erase(remove(v.second.begin(), v.second.end(), '\r'), v.second.end());
        char previous;
        int count_duplicate = 0;
        for(auto c : v.second){
            if(!previous){
                previous = c;
                ++count_duplicate;
            }
            else if (c == previous){
                ++count_duplicate;
            }
            else if (c != previous){
                count_duplicate = 1;
                previous = c;
            }
            if(count_duplicate == v.first){
                count_duplicate = 1;
                previous = c;
                ++total;
            }
        }
    }
    cout << "(Part 1) total : " << total_answers << endl;

    cout << "(Part 2) total : " << total << endl;
    MyReadFile.close();
}