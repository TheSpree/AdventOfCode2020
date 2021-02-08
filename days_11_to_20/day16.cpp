//
// Created by Olivier on 07/02/2021.
//
#include "../head.h"

class Field{
private:
    string name;
    vector<pair<unsigned int, unsigned int>> ranges;
public:
    Field(string name, const pair<unsigned int, unsigned int> p1,  const pair<unsigned int, unsigned int> p2) : name(std::move(name)) {
        ranges.push_back(p1);
        ranges.push_back(p2);
    };

    [[nodiscard]] const string &getName() const { return name; }
    [[nodiscard]] const vector<pair<unsigned int, unsigned int>> &getRanges() const { return ranges; }
};

class Constraints{
private:
    vector<Field> fields{};
public:
    Constraints() = default;
    void pushField(const Field& field){ fields.push_back(field);}
    bool isValid(unsigned int value){
        for(const Field & field : fields){
            for(const pair<unsigned int, unsigned int> & range : field.getRanges()){
                unsigned int min=range.first, max = range.second;
                if (value >= min && value <= max)
                    return true;
            }
        }
        return false;
    }
    vector<string> validFields(unsigned int value){
        vector<string> valid{};
        for(const Field & field : fields){
            bool isFieldValid = true;
            vector<pair<unsigned int, unsigned int>> ranges = field.getRanges();
                unsigned int min1=ranges.at(0).first, min2=ranges.at(1).first, max1=ranges.at(0).second, max2=ranges.at(1).second;
                if (!((value >= min1 && value <= max1) || (value >= min2 && value <= max2))){
                    isFieldValid = false;
                }
            if (isFieldValid){
                valid.push_back(field.getName());
            }
        }
        return valid;
    }
};

pair<unsigned long long int, unsigned long long int> day16(const string & path){
    ifstream MyReadFile(path);
    string text, mask;
    Constraints constraints{};
    int part = 0;
    unsigned long int invalidSum = 0;
    vector<int> ticket{};
    vector<vector<int>> validTickets;
    while (getline(MyReadFile, text)) {
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        if(text.empty()){
            ++part;
        }else if(part == 0){
            vector<string> patternStr{": ", "-", " or ", "-"};
            vector<string> pattern= extractPattern(text, patternStr);
            Field f(pattern[0], pair<int, int>(stoi(pattern[1]), stoi(pattern[2])), pair<int, int>(stoi(pattern[3]), stoi(pattern[4])));
            constraints.pushField(f);
        }else if(part == 1){
            if(text != "your ticket:"){
                vector<string> strTicket = split(text, ",");
                for(const string & item : strTicket){
                    ticket.push_back(stoi(item));
                }
            }
        }else if(part == 2){
            if(text != "nearby tickets:") {
                vector<string> strTicket = split(text, ",");
                vector<int> intTicket{};
                bool isTicketValid = true;
                for(const string & item : strTicket){
                    if(!constraints.isValid(stoi(item))){
                        invalidSum += stoi(item);
                        isTicketValid = false;
                    }
                    intTicket.push_back(stoi(item));
                }
                if (isTicketValid){
                    validTickets.push_back(intTicket);
                }
            }
        }
    }
    vector<vector<string>> correctField(validTickets.at(0).size());
    for(const vector<int> & valid:validTickets){
        for(int i = 0; i<valid.size(); ++i){
            if(correctField.at(i).empty()) {
                for (const string &field : constraints.validFields(valid.at(i))) {
                    correctField.at(i).push_back(field);
                }
                sort(correctField.at(i).begin(), correctField.at(i).end());
                correctField.at(i).erase(unique(correctField.at(i).begin(), correctField.at(i).end()),
                                         correctField.at(i).end());
            }else{
                vector<string> common{};
                for (const string &field : constraints.validFields(valid.at(i))) {
                    if(find(correctField.at(i).begin(), correctField.at(i).end(), field) != correctField.at(i).end()){
                        common.push_back(field);
                    }
                }
                correctField.at(i) = common;
            }
        }
    }
    vector<int> ignoredList{};
    while(!all_of(correctField.begin(), correctField.end(), [](const vector<string>&v){return v.size()==1;})){
        for (int i = 0; i < correctField.size(); ++i) {
            if(correctField.at(i).size()==1 && find(ignoredList.begin(), ignoredList.end(), i) == ignoredList.end() ){
                ignoredList.push_back(i);
                for (int j = 0; j < correctField.size(); ++j) {
                    if(j != i){
                        auto position = find(correctField.at(j).begin(), correctField.at(j).end(),
                                             correctField.at(i).at(0));
                        if (position != correctField.at(j).end()) {
                            correctField.at(j).erase(position);
                        }
                    }
                }
            }
        }
    }
    unsigned long long int times = 1;
    for (int i = 0; i < correctField.size(); ++i) {
        for(const auto & s:correctField.at(i)){
            if (s.find("departure") != string::npos){
                cout << ticket.at(i) << endl;
                times = times * ticket.at(i);
            }
        }
    }
    MyReadFile.close();
    pair<unsigned long long int, unsigned long long int> answer{invalidSum ,times};
    return answer;
}
