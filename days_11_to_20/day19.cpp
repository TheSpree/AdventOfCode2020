//
// Created by Olivier on 10/02/2021.
//
#include "../head.h"


string getPossible(const map<int, vector<vector<string>>>& rules, const string & current);
vector<int> evaluateStr(const string & str, int a, int b);

unsigned long long int day19(const string & path){
    ifstream MyReadFile(path);
    string text;
    unsigned long long int sum = 0;
    int part = 0, a, b;
    map<int, vector<vector<string>>> rules{};
    vector<string> data{};
    while (getline(MyReadFile, text)) {
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        if(text.empty()){
            ++part;
        }else if(part == 0){
            int id = stoi(text.substr(0, text.find(':')));
            vector<string> rest = split(text.substr(text.find(':')+2), " | ");
            vector<vector<string>> applyIt{};
            applyIt.emplace_back();
            if(rest.size() == 1 && (rest[0] == "\"a\"" || rest[0] == "\"b\"")){
                if(rest[0] == "\"a\""){
                    applyIt[0].emplace_back("a");
                    a = id;
                }else{
                    applyIt[0].emplace_back("b");
                    b = id;
                }
            }else{
                int i = 0, j = 0;
                while(j < rest.size()){
                    if (rest[j] != "|"){
                        applyIt[i].emplace_back(rest[j]);
                    }else{
                        ++i;
                        applyIt.emplace_back();
                    }
                    ++j;
                }
            }
            rules.emplace(id, applyIt);
        }else if(part == 1){
            data.push_back(text);
        }
    }

    printVector(evaluateStr(data[0], a, b));

    return sum;
}

vector<int> evaluateStr(const string & str, int a, int b){
    vector<int> evaluation{};
    for(const char c : str){
        evaluation.push_back((c=='a')?a:b);
    }
    return evaluation;
}
