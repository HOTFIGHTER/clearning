//
// Created by xmly on 2019/9/8.
//
int main(){
    int a[]={0,1,2};
    //int a2[]=a; 不允许使用一个数组初始化另一个数组
    //a2=a;
    int *ptrs[10];
    //int &refs[10]=/*?*/; 不存在引用的数组
    int (*Parray)[3]=&a; //Parray指向一个含有3个整数的数组
    int (&arrRef)[3]=a; //引用一个含有3个整数的数组
    int *(&arry)[10]=ptrs;   //arry是数组的引用，改数组含有10个指针

}
