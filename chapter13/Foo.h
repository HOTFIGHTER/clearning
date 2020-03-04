//
// Created by xmly on 2019/10/8.
//

#ifndef CLEARNING_FOO_H
#define CLEARNING_FOO_H

#include <iostream>
using namespace std;

class Foo {
public:
    Foo &operator=(const Foo &)= delete;//阻止赋值
    Foo()= default;
    Foo(const Foo&)= delete; //阻止拷贝
    ~Foo()= default;
private:
    int bookNo;
    int units_sold;
    string *ps;
};

Foo &Foo::operator=(const Foo &rhs) {
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    auto newp=new string(*rhs.ps);
    delete ps;
    ps=newp;
    return *this;
//    delete ps;
//    ps=new string(*rhs.ps);
//    return *this;
}

void calcualate(){
    int i=42;
    int &r=i;
    int &&rr=i;  //不能将右值绑定到左值上
    int &r2=i*2; //错误i*2是一个右值
    const int &r3=i*42;
    int &&rr2=i*42; 
}

#endif //CLEARNING_FOO_H
