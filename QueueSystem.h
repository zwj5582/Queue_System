/*************************************************************************
	> File Name: QueueSystem.h
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Tue 12 Jul 2016 01:54:54 AM PDT
 ************************************************************************/

#ifndef QUEUE_SYSTEM_H
#define QUEUE_SYSTEM_H

#include"Queue.h"
#include"ServiceWindow.h"
#include"Event.h"
#include"Node.h"
#include"Random.h"

class QueueSystem{
private:
	static int ID;
	ServiceWindow* windows;
	Queue<Customer> customer_list;
	Queue<Event> event_list;
	Event* current_event;
	Queue<Customer> buff_customer_list;
	double run();
	void init();
	void end();
	void customerArrive();
	void customerLeave();
	int getIDLEservicewindow();
	int window_num;
	int total_service_time;
	int customer_stay_time;
	//int total_customer_stay_time;
	int total_customer_num;
	double avg_customer;
	double avg_stay_time;
public:
	QueueSystem(int total_service_time,int window_num);
	~QueueSystem();
	void simulate(int simulate_num);
	inline double getAvgStayTime(){
		return avg_stay_time;
	}
	inline double getAvgCustomer(){
		return avg_customer;
	}
};

#endif
