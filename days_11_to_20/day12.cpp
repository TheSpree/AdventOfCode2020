//
// Created by Olivier on 05/02/2021.
//


#include "../head.h"
using namespace std;

struct Instruction{
    char action{};
    int value{};
};

struct Waypoint{
    int north=1;
    int east=10;
};

class Ship{
protected:
    int direction = 1; // Considering N = 0, E = 1, S = 2, W = 3
    int north = 0, east = 0;
public:
    Ship()= default;

    virtual void printPosition() const{
        cout << "north : " << north << ", east : " << east << endl;
        cout << "Manhattan distance : " << abs(north)+abs(east) << endl;
    }

    virtual void changeDirection(char sens, int value){
        int angleToValue = value/90;
        if (sens == 'R'){
            direction += angleToValue;
        }else if(sens == 'L'){
            direction -= angleToValue;
        }
        if (direction > 3){
            direction %= 4;
        }
        if (direction<0){
            direction += 4;
        }
    }

    virtual void moveForward(int value){
        switch (direction) {
            case 0:
                north+=value;
                break;
            case 1:
                east+=value;
                break;
            case 2:
                north-=value;
                break;
            case 3:
                east-=value;
                break;
            default:
                break;
        }
    }

    virtual void moveDirection(char gavenDirection, int value){
        switch (gavenDirection) {
            case 'N':
                north+=value;
                break;
            case 'E':
                east+=value;
                break;
            case 'S':
                north-=value;
                break;
            case 'W':
                east-=value;
                break;
            default:break;
        }
    }
    void executeInstruction(const Instruction & i){
        if (i.action == 'F'){
            moveForward(i.value);
        }else if(i.action == 'L' || i.action == 'R'){
            changeDirection(i.action, i.value);
        }else{
            moveDirection(i.action, i.value);
        }
    }
    void executeAllInstructions(const vector<Instruction> & listOfInstructions){
        for(const Instruction & i : listOfInstructions){
            executeInstruction(i);
        }
    }
};

class Shipv2: public Ship{
private:
    Waypoint waypoint; // Waypoint is defined using ship itself as origin
public:
    Shipv2() = default;
    void printPosition() const override{
        Ship::printPosition();
    }

    void moveForward(int value) override{ // Moving forward the waypoint
        north += value*waypoint.north;
        east += value*waypoint.east;
    }
    void moveDirection(char gavenDirection, int value) override {
        switch (gavenDirection) {
            case 'N':
                waypoint.north+=value;
                break;
            case 'E':
                waypoint.east+=value;
                break;
            case 'S':
                waypoint.north-=value;
                break;
            case 'W':
                waypoint.east-=value;
                break;
            default:break;
        }
    }

    void changeDirection(char sens, int value) override{
        int angleToValue = value/90;
        for (int i = 0; i < angleToValue; ++i) {
            int nextNorth = 0, nextEast = 0;
            if (sens == 'R'){
                nextNorth = -waypoint.east;
                nextEast = waypoint.north;
            }else if(sens == 'L'){
                nextNorth = waypoint.east;
                nextEast = -waypoint.north;
            }
            else{
                cout << "INVALID SENS" << endl;
            }
            waypoint.north = nextNorth;
            waypoint.east = nextEast;
        }
    }
};

void day12(){
    ifstream MyReadFile("../inputs/day12input");
    string text;
    vector<Instruction> instructionList{};
    while (getline(MyReadFile, text)){
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        Instruction i;
        i.action = text[0];
        i.value = stoi(text.substr(1, text.size()));
        instructionList.push_back(i);
    }
    MyReadFile.close();

    Ship ship;
    ship.executeAllInstructions(instructionList);
    ship.printPosition();

    Shipv2 shipv2;
    shipv2.executeAllInstructions(instructionList);
    shipv2.printPosition();

}
