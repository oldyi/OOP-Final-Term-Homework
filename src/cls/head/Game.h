/*
    created by 周鸿义 in 4/9
*/
#ifndef GAME_H
#define GAME_H

#include<string>
class Game
{
private:
    bool System;//记录系统类型(Windows/linux)
    const char * sys[2]={"cls","clear"};//针对不同系统的清屏命令
public:
    void start();//开始新的一局(内部)
    void showGUI();//显示开始界面
    void play();//开始游戏(总体)
    void getSystemInfo();//判断系统类型(Windows/linux)
    void clear();//清屏
};

#endif
