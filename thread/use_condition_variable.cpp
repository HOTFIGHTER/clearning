//
// Created by xmly on 2019/5/28.
//
//std::condition_variable 是为了解决死锁而生的

#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>

int main12() {
    std::queue<int> produced_nums;
    std::mutex m;
    std::condition_variable cond_var;
    //结束标记
    bool done = false;
    bool notified = false;

    std::thread producer([&]() {
        for (int i = 0; i < 5; i++) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            //创建互斥变量
            std::unique_lock<std::mutex> lock(m);
            std::cout << " producing " << i << std::endl;
            produced_nums.push(i);
            notified = true;
            lock.unlock();
            cond_var.notify_one();
        }
        done = true;
        notified = true;
        cond_var.notify_one();
    });

    std::thread consumer([&]() {
        std::unique_lock<std::mutex> lock(m);
        while (!done) {
            while (!notified) { // 循环避免虚假唤醒
                cond_var.wait(lock);
            }
            while (!produced_nums.empty()) {
                std::cout << " consuming " << produced_nums.front() << std::endl;
                produced_nums.pop();
            }
            notified = false;
        }
        lock.unlock();
    });

    producer.join();
    consumer.join();
}
