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
    Block(){ //开始时默认无雷
        ifMine = false;
        ifShow = false;
        around = 0;
    }
    bool getIfMine()const{ //返回此格内是否有地雷，true=有
         return ifMine;
    }
    bool getIfShow()const{ //返回此格是否已被翻开，true=是
        return (ifShow);
    }
    void setMine(){//设置地雷
        this->ifMine = true;
    }
    void setIfShow(){//翻开格子
        this->ifShow = true;
    }
    void setAround(int ar){//设置周围雷数
        around = ar;
    }
    int getAround()const{//返回周围雷数
        return around;
    }
};

#endif
