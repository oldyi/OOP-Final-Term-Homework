/*
    created by 杨新源 in 4/25
*/
#ifndef TIME_H
#define TIME_H
#include<iostream>
#include <cstdio>
#include <ctime>
class Time
{
private:
        clock_t isstart, isend;
public:
        void GetCurrentTime(){
            time_t now = time(0);
            tm* ltm = localtime(&now);
            std::cout << "当前时间:" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << std::endl;
            std::cin.get();
        }
        void TimeDifference(int a,int b){
            if (a==1) {
                isstart = time(0);                  //开始计时
            }
            if (b==1) {  							//结束扫雷
                isend = time(0);                    //结束计时
            }
            std::cout << "本次扫雷用时:" << (isend - isstart) << "s" << std::endl;
            std::cin.get();
        }
};
#endif
