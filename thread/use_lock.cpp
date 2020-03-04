//
// Created by xmly on 2019/5/28.
//

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int number = 1;

void block_area() {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "do some mutex code" << number << std::endl;
    number++;
    lock.unlock();
}

int main10() {
    int i = 0;
    while (i < 10) {
        std::thread thd1(block_area);
        thd1.join();
        i++;
    }
}
