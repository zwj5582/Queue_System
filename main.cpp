/*************************************************************************
	> File Name: main.cpp
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Tue 12 Jul 2016 06:54:08 PM PDT
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include"QueueSystem.h"
using namespace std;

int main(){

srand((unsigned)time(0));

int total_service_time=240;

int window_num=4;

int simulate_num=10;

QueueSystem queuesystem(total_service_time,window_num);

queuesystem.simulate(simulate_num);

cout<<"The average time of Customer stay in bank: "<<queuesystem.getAvgStayTime()<<endl;

cout<<"the average time of Customer service time in bank: "<<\
	queuesystem.getAvgCustomer()<<endl;

return 0;

}

