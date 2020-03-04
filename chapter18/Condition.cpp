//
// Created by xmly on 2020/2/22.
//
#include <cstdio>
#include <pthread.h>
using namespace std;
pthread_mutex_t count_lock;
pthread_cond_t count_nonzero;
unsigned count;
pthread_mutex_t rsrc_lock;
pthread_cond_t rsrc_add;
unsigned int resources;

void decrement_count() {
    pthread_mutex_lock(&count_lock);
    while (count == 0){
        pthread_cond_wait(&count_nonzero, &count_lock);
    }
    count = count - 1;
    pthread_mutex_unlock(&count_lock);
}

void increment_count() {
    pthread_mutex_lock(&count_lock);
    if (count > 0){
        pthread_cond_signal(&count_nonzero);
    }
    count = count + 1;
    pthread_mutex_unlock(&count_lock);
}

void get_resources(int amount) {
    pthread_mutex_lock(&rsrc_lock);
    while (resources < amount) {
        pthread_cond_wait(&rsrc_add, &rsrc_lock);
    }
    resources -= amount;
    pthread_mutex_unlock(&rsrc_lock);
}

void add_resources(int amount) {
    pthread_mutex_lock(&rsrc_lock);
    resources += amount;
    pthread_cond_broadcast(&rsrc_add);
    pthread_mutex_unlock(&rsrc_lock);
}