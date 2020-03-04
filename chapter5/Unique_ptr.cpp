//
// Created by xmly on 2020/1/3.
//

#include <csignal>
#include <memory>
#include <iostream>

using namespace std;

int main() {
    unique_ptr<int, void (*)(int *)> p(new int[10], [](int *p) { delete[] p; });
    unique_ptr<int> up(new int);
    up.reset();
    unique_ptr<string> up2(new string("nico"));
    string *sp = up2.release();
    if (up2) {
        cout << *up2 << endl;
    }
    unique_ptr<int> up3=move(up);
    unique_ptr<string[]> up4(new string[10]);

}