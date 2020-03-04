//
// Created by xmly on 2019/12/10.
//

#include <mutex>
#include <thread>

bool readyFlag;
std::mutex readyFlagMutex;

void thread1(){
    std::lock_guard<std::mutex> lg(readyFlagMutex);
    readyFlag= true;
}

void thread2(){
    std::unique_lock<std::mutex> ul(readyFlagMutex);
    while(!readyFlag){
        ul.unlock();
        std::this_thread::yield();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        ul.lock();
    }
}