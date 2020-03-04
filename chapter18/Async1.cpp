//
// Created by xmly on 2019/12/9.
//

#include <random>
#include <iostream>
#include <thread>
#include <future>

int doSomething(char c){
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(10,1000);
    for(int i=0;i<10;++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
        std::cout.put(c).flush();
    }
    return c;
}

int func1(){
    return doSomething('>');
}

int func2(){
    return doSomething('*');
}

int main(){
    std::future<int> result1(std::async(func1));
    int result2=func2();
    int result=result2+result1.get();
    std::cout<<"result1 +result2"<<result<<std::endl;
}