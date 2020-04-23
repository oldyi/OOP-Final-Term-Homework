/*
    created by 周鸿义 in 4/9
*/
#ifndef BLOCK_H
#define BLOCK_H

class Block
{
private:
    bool ifMine,ifShow;//是否有雷/是否被翻开
    int around;//周围的雷数
public:
    Block();
    bool getIfMine()const; //返回此格内是否有地雷，true=有
    bool getIfShow()const; //返回此格是否已被翻开，true=是
    void setMine();//设置地雷
    void setIfShow();//翻开格子
    void setAround(int);//设置周围雷数
    int getAround()const;//返回周围雷数
};

#endif