//
// Created by xmly on 2019/10/11.
//

#include "Bulk_quote.h"

int main() {
    Quote item;   //基类对象
    Bulk_quote bulk;  //派生类对象
    Quote *p = &item; //p指向quote对象
    p = &bulk;        //p指向bulk的Quote对象
    Quote &r = bulk;  //r绑定到bulk的Quote对象
}