/*
    created by 周鸿义 in 4/9
*/
#ifndef GAME_CPP
#define GAME_CPP
#include <iostream>
#include "./head/Game.h"
#include "./Map.cpp"

void Game::clear(){
    system(sys[System]);
}

void Game::showGUI(){
    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"|               扫雷             |"<<std::endl;
    std::cout<<"|                                |"<<std::endl;
    std::cout<<"|                                |"<<std::endl;
    std::cout<<"|   1:开始游戏         2:退出    |"<<std::endl;
    std::cout<<"|                                |"<<std::endl;
    std::cout<<"|                                |"<<std::endl;
    std::cout<<"----------------------------------"<<std::endl;
}


bool Game::getSystemInfo(){
    if(system("cls")==1){
        System=0;
    }
    else{
        System=1;
        system(sys[System]);
    }
}


void Game::play(){
    int opt;
    getSystemInfo();
    showGUI();
    std::cout<<"请输入要执行的操作:"<<std::endl;
    std::cin>>opt;
    while (opt!=2){
        clear();
        showGUI();
        std::cout<<"请输入有效的操作:"<<std::endl;
        std::cin>>opt;
        if(opt!=1){
            continue;
        }
        else{
            start();
        }
    }
    std::cout<<"感谢游玩，按任意键退出"<<std::endl;
    std::cin.get();
    std::cin.get();
}

void Game::start(){
    Map erea;
    erea.Show();
    std::cout<<"请选择一个位置以开始"<<std::endl;
    int x,y;
    bool ifLose = false;
    std::cin>>x>>y;
    erea.setMine(x, y);
    while(!erea.ifWin()){
        clear();
        erea.Show();
        std::cin>>x>>y;
        switch(erea.trunOf(x,y)){
            case 1: break;

            case 2: std::cout<<"无效值!请重新输入"<<std::endl;
                    break;

            case 3: ifLose = true;
                    break;
        }
        clear();
        erea.showAll();
        if(ifLose){
            std::cout<<"  Y     Y  OOOOO   U     U    L        OOOOO    SSSSS  EEEEEEE "<<std::endl;
            std::cout<<"   Y   Y  O     O  U     U    L       O     O  S     S E       "<<std::endl;
            std::cout<<"    Y Y  O       O U     U    L      O       O  SSS    E______ "<<std::endl;
            std::cout<<"     Y   O       O U     U    L      O       O    SSS  E^^^^^^ "<<std::endl;
            std::cout<<"     Y    O     O  U     U    L       O     O  S     S E       "<<std::endl;
            std::cout<<"     Y     OOOOO    UUUUU     LLLLLLL  OOOOO    SSSSS  EEEEEEE "<<std::endl;
        }
        else {
            std::cout<<"you win!"<<std::endl;
        }
        std::cout<<"按任意键以继续"<<std::endl;
    }
}

#endif