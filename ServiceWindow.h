/*************************************************************************
	> File Name: ServiceWindow.h
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Tue 12 Jul 2016 12:01:29 AM PDT
 ************************************************************************/

#ifndef SERVICE_WINDOW_H
#define SERVICE_WINDOW_H

#include"Node.h"

enum WindowStatus{
	SERVICE,
	IDLE,
};

class ServiceWindow{
private:
	WindowStatus window_status;
	Customer customer;
public:
	inline ServiceWindow(){
		window_status=IDLE;
	}
	inline bool IsIDLE(){
		return (window_status==IDLE);
	}
	inline void serviceCustomer(const Customer& customer){
		this->customer=customer;
	}
	inline void setIDLE(){
		window_status=IDLE;
	}
	inline void setSERVICE(){
		window_status=SERVICE;
	}
	inline int getcustomerarrivetime(){
		return customer.arrive_time;
	}
	inline int getcustomerduration(){
		return customer.duration;
	}
};

#endif
