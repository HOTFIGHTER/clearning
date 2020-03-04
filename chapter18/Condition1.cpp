//
// Created by xmly on 2019/12/10.
//

#include <mutex>
#include <iostream>
#include <future>

bool readyFlag;
std::mutex readyMutex;
std::condition_variable readyCondVar;

void thread1() {
    std::cout << "<return>" << std::endl;
    std::cin.get();
    {
        std::lock_guard<std::mutex> lg(readyMutex);
        readyFlag = true;
    }
    readyCondVar.notify_one();
}

void thread2() {
    {
        std::unique_lock<std::mutex> ul(readyMutex);
        readyCondVar.wait(ul, [] { return readyFlag; });
    }
    std::cout << "done" << std::endl;
}

int main() {
    auto f1 = std::async(std::launch::async, thread1);
    auto f2 = std::async(std::launch::async, thread2);
}