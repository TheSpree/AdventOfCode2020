//
// Created by Olivier on 04/02/2021.
//


#include "head.h"
using namespace std;

enum State{Floor, Free, Occupied};

class Spot{
private:
    int x;
    int y;
    State state;
public:
    Spot(int x, int y, State state) : x(x), y(y), state(state) {}

    [[nodiscard]] State getState() const {
        return state;
    }

    void setState(State state2) {
        state = state2;
    }

    [[nodiscard]] State getNextState(const vector<vector<Spot>> & grid) const {
        if (state == Floor){
            return Floor;
        }else if(state == Free){
            for (int i = x-1; i <= x+1; ++i) {
                if(i>=0 && i<grid.size()){
                    for (int j = y-1; j <= y+1; ++j) {
                        if (j>=0 && j< grid.at(0).size() && !(i == x && j == y)){
                            if(grid.at(i).at(j).state == Occupied){
                                return Free;
                            }
                        }
                    }
                }
            }
            return Occupied;
        } else if(state == Occupied){
            int occupiedNeighbours = 0;
            for (int i = x-1; i <= x+1; ++i) {
                if(i>=0 && i<grid.size()){
                    for (int j = y-1; j <= y+1; ++j) {
                        if (j>=0 && j < grid.at(i).size() && !(i == x && j == y)){
                            occupiedNeighbours += grid.at(i).at(j).state == Occupied;
                        }
                        if(occupiedNeighbours>=4){
                            return Free;
                        }
                    }
                }
            }
            return Occupied;
        }
        return Floor;
    }

    [[nodiscard]] State getNextStatePart2(const vector<vector<Spot>> & grid) const {
        if (state == Floor){
            return Floor;
        }else{
            vector<State> neighboursMap;
            neighboursMap.reserve(8);
            for(int i = 0; i < 8; i++){
                neighboursMap.push_back(Floor);
            }

            for (int i = 1; i < grid.size(); ++i) {
                if(neighboursMap.at(0) == Floor && y-i>=0){
                    neighboursMap.at(0) = grid.at(x).at(y-i).getState();
                }

                if (neighboursMap.at(1) == Floor && y + i < grid.at(x).size()) {
                    neighboursMap.at(1) = grid.at(x).at(y + i).getState();
                }

                if (neighboursMap.at(2) == Floor && x + i < grid.size()) {
                    neighboursMap.at(2) = grid.at(x + i).at(y).getState();
                }

                if (neighboursMap.at(3) == Floor && x - i >= 0) {
                    neighboursMap.at(3) = grid.at(x - i).at(y).getState();
                }

                if (neighboursMap.at(4) == Floor && (y - i >= 0 && x + i < grid.size())) {
                    neighboursMap.at(4) = grid.at(x + i).at(y - i).getState();
                }

                if (neighboursMap.at(5) == Floor && (y - i >= 0 && x - i >= 0)) {
                    neighboursMap.at(5) = grid.at(x - i).at(y - i).getState();
                }

                if (neighboursMap.at(6) == Floor && (y + i < grid.at(x).size() && x + i < grid.size())) {
                    neighboursMap.at(6) = grid.at(x + i).at(y + i).getState();
                }

                if (neighboursMap.at(7) == Floor && (y + i < grid.at(x).size() && x - i >= 0)) {
                    neighboursMap.at(7) = grid.at(x - i).at(y + i).getState();
                }
            }
            int nbOccupied = 0;
            for(const auto &n : neighboursMap){
                if(n == Occupied){
                    nbOccupied+=1;
                }
            }
            if(state == Free){
                if (nbOccupied == 0){
                    return Occupied;
                }
                else return Free;
            }else if (state == Occupied){
                if (nbOccupied >= 5){
                    return Free;
                }
                else return Occupied;
            }
        }
        return Floor;
    }
};

void day11(){
    ifstream MyReadFile("../inputs/day11input");
    string text;
    vector<vector<Spot>> grid{};
    int x = 0;
    while (getline(MyReadFile, text)){
        grid.emplace_back();
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        for (int i = 0; i < text.size(); ++i) {
            grid.at(x).push_back(Spot(x,i, (text.at(i)=='.')?Floor:Free));
        }
        ++x;
    }
    MyReadFile.close();
    vector<vector<Spot>> newGrid(grid);
    bool gridHasBeenModified = true;
    int round = 0;
    while(gridHasBeenModified){
        gridHasBeenModified = false;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.at(0).size(); ++j) {
                State newState = grid.at(i).at(j).getNextStatePart2(grid);
                //State newState = grid.at(i).at(j).getNextState(grid); // Uncomment this for part1
                State previousState = grid.at(i).at(j).getState(); // Comment this for part2
                if (previousState != newState){
                    newGrid.at(i).at(j).setState(newState);
                    gridHasBeenModified = true;
                }
            }
        }
        grid = newGrid;
        ++round;
    }
    int countOccupied = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid.at(0).size(); ++j) {
            countOccupied += grid.at(i).at(j).getState() == Occupied;
        }
    }
    cout << countOccupied  << " after " << round << " rounds"<< endl;

}
