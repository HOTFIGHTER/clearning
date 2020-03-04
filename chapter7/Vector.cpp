//
// Created by xmly on 2020/1/28.
//
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <array>

using namespace std;
int main(){
  const vector<int>v1={1,2,3,4,5};
  const vector<int>v2({1,2,3,4,5});
  list<int> l;
  const vector<int> v3(l.begin(),l.end());
  int array[]={2,3,4,5,6};
  set<int> c(begin(array),end(array));
  vector<int> v4;
  vector<int> v5=std::move(v4);
  array<int,4> coli2={1,2,3,4};

}