#ifndef _FACT_H_
#define _FACT_H_
#include <pthread.h>
#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


int res = 1;
int x = 2;
struct ThreadData {
    int start, stop;
    int array;
};
void* factor(struct ThreadData* td);

#endif
