/*
    created by 周鸿义 in 4/9
*/
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "./Map.h"
#include "./Time.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
class Map;
struct paiming{
     std::string a;
     int t;
};
class Game
{
private:
    static bool System;//记录系统类型(Windows/linux)
    const char * sys[2]={"cls","clear"};//针对不同系统的清屏命令
    paiming s;
public:
    void start(){//开始新的一局(内部)
        Time t;
        Map* erea;
        nandujiemian();
        int temp = nanduxuanze();
        switch (temp){
            case 1:
                erea = new Map{8,8,10};
                break;
            case 2:
                erea = new Map{16,16,40};
                break;
            case 3:
                erea = new Map{20,20,99};
                break;
            case 4:
                int kuan,gao,lei;
                zidingyi();
                std::cin>>kuan>>gao>>lei;                                            //读取数据
                while(kuan<=0||kuan>25||gao<=0||gao>25||lei<=0||lei>=kuan*gao-5){    //防止出现错误
                    zidingyi();
                    std::cout<<"请输入正确的条件"<<std::endl;
                    std::cin>>kuan>>gao>>lei;
                }
                erea = new Map{kuan,gao,lei};
                break;
        }
        clear();
        std::cout<<"请选择一个位置以开始"<<std::endl;
        erea->Show();
        int x,y;
        bool ifLose = false;
        std::cin>>x>>y;
        t.TimeDifference(1,0);
        erea->setMine(x, y);
        erea->trunOf(x,y);
        while(!erea->ifWin()){
            clear();
            erea->Show();
            std::cin>>x>>y;
            switch(erea->trunOf(x,y)){
                case 1: break;

                case 3: std::cout<<"无效值!请重新输入"<<std::endl;
                        break;

                case 2: ifLose = true;
                        break;
            }
            clear();
            erea->Show();
            if(ifLose){
                clear();
                erea->showAll();
                std::cout<<"  Y     Y  oOOOo   U     U    L        oOOOo    sSSSs  EEEEEEE "<<std::endl
                         <<"   Y   Y  O     O  U     U    L       O     O  S       E       "<<std::endl
                         <<"    Y Y  O       O U     U    L      O       O  SSs    E______ "<<std::endl
                         <<"     Y   O       O U     U    L      O       O    SSs  E^^^^^^ "<<std::endl
                         <<"     Y    O     O  U     U    L       O     O  s     S E       "<<std::endl
                         <<"     Y     OOOOO    UUUUU     LLLLLLL  OOOOO    SSSSS  EEEEEEE "<<std::endl;
                t.GetCurrentTime();
                t.TimeDifference(0,1);
                std::cout<<"按任意键以继续"<<std::endl;
                std::cin.get();
                break;
            }
            else /*if(erea->ifWin())*/ {
                clear();
                erea->showAll();
                std::cout<<"you win!"<<std::endl;
                if(temp != 4) {
                    t.GetCurrentTime();
                    t.TimeDifference(0,1);
                    std::cout<<"是否要加入排行榜（1：是 ；其它：否）？\n 请选择："<<std::endl;
                    std::cin>>x;
                    if(x==1){
                        int timeaa;
                        timeaa=t.GetTimeDifference();
                        add2Cata(/*timeaa*/rand()%100 , temp);
                    }
                }
                std::cin.get();
                std::cout<<"按任意键以继续"<<std::endl;
                std::cin.get();
                break;
            }
            
        }
        delete erea;
    }
    void showGUI(){//显示开始界面
        std::cout<<"----------------------------------"<<std::endl
             <<"|               扫雷             |"<<std::endl
             <<"|                                |"<<std::endl
             <<"|                                |"<<std::endl
             <<"|   1:开始游戏         2:退出    |"<<std::endl
             <<"|                                |"<<std::endl
             <<"|                                |"<<std::endl
             <<"----------------------------------"<<std::endl;
    }
    void play(){//开始游戏(总体)
        std::string opt;
        getSystemInfo();
        showGUI();
        std::cout<<"请输入要执行的操作:"<<std::endl;
        std::cin>>opt;
        while (opt!="2"){
            clear();
            if(opt!="1") {
                showGUI();
                std::cout<<"请输入有效的操作:"<<std::endl;
                std::cin>>opt;
            }
            if(opt!="1"){
                continue;
            }
            else{
                start();
                clear();
                showGUI();
                std::cin>>opt;
            }
        }
        std::cout<<"感谢游玩，按任意键退出"<<std::endl;
        std::cin.get();
        std::cin.get();
    }
    void getSystemInfo(){//判断系统类型(Windows/linux)
        if(system("cls")==0){
            System=0;
            system("chcp 65001");
            system("color 70");
            system(sys[System]);
        }
        else{
            System=1;
            system("setterm -inversescreen on");
            system(sys[System]);
        }
    }
    void clear(){//清屏
        system(sys[System]);
    }
    void nandujiemian(){
        std::cout<<"---------------请选择难度--------------- "<<std::endl;
        std::cout<<" _______________      _________________"<<std::endl;
        std::cout<<"|      简单     |    |       普通       |"<<std::endl;
        std::cout<<"|     8 × 8     |    |      16×16       |"<<std::endl;
        std::cout<<"|    10个雷     |    |      40个雷      |"<<std::endl;
        std::cout<<"|    输入'1'    |    |      输入'2'     |"<<std::endl;                    
        std::cout<<"-----------------    -------------------"<<std::endl;          //界面展示
        std::cout<<" _______________      _________________"<<std::endl;
        std::cout<<"|      困难     |    |      自定义      |"<<std::endl;
        std::cout<<"|     20×20     |    |                  |"<<std::endl;
        std::cout<<"|     99个雷    |    |                  |"<<std::endl;
        std::cout<<"|    输入'3'    |    |      输入'4'     |"<<std::endl;
        std::cout<<"-----------------    -------------------"<<std::endl;

    }

