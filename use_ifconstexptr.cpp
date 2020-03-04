//
// Created by xmly on 2019/5/27.
//
#include <iostream>

template<typename R, typename T> R print_type_info(const T &t) {
    if constexpr (std::is_integral<T>::value) {
        return t + 1;
    } else {
        return t + 0.02;
    }
}

template < typename ... Args >
void magic ( Args ... args ) {
    std :: cout << sizeof ...( args ) << std :: endl ;
}

int main7() {
    //std::cout << print_type_info(5) << std::endl;
    //std::cout << print_type_info(3.14) << std::endl;
    magic (); //0
    magic (1); //1
    magic (1, ""); //2
}