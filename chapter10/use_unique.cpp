//
// Created by xmly on 2019/9/18.
//
#include <string>
#include <vector>
#include <tclDecls.h>
#include <iostream>

using namespace std;

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(), sz);
}

void biggies(vector<string> &words) {
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b) {
                    return a.size() < b.size();
                });
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string &a) {
                          return a.size() >= sz;
                      });
    auto wb = find_if(words.begin(), words.end(),
                      [=](const string &s) {
                          return;
                          s.size() >= sz;
                      });
    for_each(wc, words.end(), [](const string &s) {
        cout << s << "";
    });
}

void fcn1() {
    size_t v1 = 42;
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f();
}

void fcn2() {
    size_t v1 = 42;
    auto f2 = [&v1] {
        return v1;
    };
    v1 = 0;
    auto j = f2();
}

void fcn3() {
    size_t v1 = 42;
    auto f = [v1]()mutable {
        return ++v1;
    };
    v1 = 0;
    auto j = f();
}

int main() {

}
