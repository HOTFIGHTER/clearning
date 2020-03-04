//
// Created by xmly on 2020/1/5.
//
#include <cstdio>
#include <chrono>
#include <iostream>

using namespace std;

string asString(const chrono::system_clock::time_point &tp) {
    time_t t = chrono::system_clock::to_time_t(tp);
    string ts = ctime(&t);
    ts.resize(ts.size() - 1);
    return ts;
}

int main() {
    chrono::seconds twntySeconds(20);
    chrono::hours aDay(24);
    chrono::milliseconds ms;
    ms += twntySeconds + aDay;
    --ms;
    ms *= 2;
    cout << ms.count() << "ms" << endl;
    cout << chrono::nanoseconds(ms).count() << "ns" << endl;
    chrono::milliseconds d(42);
    cout << d.count() << endl;
    chrono::seconds sec(75);
    chrono::minutes m2 = chrono::duration_cast<chrono::minutes>(sec);
    cout << m2.count() << endl;
    auto system_start = chrono::system_clock::now();
    if (chrono::system_clock::now() > system_start + sec) {

    }
    chrono::system_clock::time_point tp;
    cout << "epoch:" << asString(tp) << endl;
    tp = chrono::system_clock::time_point::min();
    cout << "min:" << asString(tp) << endl;
}


