//
// Created by xmly on 2019/5/27.
//
#include <string>
#include <iostream>

std::tuple<int, double, std::__make_tuple_return<const char (&)[5]>::type> f() {
    return std :: make_tuple (1, 2.3 , "456 ");
}

int main6(){
    auto [x, y, z] = f();
    std :: cout << x << ", " << y << ", " << z << std :: endl ;
    return 0;
}

