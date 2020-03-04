//
// Created by xmly on 2020/2/17.
//
#include <cstdio>
#include <iostream>

using namespace std;

class Singleton {
private:
    int i;

    Singleton(int x) : i(x) {};

    Singleton &operator=(Singleton &);

    Singleton(const Singleton &);

public:
    static Singleton &instance() {
        static Singleton s(47);
        return s;
    }

    int getValue() {
        return i;
    }

    void setValue(int x) {
        i = x;
    }
};


int main() {
    Singleton &s = Singleton::instance();
    cout << s.getValue() << endl;
    Singleton &s2 = Singleton::instance();
    s2.setValue(9);
    cout << s.getValue() << endl;
}
