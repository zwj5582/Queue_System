/*************************************************************************
	> File Name: QueueSystem.cpp
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Tue 12 Jul 2016 05:45:50 AM PDT
 ************************************************************************/

#include"QueueSystem.h"
#include"Queue.h"
#include"Random.h"

static int ID=0;

QueueSystem::QueueSystem(int total_service_time,int window_num):
total_service_time(total_service_time),window_num(window_num),
customer_stay_time(0),total_customer_num(0){
	windows=new ServiceWindow[window_num];
}

QueueSystem::~QueueSystem(){
	delete[] windows;
}

void QueueSystem::simulate(int simulate_num){
	double sum=0;
	for(int i=0;i<simulate_num;i++){
		sum+=run();
	}
	avg_stay_time=(double)sum/simulate_num;
	avg_customer=(double)total_customer_num/(total_service_time*simulate_num);
}

void QueueSystem::init(){
	Event* event=new Event;
	current_event=event;
}

double QueueSystem::run(){
	init();
	while(current_event){
		if(current_event->event_type<0){
			customerArrive();
		}
		else{
			customerLeave();
		}
		delete current_event;
		current_event=event_list.dequeue();
	}
	end();
	return (double)customer_stay_time/total_customer_num;
}

void QueueSystem::end(){
	for(int i=0;i<window_num;i++){
		windows[i].setIDLE();
	}
	event_list.clearQueue();
	customer_list.clearQueue();
}

void QueueSystem::customerArrive(){
	total_customer_num++;
	int intertime=Random::uniform(100);
	int time=current_event->occur_time+intertime;
	Event tmp_event(time);
	if(time<total_service_time){
		event_list.orderqueue(tmp_event);
	}
	Customer* customer=new Customer(current_event->occur_time);
	customer_list.enqueue(*customer);
	int index=getIDLEservicewindow();
	if(index>=0){
		customer=customer_list.dequeue();
		windows[index].serviceCustomer(*customer);
		windows[index].setSERVICE();
		Event tmp_event(current_event->occur_time+customer->duration,index);
		event_list.orderqueue(tmp_event);
	}
	delete customer;
}

void QueueSystem::customerArrive(){
	Customer* customer;
	if(current_event->event_type==-2){
		customer=buff_customer_list.defromidtocustomer(current_event->ID);
	}
	else{
		customer=new Customer(current_event->occur_time);
		customer->ID=ID++;
	}
	customer_list.enqueue(*customer);
	if(customer->ID>current_event->ID){
		total_customer_num++;
	}
	Event tmp_event(current_event->occur_time+Random::uniform(100));
	if(tmp_event.occur_time<total_service_time){
		event_list.orderqueue(tmp_event);
	}
	int index=getIDLEservicewindow();
	if(index>=0){
		customer=customer_list
	}
}

void QueueSystem::customerLeave(){
	if(current_event->occur_time<total_service_time){
		customer_stay_time+=current_event->occur_time-
			windows[current_event->event_type].getcustomerarrivetime();
		if(customer_list.length()){
			Customer* customer;
			customer=customer_list.dequeue();
			windows[current_event->event_type].serviceCustomer(*customer);
			Event* event=new Event(current_event->occur_time+customer->duration,
					current_event->event_type);
			event_list.orderqueue(*event);
			delete event;
			delete customer;
		}
		else{
			windows[current_event->event_type].setIDLE();
		}
	}
}

void QueueSystem::customerleave(){
	if(current_event->occur_time<total_service_time){
		customer_stay_time+=per_time;
		Customer customer=windows[current_event->event_type];
		if(customer.duration>per_time){
			customer.duration-=per_time;
			Event tmp_event(customer_list.getlastcustomer()->arrive_time+per_time);
			event_list.orderqueue(tmp_event);
			Customer tmp_customer(customer_list.getlastcustomer()->arrive_time+per_time,
					customer.duration,-2);
			customer_list.enqueue(tmp_customer);
		}
		if(customer_list.length()){
			Customer* customer=customer_list.dequeue();
			windows[current_event->event_type].serviceCustomer(customer);
			Event tmp_event(current_event->occur_time+customer->duration,
					current_event->event_type);
			event_list.orderqueue(tmp_event);
			delete customer;
		}
		else{
			windows[current_event->event_type].setIDLE();
		}
	}
}

int QueueSystem::getIDLEservicewindow(){
	for(int i=0;i<window_num;i++){
		if(windows[i].IsIDLE()){
			return i;
		}
	}
	return -1;
}
