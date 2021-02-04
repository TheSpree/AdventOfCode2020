//
// Created by Olivier on 02/02/2021.
//

#include "../head.h"

void day3(){
    vector<string> map;
    string text;
    ifstream MyReadFile("../inputs/day3input.txt");
    while(getline (MyReadFile, text)){
        map.push_back(text);
    }
    long treecounter = 1;

    vector<vector<int>> slopes({{1,1}, {3,1}, {5,1}, {7,1},{1,2}});
    for(auto slope:slopes){
        int x = 0;
        int y = 0;
        long int tempo=0;
        while(y<map.size()){
            if (map[y][x]=='#')
                ++tempo;
            x = (x+slope[0]) % (map[y].size()-1);
            y+=slope[1];
        }
        treecounter *= tempo;
    }
    cout << "Trees on the way : " << treecounter << endl;
    MyReadFile.close();
}
