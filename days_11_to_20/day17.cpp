//
// Created by Olivier on 07/02/2021.
//
#include "../head.h"

class Spot{
private:
    bool active=false;
    bool nextStatus = false;
public:
    explicit Spot(bool active) : active(active) {}
    [[nodiscard]] bool isActive() const {
        return active;
    }
    void changeStatus(bool newStatus){active = newStatus;}

    [[nodiscard]] static unsigned int getActiveNeighbours(const vector<vector<vector<vector<Spot>>>> & globalGrid, int x, int y, int z, int w) {
        unsigned int nb=0;
        for(int n = -1; n<=1; ++n){
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    for (int k = -1; k <=1; ++k) {
                        if(z+i>=0 && z+i < globalGrid.size() &&
                           y+j>=0 && y+j < globalGrid.size() &&
                           x+k>=0 && x+k < globalGrid.size() &&
                           w+n>=0 && w+n < globalGrid.size()){
                            if(!(z+i == z && y+j == y && x+k == x && w+n == w)){
                                    nb +=globalGrid.at(w+n).at(z+i).at(y+j).at(x+k).isActive();
                            }
                        }
                    }
                }
            }
        }
        return nb;
    }
    void updateStatus(const vector<vector<vector<vector<Spot>>>>& globalGrid, int x, int y, int z, int w){
        unsigned int neighbours = getActiveNeighbours(globalGrid, x, y, z, w);
        if(active && (neighbours == 2 || neighbours == 3)){
            //cout << neighbours<<endl;
            nextStatus = true;
        }else if(active){
            //cout << neighbours<<endl;
            nextStatus = false;
        }else if(!active && neighbours == 3){
            nextStatus = true;
        }else{
            nextStatus = false;
        }
    }
    void applyNextStatus(){
        active = nextStatus;
    }
};


int day17(const string& path){
    int size = 40, inputSize = 8;
    vector<vector<vector<vector<Spot>>>> grid{};
    for(int n = 0; n<size; ++n){
        grid.emplace_back();
        for (int i = 0; i < size; ++i) {
            grid.at(n).emplace_back();
            for (int j = 0; j < size; ++j) {
                grid.at(n).at(i).emplace_back();
                for (int k = 0; k < size; ++k) {
                    grid.at(n).at(i).at(j).push_back(Spot(false));
                }
            }
        }
    }
    ifstream MyReadFile(path);
    string text;
    int j = 0;
    while (getline(MyReadFile, text)) {
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        for(int i = 0; i<text.size(); ++i){
            if (text[i] == '.'){
                grid.at(size/2).at(size/2).at(size/2+j-inputSize/2).at(size/2+i-inputSize/2) = Spot( false);
            }else if(text[i] == '#'){
                grid.at(size/2).at(size/2).at(size/2+j-inputSize/2).at(size/2+i-inputSize/2) = Spot( true);
            }
        }
        ++j;
    }
    int zDim = 0;

    /*cout << "Init" <<endl;
    for(auto & gridn: grid){
        for (auto &i : gridn) {
            cout << "z=" << zDim << endl;
            for (const auto &y : i) {
                for (Spot x : y) {
                    string printMe = (x.isActive()) ? "# " : ". ";
                    cout << printMe;
                }
                cout << endl;
            }
            cout << endl;
            ++zDim;
        }
    }*/
    MyReadFile.close();
    int count = 0;
    //////////////////////////////////////////////////////////////////////////////////////////////////////

    while(count != 6){
        for(int n = 0; n<grid.size(); ++n){
            for (int i = 0; i < grid.size(); ++i) {
                for (int l = 0; l < grid.size(); ++l) {
                    for (int k = 0; k < grid.size(); ++k) {
                        grid.at(n).at(i).at(l).at(k).updateStatus(grid, k, l, i, n);
                    }
                }
            }
        }
        zDim = 0;
        for(int n = 0; n<grid.size(); ++n){
            for (int i = 0; i<grid.size(); ++i) {
                //cout << "z=" << zDim<<endl;
                for (int l = 0; l < grid.size(); ++l) {
                    for (int k = 0; k<grid.size(); ++k) {
                        grid.at(n).at(i).at(l).at(k).applyNextStatus();
                        //string printMe = (grid.at(i).at(l).at(k).isActive())?"# ":". ";
                        //cout << printMe;
                    }
                   //cout << endl;
                }
                ++zDim;
            }
        }


        ++count;
        cout << "Actual count : " << count << endl;
    }



    long int sum = 0;
    for(auto & gridn: grid){
        for (auto &z : gridn) {
            for (auto &y : z) {
                for (auto &x : y) {
                    sum += x.isActive();
                }
            }
        }
    }
    return sum;
}
