//
// Created by xmly on 2019/12/24.
//
#include <cstdio>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    shared_ptr<string> pNico(new string("nico"));
    shared_ptr<string> pJutta(new string("jutta"));
    //pJutta = new string("hahaha");
    pJutta.reset(new string("nico"));
    (*pJutta)[0] = 'N';
    pJutta->replace(0, 1, "J");
    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    for (auto ptr:whoMadeCoffee) {
        cout << *ptr << endl;
    }
    cout << endl;
    *pNico = "Nicola";
    cout << "use_count:" << whoMadeCoffee[0].use_count() << endl;
    shared_ptr<string> pNico2(new string("nico2"), [](string *p) {
        cout << "delete " << *p << endl;
        delete p;
    });
    pNico2 = nullptr;
    whoMadeCoffee.resize(2);
    shared_ptr<int> p(new int[10],[](int *p){
        delete[] p;
    });
    shared_ptr<int> p2(new int[10],default_delete<int[]>());
}

