//
// Created by Olivier on 03/02/2021.
//
#include "../head.h"

void day7(){
    ifstream MyReadFile("../inputs/day7input");
    string text;
    map<string, map<string, int>> mapOfBags;
    map<string, vector<string>> mapBagChildren;
    vector<string> emptyBags{};
    vector<string> canContain{};
    while (getline(MyReadFile, text)){
        text.erase(remove(text.begin(), text.end(), '\n'), text.end());
        text.erase(remove(text.begin(), text.end(), '\r'), text.end());
        string contain = "contain ";
        int contain_size = contain.size();
        string color = text.substr(0, text.find(" bags"));
        if(text.find("no other bags.") == string::npos){
            mapOfBags.emplace(color, map<string, int>{});
            mapBagChildren.emplace(color, vector<string>{});
            string containAll = text.substr(text.find("contain ")+contain_size, text.find('.'));
            containAll.erase(containAll.size()-1);
            while(!text.empty()){
                int nb = (unsigned char) containAll[0] - '0';
                containAll.erase(0,2);
                auto bagOrbags = (containAll.find(" bag") < containAll.find(" bags"))?containAll.find(" bag"):containAll.find(" bags");
                string color2 = containAll.substr(0, bagOrbags);
                mapOfBags.find(color)->second.emplace(color2, nb);
                for (int i = 0; i < nb; ++i) {
                    mapBagChildren.find(color)->second.push_back(color2);
                }
                if (containAll.find(',') != string::npos){
                    containAll.erase(0, containAll.find(',')+2);
                } else {
                    break;
                }
            }
        }
        else{
            emptyBags.push_back(color);
        }
    }
    //First part
    int prevSize;
    while(prevSize != canContain.size()){
        prevSize = canContain.size();
        for(auto const & m : mapOfBags){
            for(auto const & container : m.second){
                if(container.first == "shiny gold" || find(canContain.begin(), canContain.end(), container.first) != canContain.end()){
                    if(find(canContain.begin(), canContain.end(), m.first) == canContain.end()){
                        canContain.push_back(m.first);
                    }
                }
            }
        }
    }
    cout << canContain.size() << " bags can contain a shiny gold bag" <<endl;

    //Second part
    vector<string> bags{"shiny gold"};
    for(int i = 0; i < bags.size(); ++i){
        if(mapBagChildren.find(bags.at(i)) != mapBagChildren.end()) {
            auto inside = mapBagChildren.find(bags.at(i))->second;
            for (const auto &color2 : inside) {
                bags.push_back(color2);
            }
        }
    }
    cout << "Shiny gold contains : "<<bags.size()-1<< " bags" << endl;

    MyReadFile.close();
}