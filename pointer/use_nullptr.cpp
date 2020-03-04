//
// Created by xmly on 2019/5/27.
//

#include <iostream>
#include <type_traits>

using namespace std;

void foo(char *);

void foo(int);

int main4() {
    if (std::is_same<decltype(NULL), decltype(0)>::value)//is_same表示类型是否相等，decltype表示类型
        std::cout << " NULL == 0" << std::endl;
    if (std::is_same<decltype(NULL), decltype((void *) 0)>::value)
        std::cout << " NULL == ( void *)0" << std::endl;
    if (std::is_same<decltype(NULL), std::nullptr_t>::value)
        std::cout << " NULL == nullptr " << std::endl;
    if (std::is_same<decltype(nullptr), std::nullptr_t>::value)
        std::cout << " nullptr == nullptr " << std::endl;
    if (std::is_same<std::nullptr_t, decltype((void *) 0)>::value)
        std::cout << "nullptr ==(void*)0" << std::endl;
    foo(0);
//    foo(NULL); //编译失败，不再具有转换类型能力
    foo(nullptr); //nullptr用于隐式的类型转换
    return 0;
}

void foo(char *) {
    std::cout << " foo ( char *) is called " << std::endl;
}

void foo(int i) {
    std::cout << " foo (int ) is called " << std::endl;
}