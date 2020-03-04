//
// Created by xmly on 2019/12/10.
//

#include <mutex>
#include <queue>
#include <thread>
#include <iostream>
#include <future>

std::queue<int> queue;
std::mutex queueMutex;
std::condition_variable queueCondVar;

void provider(int val) {
    for (int i = 0; i < 6; i++) {
        std::lock_guard<std::mutex> lg(queueMutex);
        queue.push(val + i);
    }
    queueCondVar.notify_one();
    std::this_thread::sleep_for(std::chrono::milliseconds(val));
}

void consumer(int num) {
    while (true) {
        int val;
        {
            std::unique_lock<std::mutex> ul(queueMutex);
            queueCondVar.wait(ul,[]{ return !queue.empty();});
            val=queue.front();
            queue.pop();
        }
        std::cout<<"consumer "<<num<<":"<<val<<std::endl;
    }
}

int main(){
    auto p1=std::async(std::launch::async,provider,100);
    auto p2=std::async(std::launch::async,provider,300);
    auto p3=std::async(std::launch::async,provider,500);

    auto c1=std::async(std::launch::async,consumer,1);
    auto c2=std::async(std::launch::async,consumer,2);
}
