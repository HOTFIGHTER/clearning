//
// Created by xmly on 2019/10/9.
//

#ifndef CLEARNING_STRING_H
#define CLEARNING_STRING_H

#include <iostream>

using namespace std;

class String {
public:
    void show() {
        cout << _str << endl;
    }

    //构造
    String(const char *str = "")
            : _str(new char[strlen(str) + 1]), _pCount(new size_t(1)) {
        strcpy(_str, str);
    }

    //析构
    ~String() {
        if (--(*_pCount) == 0) {
            delete[] _str;
            delete _pCount;
            _str = NULL;
            _pCount = NULL;
        }
    }

    //拷贝构造
    String(const String &s)
            : _str(s._str), _pCount(s._pCount) {
        ++(*_pCount);
    }

    //赋值运算符重载
    String &operator=(const String &s) {
        if (this != &s) {
            if (--(*_pCount) == 0) {
                delete[] _str;
                delete _pCount;
                _str = NULL;
                _pCount = NULL;
            }
            _str = s._str;
            _pCount = s._pCount;
            ++(*_pCount);
        }


        return *this;
    }

    //写时拷贝
    void CopyOnWrite() {
        if (*_pCount > 1) {
            char *newstr = new char[strlen(_str) + 1];
            strcpy(newstr, _str);
            _str = newstr;

            --(*_pCount);
            _pCount = new size_t(1);
        }
    }

    //可读可写
    char &operator[](size_t pos) {
        CopyOnWrite();
        return _str[pos];
    }

    //可读
    const char &operator[](size_t pos) const {
        return _str[pos];
    }


private:
    char *_str;
    size_t *_pCount;
};


#endif //CLEARNING_STRING_H
