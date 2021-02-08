//
// Created by Olivier on 07/02/2021.
//

#include "../head.h"

void day14();
vector<int> convertTo36BitsBinary(unsigned long long int convertMe);
unsigned long long int applyMask(unsigned long long int value,const string& mask);
unsigned long long int convertBinaryToInt(vector<int> binary);
void executeInstruction(const string & mask, const unsigned long long& address,const unsigned long long int & value, map<unsigned long long int, unsigned long long int> & memory);

void day14(){
    ifstream MyReadFile("../inputs/day14input");
    string text, mask;
    regex maskRegex ("mask");
    regex memRegex("mem");
    map<unsigned long long int, unsigned long long int> memory{};
    map<unsigned long long int, unsigned long long int> memory2{};
    while (getline(MyReadFile, text)) {
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        if (regex_search(text, maskRegex)){
            mask = text.substr(text.find("= ")+2, text.size());
        }else if (regex_search(text, memRegex)){
            unsigned long long int memId = stoi(text.substr(text.find('[')+1, text.find(']')-text.find('[')-1));
            unsigned long long int value =  stoi(text.substr(text.find("= ")+2, text.size()));
            executeInstruction(mask, memId, value, memory2);
            unsigned long long int newValue = applyMask(value, mask);
            if(memory.find(memId) != memory.end()){
                memory.at(memId) = newValue;
            }else{
                memory.emplace(memId, newValue);
            }
        }
    }

    unsigned long long int sum = 0;
    for(auto const & item : memory){
        sum += item.second;
    }
    cout << "Part 1 : "<< sum << endl;
    sum = 0;
    for(auto const & item : memory2){
        sum += item.second;
    }
    cout << "Part 2 : "<< sum << endl;

}

vector<int> convertTo36BitsBinary(unsigned long long int convertMe) {
    vector<int> binaryConverted(36, 0);
    if (convertMe > 68719476735) { //value to high
        cout << "Value too high"<<endl;
        return {};
    } else {
        for (int i = 35; i >= 0; --i) {
            binaryConverted.at(i) = convertMe % 2;
            convertMe /= 2;
        }
    }
    return binaryConverted;
}

unsigned long long int convertBinaryToInt(vector<int> binary){
    unsigned long long int decimal = 0, i = 0, remainder;
    while (!binary.empty())
    {
        remainder = binary.back();
        decimal += remainder*pow(2,i);
        binary.pop_back();
        ++i;
    }
    return decimal;
}

unsigned long long int applyMask(unsigned long long int value,const string& mask){
    vector<int> binary = convertTo36BitsBinary(value);
    vector<int> masked{};
    for (int i = 0; i < binary.size(); ++i) {
        if (mask[i] == 'X'){
            masked.push_back(binary.at(i));
        }else{
            masked.push_back(mask[i] - '0');
        }
    }

    return convertBinaryToInt(masked);
}

void executeInstruction(const string & mask, const unsigned long long& address,const unsigned long long int & value, map<unsigned long long int, unsigned long long int> & memory){
    vector<int> binAddress = convertTo36BitsBinary(address);
    int nbX = count(mask.begin(), mask.end(), 'X');
    for (int i = 0; i < mask.size(); ++i){
        if (mask.at(i) == '1'){
            binAddress.at(i) = 1;
        }else if(mask.at(i) == 'X'){
            binAddress.at(i) = -1;
        }
    }
    vector<int> binarySizenbx{};
    binarySizenbx.reserve(nbX);
    for (int i = 0; i < nbX; ++i) {
        binarySizenbx.push_back(1);
    }
    for (int i = 0; i <=convertBinaryToInt(binarySizenbx); ++i) {
        vector<int> addressCopy = binAddress;
        vector<int> binI = convertTo36BitsBinary(i);
        for (int i = addressCopy.size()-1; i>=0; --i) {
            if(addressCopy.at(i) == -1){
                addressCopy.at(i) = binI.back();
                binI.pop_back();
            }
        }
        unsigned long long int newAdress = convertBinaryToInt(addressCopy);
        if(memory.find(newAdress) == memory.end()){
            memory.emplace(newAdress, value);
        }else{
            memory.at(newAdress) = value;
        }
    }
}

/*Explanations :
 * Part 1 is pretty strait forward, juste follow instructions, apply mask and it's done.
 *
 * Part 2 is a little more tricky, but still follow instructions and don't get caught by type's range which may cause
 * the algorithm to end with a bad answer. Here, the index of the map must be unsigned long long int, if not, some
 * addresses are wrong so the algorithm can't detect either an address haven't been writen or not.
 *
 * */