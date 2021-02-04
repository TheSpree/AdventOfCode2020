//
// Created by Olivier on 04/02/2021.
//

#include "../head.h"
using namespace std;

struct Instruction{
    string instruction;
    int value{};
    bool visited = false;
};

void day8();
void isThereAnInfiniteLoop(vector<Instruction> instructionsList);

void day8(){
    ifstream MyReadFile("../inputs/day8input");
    string text;
    vector<Instruction> instructionsList{};
    while(getline(MyReadFile, text)){
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        Instruction instruction;
        instruction.instruction = text.substr(0, text.find(' '));
        string value = text.substr(text.find(' '), text.size());
        instruction.value = stoi(value);
        instructionsList.push_back(instruction);
    }

    isThereAnInfiniteLoop(instructionsList);

    for (int i = 0; i < instructionsList.size(); ++i) {
        cout << "Chaning instruction at " << i << " which is a " << instructionsList.at(i).instruction << endl;
        if(instructionsList.at(i).instruction == "jmp" ){
            instructionsList.at(i).instruction = "nop";
            isThereAnInfiniteLoop(instructionsList);
            instructionsList.at(i).instruction = "jmp";
        }else if(instructionsList.at(i).instruction == "nop"){
            instructionsList.at(i).instruction = "jmp";
            isThereAnInfiniteLoop(instructionsList);
            instructionsList.at(i).instruction = "nop";
        }
    }
    MyReadFile.close();
}

void isThereAnInfiniteLoop(vector<Instruction> instructionsList){
    int i = 0;
    int accumulator = 0;
    unsigned long exec_at = 0;
    while (exec_at != instructionsList.size() && !instructionsList.at(exec_at).visited){
        instructionsList.at(exec_at).visited = true;
        if(instructionsList.at(exec_at).instruction == "acc"){
            accumulator += instructionsList.at(exec_at).value;
            exec_at += 1;
        }
        else if(instructionsList.at(exec_at).instruction == "jmp"){
            exec_at +=instructionsList.at(exec_at).value;
            if (exec_at > instructionsList.size()){
                exec_at = instructionsList.size()-1;
            }else if(exec_at < 0){
                exec_at = 0;
            }
        }
        else if(instructionsList.at(exec_at).instruction == "nop"){
            exec_at += 1;

        }
        ++i;
        if(exec_at == instructionsList.size()){
            cout << "Terminated !" << accumulator << endl;
            return ;
        }

    }
    cout << "Found an infinite loop ! Accumulator ends with value " << accumulator << " (after " << i << " instructions and exec_at is )" << exec_at << " for " << instructionsList.size() << " instructions" << endl;
}