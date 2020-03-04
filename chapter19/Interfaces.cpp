//
// Created by xmly on 2020/2/17.
//
#include <cstdio>
#include <ostream>
#include <iostream>

using namespace std;

class Intable {
public:
    virtual ~Intable() {};

    //纯虚函数，const表示自身引用
    virtual int toInt() const =0;
};

class Printable {
public:
    virtual ~Printable() {};

    virtual void print(ostream &) const =0;
};

/**
 * 多继承必须将虚方法都实现
 * */
class Able : public Printable, public Intable {
    int myData;
public:
    Able(int x) {
        myData = x;
    }

    int toInt() const {
        return myData;
    }

    void print(ostream &o) const {

    }
};

void testIntable(const Intable &n) {
    cout << n.toInt() + 1 << endl;
}

int main() {
    Able a(7);
    testIntable(a);
}