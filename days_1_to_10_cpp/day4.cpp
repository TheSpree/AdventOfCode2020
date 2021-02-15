    //
// Created by Olivier on 02/02/2021.
//

#include "../head.h"

void day4(){
    regex key("(byr):(19[2-9][0-9]|200[0-2])|(iyr):(201[0-9]|2020)|(eyr):(202[0-9]|2030)|(hgt):((1[5-8][0-9]|19[0-5])(cm)|([5-6][0-9]|7[0-6])(in))|(hcl):((#[0-9a-f]{6}))|(ecl):(amb|blu|brn|gry|grn|hzl|oth)|(pid):([0-9]{9})");
    regex regexKeys {"(byr)|(iyr)|(eyr)|(hgt)|(hcl)|(ecl)|(pid)"};
    vector<vector<string>> map{{}};
    ifstream MyReadFile("../inputs/day4input");
    string text;
    int i = 0;
    while(getline(MyReadFile, text)){
        if(text.length()>1) { // Not a blank line => need to treat this and remove the \r that sucks. As it's at the end, can be removed easily ?
            if(text.find('\r') != string::npos){
                string pushMe = text.substr(0, text.find('\r'));
                string token;
                istringstream tokenStream(text);
                while(getline(tokenStream, token, ' ')){
                    map.at(i).push_back(token);
                }
            }
        }else{ // Blank line
            ++i;
            map.emplace_back();
        }
    }
    int valids = map.size();
    for(const auto & infos : map){
        int validParam = 0;
        for(string param : infos){
            param.erase(remove(param.begin(), param.end(), '\r'), param.end());
            param.erase(remove(param.begin(), param.end(), '\n'), param.end());
            cout << "Reading param " << param  << "(" << param.size() << ")"<< endl;
            if(regex_match(param, key))
                ++validParam;
        }
        if (validParam < 7){
            --valids;
        }
    }

    cout << "Over " << map.size() << " passports red, " << valids << " are valid."<<endl;

    MyReadFile.close();
}
