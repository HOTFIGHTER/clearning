//
// Created by xmly on 2020/2/17.
//
#include <cstdio>
#include <iostream>

using namespace std;

template<class T>
class Singleton {
    Singleton(const Singleton &);

    Singleton &operator=(const Singleton &);

protected:
    /**这里一定要加{}，不然是声明，会有问题*/
    Singleton(){};

    virtual ~Singleton(){};
public:
    static T &instance() {
        static T theInstance;
        return theInstance;
    }
};

class MyClass : public Singleton<MyClass> {
    int x;
protected:
    friend class Singleton<MyClass>;

    MyClass() {
        x = 0;
    }

public:
    void setValue(int n) {
        x = n;
    }

    int getValue() const {
        return x;
    }
};

int main() {
    MyClass &m = MyClass::instance();
    cout << m.getValue() << endl;
    m.setValue(1);
    cout << m.getValue() << endl;
}