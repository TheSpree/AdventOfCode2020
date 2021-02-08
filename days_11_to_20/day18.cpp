//
// Created by Olivier on 08/02/2021.
//

#include "head.h"

int day18(const string& path){
    ifstream MyReadFile(path);
    string text;
    while (getline(MyReadFile, text)) {
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
    }

}