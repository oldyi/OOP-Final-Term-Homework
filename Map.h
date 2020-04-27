/*
    created by 周鸿义 in 4/9
*/
#ifndef MAP_H
#define MAP_H
#include <vector>
#include "Block.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "./Game.h"
class Game;
class Map
{
private:
    int height, width, mines, hasTurn{0};//棋盘的长,宽,雷数
    std::vector<std::vector<Block> > map;//储存棋盘
public:
    Map(int height = 10, int width = 10, int mines = 10){
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
    void setMine(int x,int y){//随机设置地雷
        int iii = mines;
        int tx[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
        int ty[8] = { 1, 1, 1, 0, 0,-1,-1,-1};
        srand((unsigned int)(time(NULL)));
        while (iii)
        {
            int nx=rand()%width;
            int ny=rand()%height;
            if(!map[nx][ny].getIfMine()&&!(nx==x&&ny==y)){
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
    void Show(){//绘制游戏中绘制棋盘
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
                        std::cout<<' '<<"雷"<<"|";
                    }
                    else{
                        std::cout<<' '<<(j.getAround()==0?' ':char(j.getAround()+48))<<" |";
                    }
                }
                else{
                    if(1){
                        std::cout<<' '<<"□"<<" |";
                    }
                    else {
                        std::cout<<' '<<"□"<<"|";
                    }
                }
            }
            std::cout<<std::endl;
        }
        for(int j=0;j<=width;j++)std::cout<<"---|";
        std::cout<<std::endl<<"行 列"<<std::endl;
    }
    void showAll(){//游戏结束(获胜或踩雷后)绘制棋盘;
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
                    std::cout<<' '<<"雷"<<"|";
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
    int trunOf(int x, int y){//翻转格子,判断是否成功,返回 1 = 没踩雷/  2 = 踩雷   / 3 = 无效输入
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
    bool ifWin(){//判断是否结束 true = 结束
        if(hasTurn==width*height-mines)return true;
        return false;
    }
    
    int getAround();//记录每个格子周围的雷数
};

#endif
