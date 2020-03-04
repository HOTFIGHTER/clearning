#include <iostream>

//
// Created by xmly on 2019/6/1.
//
int main21() {
    std::cout << "/*";
    std::cout << "*/";
    //std::cout<</*"*/"*/;
    //std::cout<</* "*/" /* "/*" */;
    int sum = 0, value = 0;
    while (std::cin >> value) {
        sum += value;
        std::cout << "Sum is:" << sum << std::endl;
    }
    return 0;
}
