//
// Created by Olivier on 02/02/2021.
//
#include "head.h"

void day2(){
    int valid = 0;
    int valid_part2 = 0;
    string s;
    ifstream input("day2Input");
    while(getline(input, s)){
        int count = 0;
        string firstHalf = s.substr(0, s.find(':'));
        string password = s.substr(s.find(':')+2, s.length());
        string minMax = firstHalf.substr(0, firstHalf.find(' '));
        int min = stoi((minMax.substr(0, minMax.find('-'))));
        int max = stoi(minMax.substr(minMax.find('-')+1, minMax.find(' ')));
        char letter = firstHalf[firstHalf.length()-1];
        for(char c : password){
            if(c==letter){
                ++count;
            }
        }
        if((count >= min) && (count <= max)){
            ++valid;
        }
        if(password[min-1] == letter xor password[max-1] == letter){
            ++valid_part2;
        }
    }
    cout << valid << " passwords are valid" << endl;
    cout << valid_part2 << " passwords are valid with 2nd policy" << endl;

}