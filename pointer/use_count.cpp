#include <memory>
#include <iostream>

//
// Created by xmly on 2019/5/28.
//
int main14() {
    auto pointer = std::make_shared<int>(10);
    auto pointer2 = pointer; // 引用计数+1
    auto pointer3 = pointer; // 引用计数+1
    int *p = pointer.get(); // 这样不会增加引用计数
    std::cout << " pointer . use_count () = " << pointer.use_count() << std::endl;
    std::cout << " pointer2 . use_count () = " << pointer2.use_count() << std::endl;
    std::cout << " pointer3 . use_count () = " << pointer3.use_count() << std::endl;
    pointer2.reset();
    std::cout << " reset pointer2 :" << std::endl;
    std::cout << " pointer . use_count () = " << pointer.use_count() << std::endl;
    std::cout << " pointer2 . use_count () = " << pointer2.use_count() << std::endl;
    std::cout << " pointer3 . use_count () = " << pointer3.use_count() << std::endl;
    pointer3.reset();
    std::cout << " reset pointer3 :" << std::endl;
    std::cout << " pointer . use_count () = " << pointer.use_count() << std::endl;
    std::cout << " pointer2 . use_count () = " << pointer2.use_count() << std::endl;
    std::cout << " pointer3 . use_count () = " << pointer3.use_count() << std::endl;
}
