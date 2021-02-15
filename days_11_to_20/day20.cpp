//
// Created by Olivier on 10/02/2021.
//
#include "../head.h"

struct Tile{
    vector<string> borders; // DEFINING : 0 => top, 1 => bottom, 2 => right, 3 => left
    vector<int> neighbours; // DEFINING : 0 => top, 1 => bottom, 2 => right, 3 => left
};


int day20(string path){
    ifstream MyReadFile(path);
    string text, tileStr;
    int line = 0;
    int id;
    map<int, Tile> tiles{};
    Tile current;
    while(getline(MyReadFile, text)){
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        tileStr += text;
        if(text.empty()){
            Tile currentTile;
            currentTile.borders = {"", "", "", ""};
            currentTile.neighbours = {};
            int id = stoi(tileStr.substr(tileStr.find(" "), tileStr.find(':')+1));
            string content = tileStr.substr(tileStr.find(':')+1, tileStr.size());     
            // cout << "Content : " << content << endl;       
            int tileSize = sqrt(content.size());
            // cout << "Tile : " << id << endl;
            for (int i = 0; i < tileSize; i++){
                string line = content.substr(tileSize*i, tileSize);
                // cout << "Line " << i << " : " << line << endl;
                if(i == 0){
                    currentTile.borders[0] = line;
                }else if(i == tileSize-1){
                    currentTile.borders[1] = line;
                }
                currentTile.borders[2] += line.back();
                currentTile.borders[3] += line.front();
            }
            tiles.emplace(id, currentTile);
            tileStr = "";
            // cout << endl;
        }
        
    }
    //Emplace last tile
    Tile currentTile;
    currentTile.borders = {"", "", "", ""};
    currentTile.neighbours = {};
    int nid = stoi(tileStr.substr(tileStr.find(" "), tileStr.find(':')+1));
    string content = tileStr.substr(tileStr.find(':')+1, tileStr.size());     
    // cout << "Content : " << content << endl;       
    int tileSize = sqrt(content.size());
    // cout << "Tile : " << nid << endl;
    for (int i = 0; i < tileSize; i++){
        string line = content.substr(tileSize*i, tileSize);
        // cout << "Line " << i << " : " << line << endl;
        if(i == 0){
            currentTile.borders[0] = line;
        }else if(i == tileSize-1){
            currentTile.borders[1] = line;
        }
        currentTile.borders[2] += line.back();
        currentTile.borders[3] += line.front();
    }
    tiles.emplace(nid, currentTile);
    tileStr = "";
    // cout << endl;

    for(auto tile : tiles){
        for(auto checkingTile : tiles){
            if(tile.first != checkingTile.first){
                for(string border : tile.second.borders){
                    if(border != ""){
                        string reversedBorder = border;
                        reverse(reversedBorder.begin(), reversedBorder.end());
                        if(find(checkingTile.second.borders.begin(), checkingTile.second.borders.end(), border) != checkingTile.second.borders.end()
                        || find(checkingTile.second.borders.begin(), checkingTile.second.borders.end(), reversedBorder) != checkingTile.second.borders.end()){
                            // cout << "It's a match between " << tile.first << " and " << checkingTile.first << endl;
                            int pos = ((find(checkingTile.second.borders.begin(), checkingTile.second.borders.end(), border) != checkingTile.second.borders.end())?
                            find(checkingTile.second.borders.begin(), checkingTile.second.borders.end(), border) :
                            find(checkingTile.second.borders.begin(), checkingTile.second.borders.end(), reversedBorder))  - checkingTile.second.borders.begin();
                            tiles.at(checkingTile.first).borders[pos] = "";
                            tiles.at(checkingTile.first).neighbours.push_back(tile.first);
                            
                            int tilePos = find(tile.second.borders.begin(), tile.second.borders.end(), border) - tile.second.borders.begin();
                            tiles.at(tile.first).borders[tilePos] = "";
                            tiles.at(tile.first).neighbours.push_back(checkingTile  .first);
                        }
                    }
                }
            }
        }
    }
    unsigned long int result = 1;
    for(const auto & tile : tiles){
        int nbNeighbours = tile.second.neighbours.size();
        // cout << tile.first << " neighbours : ";
        // printVector(tile.second.neighbours);
        if(nbNeighbours == 2){
            cout << endl << "−−−−−−−−−−−−−−−−−−−−" << tile.first << " is a corner" << "−−−−−−−−−−−−−−−−−−−−−−−"<< endl << endl;
            result *= tile.first;
        }
    }
    cout << result << endl;
    return 0;
}