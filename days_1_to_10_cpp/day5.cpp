//
// Created by Olivier on 02/02/2021.
//
#include "../head.h"

void day5(){
    ifstream MyReadFile("../inputs/day5input");
    string text;
    vector<string> boardingPasses;
    vector<int> seatsid;
    while(getline(MyReadFile, text)){
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        boardingPasses.push_back(text);
    }
    MyReadFile.close();
    int maxSeatId = 0;
    for(const auto & s : boardingPasses){
        pair<int, int> rowRange({0,127});
        pair<int, int> columnRange({0, 7});
        int finalRow, finalColumn;
        finalColumn = 0;
        finalRow = 0;
        for(const auto c : s){
            float midRow = ((float) rowRange.first + (float) rowRange.second)/2;
            float midColumn = ((float) columnRange.first + (float)  columnRange.second)/2;

            if(c == 'F')
                rowRange.second = floor(midRow);
            else if(c == 'B')
                rowRange.first = ceil(midRow);

            if(c == 'R')
                columnRange.first = ceil(midColumn);
            else if(c == 'L')
                columnRange.second = floor(midColumn);

            if(rowRange.first == rowRange.second && (c == 'F' || c == 'B'))
                finalRow = rowRange.first;
            if(columnRange.first == columnRange.second && (c == 'L' || c == 'R'))
                finalColumn = columnRange.first;
        }
        seatsid.push_back(finalRow*8 + finalColumn);
    }
    sort(seatsid.begin(), seatsid.end());
    for (int i = 0; i < seatsid.size()-1; ++i) {
        if(seatsid[i]+1 != seatsid[i+1]){
            cout << seatsid[i]+1 << " is my seat" << endl;
        }
    }
    cout << "Max seat id = " << seatsid[seatsid.size()-1] << endl;

}