/*************************************************************************
	> File Name: Node.h
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Tue 12 Jul 2016 12:11:42 AM PDT
 ************************************************************************/

#ifndef NODE_H
#define NODE_H
#include"Random.h"

#define RANDOM_PARAMETER 100

struct Node{
	int arrive_time;
	int duration;
	struct Node* next;
	int ID;
	Node(int arrive=0,int dur=Random::uniform(RANDOM_PARAMETER)):
		arrive_time(arrive),duration(dur),next(NULL){}
};

typedef struct Node Node;
typedef struct Node Customer;

#endif
