/*************************************************************************
	> File Name: Event.h
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Tue 12 Jul 2016 01:25:03 AM PDT
 ************************************************************************/

#ifndef EVENT_H
#define EVENT_H

#include"Random.h"

#define RANDOM_PARAMETER 100

struct Event{
	int occur_time;
	int event_type;
	struct Event* next;
	int ID;
	Event(int occur_time=Random::uniform(RANDOM_PARAMETER),
			int event_type=-1):occur_time(occur_time),event_type(event_type),next(NULL){}
};

#endif
