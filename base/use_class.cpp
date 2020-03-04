//
// Created by xmly on 2019/5/28.
//

#include <iostream>

class Base {
public :
    int value1;
    int value2;

    Base() {
        value1 = 1;
    }

    Base(int value) : Base() {// 委托Base () 构造函数
        value2 = value;
    }
};

class Sales_data {
    friend Sales_data add(const Sales_data & ); //友元函数
    friend std::istream &read(std::istream &, Sales_data &);

public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n) :
            bookNo(s), units_good(1) {};
    void some_member() const;
private:
    std::string bookNo = "yu";
    unsigned units_good = 0;
    mutable size_t access_ctr;//const方法也可以改变access_ctr
};

void Sales_data::some_member() const {
    ++access_ctr;
}

int main23() {
    Base b(2);
    std::cout << b.value1 << std::endl;
    std::cout << b.value2 << std::endl;
}