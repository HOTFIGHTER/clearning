//
// Created by xmly on 2020/1/3.
//
#include <csignal>
#include <ostream>
#include <iostream>

using namespace std;

typedef pair<int, float> IntFloatPair;


int main() {
    IntFloatPair p(42, 3.14);
    cout << get<0>(p) << endl;
    cout << get<1>(p) << endl;
    cout << tuple_size<IntFloatPair>::value << endl;
    tuple_element<0, IntFloatPair>::type;
}

template<typename T1, typename T2>
ostream &operator<<(ostream &strm, const pair<T1, T2> &p) {
    return strm << "[" << p.first << "," << p.second << "]";
};

