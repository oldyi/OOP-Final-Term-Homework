/*
    created by 杨新源 in 4/25
*/
#ifndef TIME_H
#define TIME_H
class Time
{
private:
        clock_t isstart, isend;
public:
        void GetCurrentTime();
        void TimeDifference(int a,int b);
};
#endif