//
// Created by xmly on 2019/12/3.
//
#include <iostream>
#include <ctime>

int main() {
    clock_t m_begin = clock();
    for (int i = 0; i < 100000; i++) {
     printf("%d\n",i);
    }
    clock_t m_end = clock();
    printf("%f",(double)(m_end - m_begin)/CLOCKS_PER_SEC);
}

