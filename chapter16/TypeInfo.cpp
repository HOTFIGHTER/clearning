//
// Created by xmly on 2020/2/16.
//

#include <cstdio>
#include <iostream>

using namespace std;

struct PolyBase {
    virtual ~PolyBase() {};
};

struct PolyDer : PolyBase {
    PolyDer() {};
};

struct NonPolyBase {
};

struct NonPolyDer : NonPolyBase {
    NonPolyDer(int) {};
};

class Simply{
public:
    virtual ~Simply(){};
};

int main() {
    const PolyDer pd;
    const PolyBase *ppd = &pd;
    cout << typeid(ppd).name() << endl;
    cout << typeid(*ppd).name() << endl;
    cout << boolalpha << (typeid(*ppd) == typeid(pd)) << endl;
    cout << boolalpha << (typeid(PolyDer) == typeid(const PolyDer)) << endl;
    const NonPolyDer npd(1);
    const NonPolyBase *nppd = &npd;
    cout << typeid(npd).name() << endl;
    cout << typeid(nppd).name() << endl;
    cout << typeid(*nppd).name() << endl;
    cout << boolalpha << (typeid(*nppd) == typeid(npd)) << endl;
    int i;
    cout << typeid(i).name() << endl;
    void* v=new Simply;
    //'void' is not a class
    //Simply *s= dynamic_cast<Simply*>(v);

}