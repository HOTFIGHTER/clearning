//
// Created by xmly on 2019/10/9.
//

#ifndef CLEARNING_STRING2_H
#define CLEARNING_STRING2_H

class String {
public:
    //构造
    String(char *str = "")
            : _str(new char[strlen(str) + 5]) {
        *((int *) (_str - 4)) = 1;
        strcpy(_str + 4, str);
    }

    //拷贝构造

    // s2(s1)
    String(const String &s)
            : _str(s._str) {
        ++(*((int *) (_str - 4)));
    }


    //赋值运算符重载
    //s2 = s1
    String &operator=(const String &s) {
        if (this != &s) {
            if (--(*((int *) (_str - 4))) == 0) {
                delete[](_str - 4);
            }

            _str = s._str;

            ++(*((int *) (_str - 4)));
        }
        return *this;
    }


    //析构
    ~String() {
        if (--(*((int *) (_str - 4))) == 0) {
            delete[](_str - 4);
        }
    }


    const char *c_str() {
        return _str;
    }


    void CopyOnWrite() {
        if ((*((int *) (_str - 4))) > 1) {
            char *newstr = new char[strlen(_str) + 5];
            newstr += 4;
            strcpy(newstr, _str);

            --(*((int *) (_str - 4)));
            _str = newstr;
            (*((int *) (_str - 4))) = 1;
        }
    }


    char &operator[](size_t pos) {
        CopyOnWrite();
        return _str[pos];
    }


    const char &operator[](size_t pos) const {
        return _str[pos];
    }


private:
    char *_str; // 引用计数在头上
};

#endif //CLEARNING_STRING2_H
