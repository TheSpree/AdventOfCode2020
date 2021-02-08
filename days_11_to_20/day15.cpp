//
// Created by Olivier on 07/02/2021.

#include "../head.h"

void day15(){
    ifstream MyReadFile("../inputs/day15input");
    string text, mask;
    map<int, int> spoken; // Map represent the game like : <numSpoken, turnId>
    pair<int, int> lastSpoken(0, false);
    while (getline(MyReadFile, text)) {
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        vector<string> splittedText = split(text, ",");
        for (int i = 1; i <= splittedText.size(); ++i) {
            lastSpoken.first = stoi(splittedText.at(i-1));
            lastSpoken.second = (spoken.find(lastSpoken.first) != spoken.end())?0:spoken.find(lastSpoken.first)->second;
            spoken.emplace(lastSpoken.first, i);
        }
    }
    unsigned int begin = spoken.size()+1;
    for (unsigned long int i = begin; i <= 30000000; ++i) {
        if(lastSpoken.second == 0){//If the number at turn i-1 haven't been spoken, push 0 at turn i
            lastSpoken.first = 0;
            lastSpoken.second = (spoken.find(lastSpoken.first) == spoken.end())?0:spoken.find(lastSpoken.first)->second;

        }else{ //Else, push (actualTurn-1-turnWhenLastSpoken) at turn i
            lastSpoken.first = i-1-lastSpoken.second; // <-- New spoken number
            lastSpoken.second = (spoken.find(lastSpoken.first) == spoken.end())?0:spoken.find(lastSpoken.first)->second;
        }
        if(spoken.find(lastSpoken.first) == spoken.end()){
            spoken.emplace(lastSpoken.first, i);
        }else{
            spoken.find(lastSpoken.first)->second = i;
        }
    }
    cout << lastSpoken.first <<endl;
    MyReadFile.close();
}
