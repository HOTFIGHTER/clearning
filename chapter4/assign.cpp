//
// Created by xmly on 2019/9/9.
//
#include <string>
using std::string
int main(){
    int i=0,j=0,k=0;
    const int ci=i;
    string s1="a string",*p=&s1;
    auto n=(*p).size();
    n=p->size();
}
