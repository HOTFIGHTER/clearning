//
// Created by xmly on 2019/5/27.
//

#include <iostream>
#include <vector>

class Foo {
public:
    int value_a ;
    int value_b ;
    Foo( int a, int b) : value_a (a), value_b (b) {}
};

int main22 () {
    int arr [3] = {1, 2, 3};
    Foo foo (1, 2);
    std :: vector <int > vec = {1, 2, 3, 4, 5};
    std :: cout << " arr [0]: " << arr [0] << std :: endl ;
    std :: cout << " foo :" << foo. value_a << ", " << foo. value_b << std :: endl ;
    for (std :: vector <int >:: iterator it = vec. begin (); it != vec. end (); ++ it) {
        std :: cout << *it << std :: endl ;
    }
    std::vector<int> v1;
    std::vector<int> v2{10};
    std::vector<int> v3(10,1);
    std::vector<int> v4{10,1};
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    for(auto a:v1){
        a*=a;
        std::cout<<a<<std::endl;
    }
    return 0;
}