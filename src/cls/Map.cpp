/*
    created by 周鸿义 in 4/9
*/
#include "./head/Map.h"
#include "Block.cpp"
#include <iostream>

Map::Map(int height, int width, int mines)
{
    this->height = height;
    this->width = width;
    this->mines = mines;

    for (int i = 0; i<= height; i++){
        map.push_back(*(new std::vector<Block*>));
        for (int j = 0; j <= width; j++){
            map[i].push_back(new Block);
        }
    }
}

int Map::trunOf(int x, int y){
    if(!(x <= height && y <= width && x>0 && y > 0)){
        return 3;
    }
}

void Map::setMine(int x, int y){
    int i = mines;
    while (i--)
    {

    }
    
}

void Map::Show(){
    
}

void Map::showAll(){
    for (auto i:map){
        for (auto j:i){
            if(j->getIfMine()){
                std::cout<<'*';
            }
            else{
                std::cout<<j->getAround();
            }
        }
        std::cout<<std::endl;
    }
}

bool Map::ifWin(){

}