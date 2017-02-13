/*************************************************************************
	> File Name: Random.h
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Tue 12 Jul 2016 12:12:38 AM PDT
 ************************************************************************/

#ifndef RANDOM_H
#define RANDOM_H

#include<cstdlib>
#include<cmath>

class Random{
public:
	static double uniform(double max=1){
		return ((double)rand()/RAND_MAX)*max;
	}
};

#endif
