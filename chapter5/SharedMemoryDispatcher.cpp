//
// Created by xmly on 2020/1/3.
//

#include "SharedMemoryDispatcher.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <zconf.h>
#include <sys/errno.h>
#include <iostream>

using namespace std;


void doInit(){
    /**动态方式new一个类为堆对象*/
    SharedMemoryDispatcher* sharedMemoryDispatcher=new SharedMemoryDispatcher;
    /**超出作用域smp会被销毁，但是new出来的对象不会被销毁*/
    shared_ptr<int> smp = sharedMemoryDispatcher->getSharedIntMemory(100);
    /**以栈的方式使用SharedMemoryDispatcher，用完销毁*/
//    SharedMemoryDispatcher sharedMemoryDispatcher;
//    sharedMemoryDispatcher->getSharedIntMemory(100);
    for (int i = 0; i < 100; i++) {
        smp.get()[i] = i * 42;
    }
    cout<<smp.get()[1]<<endl;
    smp.reset();
    delete sharedMemoryDispatcher;
}

int main() {
    doInit();
    cout<<"end"<<endl;
}



void SharedMemoryDispatcher::operator()(int *p) {
//    if (shm_unlink("/tmp234") != 0) {
//        cerr << "unlink failed" << endl;
//    }else{
//        cout<<"success"<<endl;
//    }
}

shared_ptr<int> SharedMemoryDispatcher::getSharedIntMemory(int num) {
    void *men;
    int shmfd = shm_open("/tmp234", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
    if (shmfd < 0) {
        throw std::string(strerror(errno));
    }
    if (ftruncate(shmfd, num * sizeof(int)) == -1) {
        throw std::string(strerror(errno));
    }
    men = mmap(nullptr, num * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (men == MAP_FAILED) {
        throw std::string(strerror(errno));
    }
    //return shared_ptr<int>(static_cast<int *>(men), SharedMemoryDispatcher());
    return shared_ptr<int>(static_cast<int *>(men), [](int *p){
        if (shm_unlink("/tmp234") != 0) {
            cerr << "unlink failed" << endl;
        }else{
            cout<<"success"<<endl;
        }
    });
}