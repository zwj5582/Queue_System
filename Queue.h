/*************************************************************************
	> File Name: Queue.h
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Tue 12 Jul 2016 01:35:49 AM PDT
 ************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include"Random.h"
#include"ServiceWindow.h"
#include"Event.h"
#include"Node.h"

template<typename T>
class Queue{
public:
	Queue();
	~Queue();
	void clearQueue();
	T* enqueue(Customer& customer);
	T* dequeue();
	T* orderqueue(Event& event);
	T* getlastcustomer();
	int length();
private:
	T* front;
	T* rear;
};
template<typename T>
T* defromIdtocustomer(int id){
	T* head=front->next;
	if(head==NULL){
		return NULL;
	}
	T* pre=front;
	while(head!=NULL){
		if(id==head->ID){
			break;
		}
		head=head->next;
		pre=pre->next;
	}
	if(head==NULL){
		return NULL;
	}
	if(head==front->next){
		front->next=head->next;
	}
	else if(head=rear){
		pre->next=NULL;
		rear=pre;
	}
	else{
		pre->next=head->next;
	}
	return head;
}
template<typename T>
Queue<T>::Queue(){
	front=new T;
	if(!front){
		exit(-1);
	}
	front->next=NULL;
	rear=front;
}

template<typename T>
Queue<T>::~Queue(){
	clearQueue();
	delete front;
}

template<typename T>
void Queue<T>::clearQueue(){
	if(!front){
		return;
	}
	T* head=front->next;
	while(head!=NULL){
		T* tmp=head;
		head=head->next;
		delete tmp;
	}
	front->next=NULL;
	rear=front;
}
template<typename T>
T* Queue<T>::getlastcustomer(){
	return rear;
}
template<typename T>
T* Queue<T>::enqueue(Customer& c){
	if(!front){
		return NULL;
	}
	Customer* customer=new Customer;
	if(!customer){
		exit(-1);
	}
	*customer=c;
	if(front==rear){
		front->next=customer;
		customer->next=NULL;
		rear=customer;
	}
	else{
		rear->next=customer;
		customer->next=NULL;
		rear=customer;
	}
	return front;
}

template<typename T>
T* Queue<T>::dequeue(){
	if(!front||front->next==NULL){
		return NULL;
	}
	T* tmp;
	if(front->next==rear){
		tmp=rear;
		front->next=NULL;
		rear=front;
	}
	else{
		tmp=front->next;
		front->next=tmp->next;
	}
	return tmp;
}
template<typename T>
T* Queue<T>::orderqueue(Event& e){
	if(!front){
		return NULL;
	}
	Event* event=new Event;
	*event=e;
	if(front==rear){
		front->next=event;
		rear=event;
		rear->next=NULL;
	}
	else{
		T* head=front->next;
		T* p=front;
		while(head!=NULL){
			if(head->occur_time>event->occur_time){
				break;
			}
			p=p->next;
			head=head->next;
		}
		if(p==front){
			event->next=front->next;
			front->next=event;
		}
		else if(p==rear){
			rear->next=event;
			rear=event;
			rear->next=NULL;
		}
		else{
			event->next=p->next;
			p->next=event;
		}
	}
	return front;
}
template<typename T>
int Queue<T>::length(){
	if(!front){
		return -1;
	}
	int i=0;
	T* head=front->next;
	while(head!=NULL){
		i++;
	}
	return i;
}
#endif
