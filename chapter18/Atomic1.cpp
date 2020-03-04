//
// Created by xmly on 2019/12/10.
//

#include <atomic>
#include <thread>
#include <future>
#include <iostream>

std::atomic<bool> readyFlag(false);

void thread1(){
    readyFlag.store(true);
}

void thread2(){
    while(!readyFlag.load()){
       std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout<<"value"<<std::endl;
}

int main(){
    auto p=std::async(std::launch::async,thread1);
    auto c=std::async(std::launch::async,thread2);
}