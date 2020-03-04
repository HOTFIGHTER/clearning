//
// Created by xmly on 2019/9/8.
//
#include <cstdlib>

int main() {
    int ival = 1024;
    int &refVal = ival;
    //int &refVal2; //报错，引用必须初始化
    //int &refVal4=10;//报错，引用必须是一个对象
    double dval = 3.14;
    //int &refVal5=dval;//报错，引用的类型必须一致
    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;

}