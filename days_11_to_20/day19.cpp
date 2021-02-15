//
// Created by Olivier on 10/02/2021.
//
#include "../head.h"


string getPossible(const map<int, vector<vector<string>>>& rules, const string & current);
vector<int> evaluateStr(const string & str, int a, int b);
bool findMatchingRule(const vector<int> & current, const map<int, vector<vector<string>>>& rules, bool secondCheck = false);
unsigned long int count_messages(const vector<string> & messages, map<int, vector<vector<string>>> rules);
bool matchRule(string expr, vector<string> stack, map<int, vector<vector<string>>> rules);

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
            if(rest.size() == 1 && (rest[0] == "\"a\"" || rest[0] == "\"b\"")){
                applyIt.emplace_back();
                if(rest[0] == "\"a\""){
                    applyIt[0].push_back("a");
                    a = id;
                }else{
                    applyIt[0].push_back("b");
                    b = id;
                }
            }else{
                for(const auto & rest1 : rest){
                    applyIt.push_back(split(rest1, " "));
                }
            }
            rules.emplace(id, applyIt);
        }else if(part == 1){
            data.push_back(text);
        }
    }
    
    cout << "Count : " << count_messages(data, rules) << endl;

    return sum;
}

vector<int> evaluateStr(const string & str, int a, int b){
    vector<int> evaluation{};
    for(const char c : str){
        evaluation.push_back((c=='a')?a:b);
    }
    return evaluation;
}

bool matchRule(string expr, vector<string> stack, map<int, vector<vector<string>>> rules){
    if(stack.size() > expr.size()){
        return false;
    }else if(stack.empty() || expr.empty()){
        return stack.empty() && expr.empty();
    }
    string string1 = stack.back();
    stack.pop_back();
    if (string1 == "a" || string1 == "b"){
        string s0{expr.at(0)};
        if(s0 == string1){
            if (matchRule(expr.substr(1, expr.size()-1), vector<string>{stack}, rules)){
                return true;
            }
        }else{
        }
    } else {
        for(const auto & rule : rules[stoi(string1)]){
            vector<string> newRule{rule};
            reverse(newRule.begin(), newRule.end());
            vector<string> newStack{stack};
            newStack.insert(newStack.end(), newRule.begin(), newRule.end());
            if (matchRule(expr, newStack, rules)){
                return true;
            }
        }
    }
    return false;
}

unsigned long int count_messages(const vector<string> & messages, map<int, vector<vector<string>>> rules){
    unsigned long int total = 0;
    for(const auto & message : messages){
        vector<string> rule0{rules.at(0)[0]};
        reverse(rule0.begin(), rule0.end());
        if(matchRule(message, rule0, rules)){
            total += 1;
        }else{
        }
    }
    return total;
}
