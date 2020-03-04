//
// Created by xmly on 2020/1/28.
//
#include <cstdio>
#include <deque>
#include <string>
#include <iostream>

using namespace std;
int main(){
  deque<string> coli;
  coli.assign(3,string("jaja"));
  coli.push_back("lasy");
  coli.push_front("haha");
  copy(coli.cbegin(),coli.cend(),ostream_iterator<string>(cout,"\n"));
  cout<<endl;
}