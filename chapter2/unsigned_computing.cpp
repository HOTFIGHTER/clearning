//
// Created by xmly on 2019/9/8.
//

#include <iostream>

int main() {
    unsigned u = 10, u2 = 42;
    int i = -42;
    std::cout << i + i << std::endl;
    std::cout << u + i << std::endl;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    int i2 = 10;
    std::cout << i2 - u << std::endl;
    std::cout << u - i2 << std::endl;
}
