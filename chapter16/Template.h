//
// Created by xmly on 2019/10/14.
//

#ifndef CLEARNING_TEMPLATE_H
#define CLEARNING_TEMPLATE_H

#include <iostream>
#include <vector>

using namespace std;

template<typename>
class Template2;

template<typename T>
class Template {
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type;

    Template();

    Template(initializer_list<T> li);

    size_type size() const {
        return data->size();
    }

    bool empty() const {
        return data->empty();
    }

    void push_back(const T &t) {
        data->push_back(t);
    };

    T &back();

    T &operator[](size_type i);

    T &operator*() const;

private:
    shared_ptr<vector<T>> data;

    //void check(size_type i, const string &msg) const;
    shared_ptr<vector<T>> check(size_t, const string &) const;

    weak_ptr<vector<T>> wptr;
    size_t curr;
};

template<typename T>
class Template2 {
    friend class Template<T>;

    friend bool operator==<T>(const Template2<T> &, const Template2<T> &);
};

template<typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

//template<typename T>
//void Template<T>::check(size_type i, const string &msg) const {
//    if (i >= data->size()) {
//        throw out_of_range(msg);
//    }
//}

template<typename T>
shared_ptr<vector<T>> Template<T>::check(size_t i, const string &msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

template<typename T>
T &Template<T>::operator[](size_type i) {
    check(0, "pop_back on empty");
    data->pop_back();
}

template<typename T>
T &Template<T>::operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

#endif //CLEARNING_TEMPLATE_H
