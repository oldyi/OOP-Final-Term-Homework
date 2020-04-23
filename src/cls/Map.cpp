/*
    created by 周鸿义 in 4/9
*/
#include "./head/Map.h"
#include "Block.cpp"
#include <iostream>
#include <cstdio>

Map::Map(int height, int width, int mines)
{
    this->height = height;
    this->width = width;
    this->mines = mines;

    for (int i = 0; i< height; i++){
        map.push_back(*(new std::vector<Block>));
        for (int j = 0; j < width; j++){
            map[i].push_back(*(new Block));
        }
    }
}

int Map::trunOf(int x, int y){
    if(!(x < height && y < width && x>=0 && y >=0)){
        return 3;
    }
    if(map[x][y].getIfMine()){
        return 2;
    }
    map[x][y].setIfShow();
    hasTurn++;
    if(map[x][y].getAround() == 0){
        int tx[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
        int ty[8] = { 1, 1, 1, 0, 0,-1,-1,-1};
        for(int i=0;i<8;i++){
            int nnx=x+tx[i],nny=y+ty[i];
            if((nnx < height && nny < width && nnx>=0 && nny >=0)&&map[nnx][nny].getIfShow()==false){
                trunOf(nnx,nny);
            }
        }
    }
    return 1;
}

void Map::setMine(int x, int y){
    int iii = mines;
    int tx[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
    int ty[8] = { 1, 1, 1, 0, 0,-1,-1,-1};
    while (iii)
    {
        int nx=rand()%width;
        int ny=rand()%height;
        if(!map[nx][ny].getIfMine()){
            iii--;
            map[nx][ny].setMine();
            for(int i=0;i<8;i++){
                int nnx=nx+tx[i],nny=ny+ty[i];
                if(nnx>=0&&nnx<width&&nny>=0&&nny<height){
                    map[nnx][nny].setAround(map[nnx][nny].getAround()+1);
                }
            }
        }
    }
    
}

void Map::Show(){
    for(int j=0;j<=width;j++)std::cout<<"_"<<"_"<<"__";
    std::cout<<std::endl<<" Q |";
    for(int j=0;j<width;j++)printf("%2d",j),std::cout<<" |";
    std::cout<<std::endl;
    int ii=0;
    for (auto i:map){
        for(int j=0;j<=width;j++)std::cout<<"---|";
        std::cout<<std::endl;
        printf("%2d",ii);
        std::cout<<" |";
        ii++;
        for (auto j:i){
            if(j.getIfShow()) {
                if(j.getIfMine()){
                    std::cout<<' '<<"💣"<<" |";
                }
                else{
                    std::cout<<' '<<(j.getAround()==0?' ':char(j.getAround()+48))<<" |";
                }
            }
            else{
                std::cout<<' '<<"□"<<" |";
            }
        }
        std::cout<<std::endl;
    }
    for(int j=0;j<=width;j++)std::cout<<"---|";
    std::cout<<std::endl<<"行 列"<<std::endl;
}

void Map::showAll(){
    for(int j=0;j<=width;j++)std::cout<<"_"<<"_"<<"__";
    std::cout<<std::endl<<" Q |";
    for(int j=0;j<width;j++)printf("%2d",j),std::cout<<" |";
    std::cout<<std::endl;
    int ii=0;
    for (auto i:map){
        for(int j=0;j<=width;j++)std::cout<<"---|";
        std::cout<<std::endl;
        printf("%2d",ii);
        std::cout<<" |";
        ii++;
        for (auto j:i){
            if(j.getIfMine()){
                std::cout<<' '<<"💣"<<"|";
            }
            else{
                std::cout<<' '<<(j.getAround()==0?' ':char(j.getAround()+48))<<" |";
            }
        }
        std::cout<<std::endl;
    }
    for(int j=0;j<=width;j++)std::cout<<"---|";
    std::cout<<std::endl;
}

bool Map::ifWin(){
    if(hasTurn==width*height-mines)return true;
    return false;
}