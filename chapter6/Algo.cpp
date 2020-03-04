//
// Created by xmly on 2020/1/6.
//
#include <csignal>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> coli = {2, 5, 4, 1, 6, 3};
    auto minpos = min_element(coli.cbegin(), coli.cend());
    cout << "min:" << *minpos << endl;
    auto maxpos = max_element(coli.cbegin(), coli.cend());
    cout << "max:" << *maxpos << endl;
    /**这里不能用cbegin，sort会改变数据，cbegin只能get不能修改*/
    sort(coli.begin(), coli.end());
    auto pos3 = find(coli.cbegin(), coli.cend(), 3);
    cout << "pos3:" << *pos3 << endl;
//    reverse(pos3, coli.end());
    for (auto elem:coli) {
        cout << elem << ' ';
    }
    cout << endl;
    vector<int>::const_iterator minpos2 = min_element(coli.begin(), coli.end());
//    auto pos4=find_if(coli.begin,coli.end(),[](int i){
//        return i==25||i==35;
//    });
    transform(coli.begin(), coli.end(), coli.begin(), [](double d) { return d * d; });
}