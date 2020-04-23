/*
    created by 周鸿义 in 4/9
*/
#ifndef MAP_H
#define MAP_H
#include <vector>
#include "Block.h"
class Map
{
private:
    int height, width, mines, hasTurn{0};//棋盘的长,宽,雷数
    std::vector<std::vector<Block> > map;//储存棋盘
public:
    Map(int height = 10, int width = 10, int mines = 10);
    void setMine(int x,int y);//随机设置地雷
    void Show();//绘制游戏中绘制棋盘
    void showAll();//游戏结束(获胜或踩雷后)绘制棋盘;
    int trunOf(int x, int y);//翻转格子,判断是否成功,返回 1 = 没踩雷/  2 = 踩雷   / 3 = 无效输入
    bool ifWin();//判断是否结束 true = 结束
    int getAround();//记录每个格子周围的雷数
};

#endif
