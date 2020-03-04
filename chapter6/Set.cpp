//
// Created by xmly on 2020/1/6.
//
#include <csignal>
#include <string>
#include <set>
#include <iostream>

using namespace std;

int main() {
    multiset<string> cities{"Hanover", "Paris"};
    for (const auto &m:cities) {
        cout << m << endl;
    }
    cities.insert({"shanghai","sichuan","anhui"});

}