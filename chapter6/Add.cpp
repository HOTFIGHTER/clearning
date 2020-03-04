//
// Created by xmly on 2020/1/28.
//

#include <cstdio>
#include <list>
#include "Add.h"

using namespace std;
int main(){
    list<int> coli;
    for(int i=1;i<9;i++){
      coli.push_back(i);
    }
    for_each(coli.begin(),coli.end(),Add(10));
    for_each(coli.begin(),coli.end(),Add(*coli.begin()));
}