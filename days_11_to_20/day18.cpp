//
// Created by Olivier on 08/02/2021.
//

#include "../head.h"

unsigned long long int extractSubOperation(vector<string> text);
vector<string> parenthesisOperation(vector<string> text);
unsigned long long int plusFirst(const vector<string>& text);

unsigned long long int day18(const string& path){
    ifstream MyReadFile(path);
    string text;
    unsigned long long int sum = 0;
    while (getline(MyReadFile, text)) {
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        sum += plusFirst(split(text, " "));
    }
    cout << sum << endl;
    return sum;
}

unsigned long long int extractSubOperation(vector<string> text){
    if(text.at(0).find('(') == string::npos){ //Pure operation, no '(' found
        unsigned long long int result = stoll(text.at(0));
        text.erase(text.begin());
        bool plus = text.at(0).find('+') != string::npos;
        text.erase(text.begin());

        if(text.at(0).find('(') != string::npos){
            text = parenthesisOperation(text);
        }
        if (plus) {
            result += stoll(text.at(0));
        } else {
            result *= stoll(text.at(0));
        }
        text.at(0) = to_string(result);

        if (text.size() != 1) {
            return extractSubOperation(text);
        } else {
            return result;
        }
    }else{ //'(' found, need to find the matching ')' and treat the operation. Then, replace the whole (..) by it's value
        text = parenthesisOperation(text);
        return extractSubOperation(text);
    }
}

unsigned long long int plusFirst(const vector<string>& text){
    vector<string> parenthesisDispatch{};
    for (const string & i : text){
        if(!(i.find('(') == string::npos && i.find(')') == string::npos)){
            for (int j = 0; j < i.size(); ++j) {
                string substr = i.substr(j, 1);
                if(!substr.empty()){
                    parenthesisDispatch.push_back(substr);
                }
            }
        }else if (!i.empty()){
            parenthesisDispatch.push_back(i);
        }
    }
    for (int i = 0; i < parenthesisDispatch.size()-2; ++i) {
        if (parenthesisDispatch[i] == "(" && parenthesisDispatch[i+2] == ")"){
            string value2 = parenthesisDispatch.at(i+1);
            parenthesisDispatch.erase(parenthesisDispatch.begin()+i, parenthesisDispatch.begin()+i+3);
            parenthesisDispatch.insert(parenthesisDispatch.begin()+i, value2);
        }
    }

    int plus = find(parenthesisDispatch.begin(), parenthesisDispatch.end(), "+") - parenthesisDispatch.begin();
    if(plus != parenthesisDispatch.size() ){
        auto plusIt = find(parenthesisDispatch.begin(), parenthesisDispatch.end(), "+");
        string leftStr = parenthesisDispatch.at(plus - 1), rightStr = parenthesisDispatch.at(plus + 1);

        if (leftStr == ")") {
            vector<string> leftParenthesis{};
            int parenthesisNb = 1;
            int index = plus - 2;
            while (parenthesisNb != 0) {
                if (parenthesisDispatch.at(index) == "(") {
                    --parenthesisNb;
                } else if (parenthesisDispatch.at(index) == ")") {
                    ++parenthesisNb;
                }
                if (parenthesisNb != 0) {
                    leftParenthesis.insert(leftParenthesis.begin(), parenthesisDispatch.at(index));
                    --index;
                }
            }
            parenthesisDispatch.erase(plusIt - leftParenthesis.size()-2, plusIt);
            parenthesisDispatch.insert(plusIt - leftParenthesis.size()-2, to_string(plusFirst(leftParenthesis)));
            return plusFirst(parenthesisDispatch);
        }
        if (rightStr == "(") {
            vector<string> rightParenthesis{};
            int parenthesisNb = 1;
            int index = plus + 2;
            while (parenthesisNb != 0) {
                if (parenthesisDispatch.at(index) == ")") {
                    --parenthesisNb;
                } else if (parenthesisDispatch.at(index) == "(") {
                    ++parenthesisNb;
                }
                if (parenthesisNb != 0) {
                    rightParenthesis.push_back(parenthesisDispatch.at(index));
                    ++index;
                }
            }
            parenthesisDispatch.erase(find(parenthesisDispatch.begin(), parenthesisDispatch.end(), "+")+1, plusIt + 3 + rightParenthesis.size());
            if (plusIt+1 > parenthesisDispatch.end()){
                parenthesisDispatch.push_back(to_string(plusFirst(rightParenthesis)));
            }else
                parenthesisDispatch.insert(plusIt +1, to_string(plusFirst(rightParenthesis)));
            return plusFirst(parenthesisDispatch);
        }
        string value = to_string(stoll(leftStr) + stoll(rightStr));
        parenthesisDispatch.erase(plusIt-1, plusIt+2);
        parenthesisDispatch.insert(plusIt-1, value);


        if(parenthesisDispatch.size() == 1){
            return stoll(parenthesisDispatch.at(0));
        }else{
            return plusFirst(parenthesisDispatch);
        }
    }else{
        unsigned long long int result = extractSubOperation(parenthesisDispatch);
        return result;
    }
}

vector<string> parenthesisOperation(vector<string> text){
    vector<string> subOperation{};
    int nbParenthesis = 1;
    text.at(0).erase(0, 1);
    if (text.at(0).find('(') != string::npos){
        ++nbParenthesis;
    }
    subOperation.push_back(text.at(0));
    text.erase(text.begin());
    while(nbParenthesis != 0 && !text.empty()){
        if(nbParenthesis == 2 && text.at(0).find("))") != string::npos){
            nbParenthesis -= 2;
            text.at(0).erase(text.at(0).size()-1);
            text.at(0).erase(text.at(0).size()-1);
        }else if (text.at(0).find(')') != string::npos){
            --nbParenthesis;
            if(nbParenthesis == 0)
                text.at(0).erase(text.at(0).size()-1);//remove parenthesis
        }else if(text.at(0).find('(') != string::npos){
            ++nbParenthesis;
        }
        subOperation.push_back(text.at(0));
        text.erase(text.begin());
    }
    text.insert(text.begin(), to_string(plusFirst(subOperation)));
    return text;
}