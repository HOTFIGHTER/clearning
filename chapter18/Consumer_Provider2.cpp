//
// Created by xmly on 2020/2/22.
//

#include <cstdio>
#include <pthread.h>
#include <assert.h>
#include <iostream>
#include <string.h>

using namespace std;
const int BSIZE = 1024;
typedef struct {
    string buf[BSIZE];
    int occupied = 0;
    int nextin = 0;
    int nextout = 0;
    pthread_mutex_t mutex;
    pthread_cond_t more;
    pthread_cond_t less;
} buffer_t;

buffer_t *buffer;

void *produce(void *item) {
    pthread_mutex_lock(&buffer->mutex);
    string *ass = (string *) item;
    while (buffer->occupied >= BSIZE) {
        pthread_cond_wait(&buffer->less, &buffer->mutex);
    }
    assert(buffer->occupied < BSIZE);
    buffer->buf[buffer->nextin++] = *ass;
    buffer->nextin %= BSIZE;
    buffer->occupied++;
    pthread_cond_signal(&buffer->more);
    pthread_mutex_unlock(&buffer->mutex);
}

void *consume(void *item) {
    pthread_mutex_lock(&buffer->mutex);
    while (buffer->occupied <= 0) {
        pthread_cond_wait(&buffer->more, &buffer->mutex);
    }
    assert(buffer->occupied > 0);
    buffer->buf[buffer->nextout++] = "";
    buffer->nextout %= BSIZE;
    buffer->occupied--;
    pthread_cond_signal(&buffer->less);
    pthread_mutex_unlock(&buffer->mutex);
}

int main() {
    buffer = (buffer_t *) malloc(sizeof(buffer_t));
    string a = "a";
    string b = "a";
    pthread_t comsumer, producer;
    //pthread_create(&producer, NULL, produce, &a);
    for (int i = 0; i < 8; i++) {
        pthread_create(&producer, NULL, produce, &b);
    }
    pthread_create(&comsumer, NULL, consume, 0);
    void *status;
    pthread_join(producer, &status);
    pthread_join(comsumer, &status);
    cout << buffer->buf[0] << endl;
    cout << buffer->buf[1] << endl;
    // pthread_exit(0);
    //pthread_create(&comsumer, NULL, reinterpret_cast<void *(*)(void *)>(consume), 0);
    //pthread_create(&comsumer, NULL, reinterpret_cast<void *(*)(void *)>(consume), 0);
}