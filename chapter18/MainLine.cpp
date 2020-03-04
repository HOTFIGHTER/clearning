//
// Created by xmly on 2020/2/21.
//

#include <pthread.h>
#include <cstdio>
#include <iostream>

using namespace std;
struct phonebookentry {
    char name[64];
    char phonenumber[32];
    char flag[16];
};

void *fetch(void *arg) {
    cout << "fetch 2" << endl;
    struct phonebookentry *npbe;
    npbe = static_cast<phonebookentry *>(arg);
    pthread_exit(0);
}

int main() {
    struct phonebookentry *pbe;
    pthread_attr_t attr;
    pthread_t helper;
    void *status;
    pthread_create(&helper, NULL, fetch, &pbe);
    cout << "fetch 1" << endl;
    pthread_join(helper, &status);
    cout << "fetch 3" << endl;
    pthread_exit(0);
}