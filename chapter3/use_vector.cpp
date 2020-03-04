

//
// Created by xmly on 2019/9/8.
//
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;

int main() {
    vector<int> ivec;
    vector<int> ivec2(ivec);
    vector<int> ivec3 = ivec;
    //vector<string> svec(ivec);类型不匹配
    vector<string> v1{"a", "an", "the"};
    //vector<string> v1("a","an","the");
    vector<int> ivec4(10, -1);
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i:v) {
        i *= i;
    }
    for (auto i:v) {
        cout << i << " ";
    }
    auto b=v.begin(),e=v.end();
//    vector<int> ivec5;
//    ivec5[0]=42;
    vector<int>::iterator it;
    string::iterator it2;
    vector<int>::const_iterator it3; //只能读
    string::const_iterator it4;
}
