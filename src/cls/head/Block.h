/*
    created by 周鸿义 in 4/9
*/
#ifndef BLOCK_H
#define BLOCK_H

class Block
{
private:
    bool ifMine,ifShow;//是否有雷/是否被翻开
    char state;//当前的内容
    int around;//周围的雷数
public:
    Block();
    bool getIfMine()const; //返回此格内是否有地雷，true=有
    bool getIfShow()const; //返回此格是否已被翻开，true=是
    bool setMine();//设置地雷
    bool setIfShow();//翻开格子
    int getAround()const;//返回周围雷数
};

#endif