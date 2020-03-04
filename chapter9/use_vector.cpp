//
// Created by xmly on 2019/9/15.
//

#include <vector>
#include <iostream>
#include <list>
#include <forward_list>
#include <array>

using namespace std;

list<string> authors = {"Milton", "austen"};
vector<const char *> articles = {"a", "an", "the"};
list<string> svec(10, "hi");
forward_list<int> ivec(10);

bool find(vector<int>::iterator a, vector<int>::iterator b, int c) {
    for (a; a != b; a++) {
        if (*a == c) {
            return true;
        }
    }
    return false;
}

int main() {
    list<int> ilist;
    for(size_t ix=0;ix!=4;++ix){
        ilist.push_front(ix);//入栈
    }
    array<int, 10> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> a2 = {0};
    a1 = a2;
    a2 = {0};
    cout << *a1.end() << endl;
    list<string> names;
    vector<const char *> oldstyle = {"a", "an", "the"};
    names.assign(oldstyle.begin(), oldstyle.end());
    cout << *names.begin() << endl;
    vector<int> vec(20);//必须事先指定这个大小，才知道end的指向
    vec[0] = 4;
    vec[1] = 5;
    vec[2] = 2;
    vec[3] = 8;
    vec[4] = 9;
    vec[5] = 6;
    vec[6] = 7;
    int find_member = 4;
    if (find(vec.begin(), vec.end(), find_member)) {
        cout << "We have found it" << endl;
    } else{
        cout << "Sorry,there is no " << find_member << " in the range" << endl;
    }

    return 0;
}