    int nanduxuanze(){    //1=简单，棋盘8*8，10雷；2=普通，棋盘16*16，40雷；3=困难，棋盘20*20，99雷；4=自定义难度，?*?,?
        int a;      //a代表难度选择
        std::cin>>a;
        while (a!=1&&a!=2&&a!=3&&a!=4){
            clear();
            std::cout<<"请输入有效的操作:"<<std::endl;
            std::cin>>a;
        }
        return a;     //返回参数
    }

    void zidingyi(){      //自定义情况下
        clear();
        std::cout<<"请输入你需要的棋盘"<<std::endl;
        std::cout<<"宽度：   高度：     雷数："<<std::endl;
    }

    static bool GetSystem() {
        return System;
    }

    void add2Cata(int timeaaa , int difficulty){
        std::string filelistN[4] = {
            "",
            "./name1.sav",
            "./name2.sav",
            "./name3.sav"
        };
        std::string filelistT[4] = {
            "",
            "./time1.sav",
            "./time2.sav",
            "./time3.sav"
        };
        std::cout<<"请输入姓名：\n";
        std::cin>>s.a;
        s.t=timeaaa;
        std::cout<<std::endl;
        int i=0,j=0,k=0;
        paiming aa[15];
        paiming ppp;
        std::ifstream infilexm;
        std::ifstream infilecj;
        std::ofstream outfilexm;
        std::ofstream outfilecj;
        std::string temp;

        outfilecj.open(filelistT[difficulty], std::ios::out | std::ios::in);
        outfilecj.close();
        outfilexm.open(filelistN[difficulty], std::ios::out | std::ios::in);
        outfilexm.close();
        
        std::cout<<"排名"<<"\t"<<"昵称"<<"   时间(s)"<<std::endl;
        infilexm.open(filelistN[difficulty], std::ios::in);

        while(getline(infilexm,temp) && i<11)
        {
            aa[i].a=temp;
            i++;
        }
        infilexm.close();

        infilecj.open(filelistT[difficulty], std::ios::in);
        while (infilecj >> aa[j].t && j<=i)
        {
            j++;
        }
        infilecj.close();
        i--;
        if(i<10){
            i++;
            aa[i]=s;
            aa[i].t=timeaaa;
        }
        else if(aa[i].t>timeaaa){
            aa[i]=s;
            aa[i].t=timeaaa;
        }
        

        if(i >= 1){
            for(k=i;k>=1;k--){
                for(j=0;j<k;j++){
                    if(aa[j].t>aa[j+1].t){
                        ppp=aa[j];
                        aa[j]=aa[j+1];
                        aa[j+1]=ppp;
                    }
                }
            }
        }

        outfilexm.open(filelistN[difficulty], std::ios::out | std::ios::trunc);
        outfilecj.open(filelistT[difficulty], std::ios::out | std::ios::trunc);

        for(k=0;k<=i;k++){
            std::cout<<k+1<<"\t"<<aa[k].a<<"\t"<<aa[k].t<<std::endl;
            outfilexm<<aa[k].a<<std::endl;
            outfilecj<<int(aa[k].t)<<std::endl;
        }

        outfilexm.close();
        outfilecj.close();

     }
};
bool Game::System = 0 ;
#endif
