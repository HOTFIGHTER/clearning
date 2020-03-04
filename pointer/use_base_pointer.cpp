#include <iostream>

//
// Created by xmly on 2019/6/2.
//
typedef char *pString;
int odd[] = {1, 2, 3, 4, 5};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) &attPtr(int);//声明
constexpr int new_sz(){
    return 42;
}
constexpr size_t scale(size_t cnt){
    return new_sz()*cnt;
}

int main8() {
    int i = 42;
    int *p;
    int *&r = p;//对p指针进行引用
    r = &i;
    *r = 13;
    std::cout << *p << std::endl;
    const int ci = 1024;
    const int &r1 = ci;
    //r1=42;错误引用为常量
    //int &r2=ci; 要使用const常量
    int errNumb = 0;
    int *const curErr = &errNumb;//地址不会变
    const double pi = 3.1415;
    const double *const pop = &pi;
    constexpr int mf = 20;//声明mf为常量
    const int *m1 = nullptr;
    constexpr int *m2 = nullptr;//常量指针，地址不能变
    const pString cStr = 0;
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((a)) d = a;//引用类型
    ++c;
    ++d;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << "attPtr" << attPtr(1)[1] << std::endl;
    scale(10);
}

decltype(odd) &attPtr(int i) {
    return (i % 2) ? odd : even;
}



