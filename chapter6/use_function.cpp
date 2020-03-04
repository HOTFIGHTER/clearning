//
// Created by xmly on 2019/9/10.
//
#include <iostream>

using namespace std;

int fact(int);

void print(const int *);

void print(const int[]);

void print(const int[10]);

void print(int (&arr)[10]);

char &get_val(string &str, string::size_type ix) {
    return str[ix];
}

int &get(int *arry, int index) {
    return arry[index];
}

int &get2(int (&arry)[10], int index) {
    return arry[index];
}

//函数指针
bool (*pf)(const string &,const string &);

int main() {
    int j = fact(5);
    cout << "5! is " << j << endl;
    int k[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(k);
    string s("a value");
    get_val(s, 0) = 'A';
    cout << s << endl;
    int ia[10];
    for (int i = 0; i != 10; ++i) {
        get(ia, i) = i;
        cout << ia[i] << endl;
    }
    //bool b1=pf("hello","goodbye");
    //bool b2=(*pf)("hello","goodbye");
    return 0;
}

int fact(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}

void print(int (&arr)[10]) {
    for (auto elem:arr) {
        cout << elem << endl;
    }
}

void error_msg(initializer_list<string> li) {
    for (auto beg = li.begin(); beg != li.end(); ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
}



