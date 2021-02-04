//
// Created by Olivier on 04/02/2021.
//


#include "../head.h"
using namespace std;

void day9();
long sum(const vector<long> & vector1);

void day9(){
    ifstream MyReadFile("../inputs/day9input");
    int preambule_sze = 25;
    long invalidNumber, invalidIndex;
    string text;
    vector<long> preamble;
    vector<long long> cypher;
    int count = 0;
    while(getline(MyReadFile, text)) {
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        cypher.push_back(stol(text));
        ++count;
    }
    for(int i = preambule_sze; i < cypher.size(); ++i){

        bool answerFound = false;
        for(int j = i-preambule_sze; j < i; ++j){
            for(int j2 = j+1; j2 < i; ++j2) {
                if (cypher.at(j)+cypher.at(j2) == cypher.at(i)) {
                    answerFound = true;
                }
                if (answerFound) {
                    break;
                }
            }
        }
        if (!answerFound){
            invalidNumber = cypher.at(i);
            invalidIndex = i;
            cout << "Could not find a solution for " << cypher.at(i) << " (index : " << invalidIndex << ")" <<endl;
            i = cypher.size();
        }
    }

    vector<long> setOfFollowing;
    for (long i = 0; i < invalidIndex; ++i) {
        setOfFollowing.push_back(cypher.at(i));
        long actualSum = sum(setOfFollowing);
        if(actualSum == invalidNumber){
            i = invalidIndex;
        }else if(actualSum > invalidNumber){
            bool tooHigh = true;
            while (tooHigh){
                setOfFollowing.erase(setOfFollowing.begin());
                actualSum = sum(setOfFollowing);
                if (actualSum <= invalidNumber){
                    tooHigh = false;
                }
                if(sum(setOfFollowing) == invalidNumber) {
                    i = invalidIndex;
                }
            }
        }
    }
    cout << "Found the sequence ! " <<endl;
    long min, max;
    min = setOfFollowing.at(0);
    max = 0;
    for(auto const & l : setOfFollowing){
        min = std::min(min, l);
        max = std::max(max, l);
    }
    cout << "Min is "<< min << " and max is " << max << " which sum is " << min+max << endl;

    MyReadFile.close();
}

long sum(const vector<long> & vector1){
    long result = 0;
    for(auto const & value : vector1){
        result += value;
    }
    return result;
}