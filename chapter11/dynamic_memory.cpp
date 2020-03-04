//
// Created by xmly on 2019/10/6.
//

#include <iostream>
#include "dynamic_memory.h"

using namespace std;

shared_ptr<string> factory(string arg){
    return make_shared<string>(arg);
}

void use_factory(string arg){
    shared_ptr<string> p=factory(arg);
}

int main(){
    shared_ptr<int> p3=make_shared<int>(42);
    shared_ptr<string> p4=make_shared<string>(10,'9');
    auto p6=make_shared<vector<string>>();
    //q和p3指向相同对象，此对象有两个引用者
    auto q(p3);
    shared_ptr<string> p=factory("yuff");
    StrBlob();
    StrBlob({"yu","lin","feng"});
    weak_ptr<string> wp(p);
    if(shared_ptr<string> np=wp.lock()){
        //dosomething
    }
}



