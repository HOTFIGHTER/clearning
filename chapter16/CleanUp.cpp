//
// Created by xmly on 2020/2/16.
//
#include <cstdio>
#include <iostream>

using namespace std;
class Trace{
  static int counter;
  int objid;
public:
    Trace(){
        objid=counter++;
        cout<<"constructing Trace #"<<objid<<endl;
        if(objid==3){
            throw 3;
        }
    }
    ~ Trace(){
        cout<<"destructing Trace #"<<objid<<endl;
    }
};
int Trace::counter=0;

int main(){
    try {
       Trace n1;
       Trace array[5];
       Trace n2;
    }catch(int j){
        cout<<"caught "<<j<<endl;
    }

}