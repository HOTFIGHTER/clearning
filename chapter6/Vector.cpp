//
// Created by xmly on 2020/1/6.
//
#include <csignal>
#include <vector>
#include <iostream>
#include <deque>
#include <array>
#include <forward_list>

using namespace std;

int main() {
    vector<int> coli;
    for (int i = 0; i < 6; i++) {
        coli.push_back(i);
    }
    for (int i : coli) {
        cout << i << endl;
    }
    deque<float> coli2;
    for (int i = 0; i < 6; i++) {
        coli2.push_front(i);
    }
    array<string, 5> coli3 = {"hello", "worlf"};
    for (const auto &i : coli3) {
        cout << "i" << i << endl;
    }
    forward_list<long> coli4 = {2, 4, 5, 6, 7, 8};
    coli4.resize(9);
    coli4.push_front(5);
    coli4.push_front(1);
    coli4.push_front(3);
    for (auto &elem:coli4) {
        cout << elem << endl;
    }
}