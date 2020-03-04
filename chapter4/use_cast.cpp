//
// Created by xmly on 2019/9/9.
//
#include <iostream>

using namespace std;

int main() {
    int i = 2, j = 1;
    double slope = static_cast<double>(j) / i; //静态类型转换
    double d = 3.14;
    void *p = &d;
    double *dp = static_cast<double *>(p);
    cout << *dp << endl;
    //const_cast只能改变运算对象的底层const
    const char *pc = "yu linfeng";
    char *p2 = const_cast<char *>(pc);
    cout << p2 << endl;
    //reinterpret_cast为运算对象的位模式提供较低层次的重新解释
    int *ip;
    char *pc= reinterpret_cast<char*>(ip);

}
