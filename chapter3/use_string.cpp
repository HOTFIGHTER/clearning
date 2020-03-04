//
// Created by xmly on 2019/9/8.
//
#include <string>
#include <iostream>

using std::string;
using namespace std;

int main() {
    string s1(10, 'c');
    string s2("value");
    const string s = "keep out!";
    for (auto &c:s) {
        cout << c << endl;
    }
    string mystring1("cdsiao");
    int num = mystring1.size();
    for (int i = 0; i < num; i++) {
        mystring1[i] = 'X';
    }
    cout << mystring1;
    string mystring;
    while (getline(cin, mystring)) {
        cout << mystring << endl;
    }
    while (cin >> mystring) {
        cout << mystring << endl;
    }
    string s5("hello world");
    //char *str=s5;不能用string对象初始化char*
    const char *str1=s.c_str();
}
