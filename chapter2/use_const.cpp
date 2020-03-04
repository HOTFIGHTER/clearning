//
// Created by xmly on 2019/9/8.
//
extern const int bufSiez;

int main() {
    const int bufSize = 512;
    //bufSize=512; const对象不能从新写
    //const int k;//错误，k是一个未经初始化的常量
    const int ci = 1024;
    const int &r1 = ci;
    //r1=42; r1是对常量的引用
    //int &r2=ci;//不能让非常量引用指向一个常量对象
    const int &r2 = 42;
    int i = 42;
    const int &r3 = i;
    const int &r4 = r3 * 2;
    //int &r5=r3*2;
    int *const p1 = &i;//不能改变p1的值，这是一个顶层const
    const int c2 = 42; //ci值不能改变，是一个顶层const
    const int *p2 = &ci; //p2值可以改变，是一个底层const
    constexpr int mf = 20;
    constexpr int limit = mf + 1;
    const int *p = nullptr;//p是一个指向整形常量的指针
    constexpr int *q = nullptr;//q是一个指向整形的常量指针
    typedef char *pString;
    const pString cstr = 0;//cstr是指向char的常量指针
    const pString *ps;//ps是一个指针，它的对象是指向char的常量指针
    int m = 42, *p3 = &m, &r5 = m;
    decltype(r5+0) b;
    //decltype(*p3) c; 引用类型必须初始化话
    //decltype((i)) d;
    decltype(i) e;
}
