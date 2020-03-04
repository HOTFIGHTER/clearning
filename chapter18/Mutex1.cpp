//
// Created by xmly on 2019/12/10.
//

#include <mutex>
#include <iostream>
#include <future>

std::mutex printMutex;

void doSomething(){
    int val;
    std::mutex valMutex;
    {
        std::lock_guard<std::mutex> lg(valMutex);
        ++val;
        printf("%d\n",val);
    }//保证锁的lock和auto unlock
}

void print(const std::string& s){
    std::lock_guard<std::mutex> l(printMutex);
    for(char c:s){
        std::cout.put(c);
    }
    std::cout<<std::endl;
}

int main(){
    doSomething();
    /**发射状态,异步执行*/
    auto f1=std::async(std::launch::async,print,"hello me\n");
    auto f2=std::async(std::launch::async,print,"from second\n");
    print("hello from the main thread\n");

}