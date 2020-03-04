#include <memory>
#include <iostream>

//
// Created by xmly on 2019/5/28.
//
void foo( std :: shared_ptr <int > i){
    (*i)++;
}

int main13(){
    //构造shared_ptr指针
    auto pointer = std :: make_shared <int >(10) ;
    foo( pointer );
    std :: cout << * pointer << std :: endl ;
    return 0;
}
