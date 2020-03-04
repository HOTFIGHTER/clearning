//
// Created by xmly on 2019/10/10.
//
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int (*)(int, int)> binops;

int add(int i, int j) { return i + j; }

int main() {
    int (*fp)(int, int)= add;
    binops.insert({"+", fp});
}

ostream &operator<<(ostream &os, const int i) {
    os << " " + i << endl;
    return os;
}

int operator+(const int &lhs, const int &rhs) {
    int sum = lhs;
    sum += rhs;
    return sum;
}

string operator=(string li) {

}

string *elements;

string &operator[](size_t n) {
    return elements[n];
}

const string &operator[](size_t n) const {
    return elements[n];
}

//string* operator->() const{
//    return & this->operator*();
//}


