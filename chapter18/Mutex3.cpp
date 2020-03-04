//
// Created by xmly on 2020/2/22.
//
#include <cstdio>
#include <pthread.h>
#include <iostream>

using namespace std;
pthread_mutex_t mut;
pthread_mutexattr_t mattr;
long long number;

void * increment_cout(void *pVoid){
    pthread_mutex_lock(&mut);
    number = number + 1;
    cout<<number<<endl;
    pthread_mutex_unlock(&mut);
    pthread_exit(0);
}

void * get_count(long long *pVoid){
    pthread_mutex_lock(&mut);
    *pVoid= number;
    cout<<*pVoid<<endl;
    pthread_mutex_unlock(&mut);
    pthread_exit(0);
}

int main() {
    pthread_t helper1,helper2;
    if(pthread_mutex_init(&mut, NULL)!=0){
        return 0;
    };
    long long count;
    pthread_create(&helper1,NULL,increment_cout,NULL);
    pthread_create(&helper2, NULL, reinterpret_cast<void *(*)(void *)>(get_count), &count);
    pthread_create(&helper2,NULL,increment_cout,NULL);
    pthread_create(&helper2,NULL,increment_cout,NULL);
    pthread_create(&helper1, NULL, reinterpret_cast<void *(*)(void *)>(get_count), &count);
    pthread_mutex_destroy(&mut);
    pthread_exit(0);
}
