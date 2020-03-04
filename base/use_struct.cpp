//
// Created by xmly on 2019/5/28.
//
#include <stdio.h>
struct Student{
    char *name;
    int age;
    float score;
};

struct X{
    friend void f(){

    }

    X(){
//        f();
    }
    void g();
    void h();
};

void X::g() {
    //return f();
}
void f();
void X::h(){
    return f();
}

void display(struct Student stu){
    printf("%s的年龄是 %d，成绩是 %f\n", stu.name, stu.age, stu.score);
}

int main(){
    struct Student stu1;
    //为结构体的成员变量赋值
    stu1.name = "小明";
    stu1.age = 15;
    stu1.score = 92.5;
    //调用函数
    display(stu1);
    X x;
//    x.f();
    x.g();
    x.h();
    return 0;
}
