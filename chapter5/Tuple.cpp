//
// Created by xmly on 2020/1/3.
//
#include <csignal>
#include <tuple>
#include <string>
#include <complex.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    tuple<string, int, int, complex<double>> t;
    tuple<int, float, string> t1(41, 6.3, "nico");
    cout << get<0>(t1) << endl;
    cout << get<1>(t1) << endl;
    auto t2 = make_tuple(22, 35, "nico");
    get<1>(t1) = get<1>(t2);
    cout << get<1>(t1) << endl;
    if (t1 < t2) {
        t1 = t2;
    }
    vector<tuple<int,float>> v{make_tuple(1,1.0),make_tuple(2,2.0)};
    vector<pair<int,float>> v1{{1,1.0},{2,2.0}};
}