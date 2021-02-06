//
// Created by Olivier on 06/02/2021.
//

#include "head.h"
void day13(){
    ifstream MyReadFile("../inputs/day13input");
    string text;
    int beginTimestamp = 0, lineCount = 0, xCount = 0;
    vector<int> inServiceBus{}; // Used in part 1 : doesn't contain the 'x' representation
    vector<int> busList{}; // Used in part 2  : contains 'x' as 1
    while (getline(MyReadFile, text)){
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        if (lineCount == 0){
            beginTimestamp = stoi(text);
        } else{
            while (!text.empty()){
                if(text.find(',') != string::npos){
                    string busId = text.substr(0, text.find(','));
                    if(busId != "x"){
                        inServiceBus.push_back(stoi(busId));
                        busList.push_back(stoi(busId));
                    }else{
                        busList.push_back(1);
                    }
                    text.erase(0, text.find(',')+1);
                }
                else{
                    inServiceBus.push_back(stoi(text));
                    busList.push_back(stoi(text));
                    text.erase(0, text.size());
                }
                ++xCount;
            }
        }
        ++lineCount;
    }
    MyReadFile.close();
    bool firstDepartureFound = false;
    int i=0, firstId = 0;
    while(!firstDepartureFound){
        for (const auto id : inServiceBus){
            if ((beginTimestamp+i)%id == 0){
                firstId = id;
                firstDepartureFound = true;
            }
        }
        i += !firstDepartureFound;
    }
    cout << firstId<< " after waiting " << i << " so answer is " << firstId*i << endl;

    unsigned long long int time = 0;
    unsigned long long int step=busList.at(0);

    for(int j = 1; j < busList.size(); ++j){
        const int bus = busList.at(j);
        while((time+j)%bus!= 0){
            time += step;
        }
        step *= bus;
    }

    cout << "Pattern matched at timestamp " << time << endl;
}
