//
// Created by xmly on 2019/5/26.
//
#include <iostream>
#include <thread>
void foo(){
    std :: cout << " hello world " << std :: endl ;
}

int main9(){
    std :: thread t( foo);
    t. join ();
    return 0;
}
