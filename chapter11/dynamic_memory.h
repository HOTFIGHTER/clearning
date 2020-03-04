//
// Created by xmly on 2019/10/6.
//

#ifndef CLEARNING_DYNAMIC_MEMORY_H
#define CLEARNING_DYNAMIC_MEMORY_H

#include <vector>
#include <iostream>
using namespace std;
class StrBlob{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> li);
    size_type size() const { return data->size();}
    bool empty() const { return data->empty();}
    void push_back(const string &t){data->push_back(t);}
    void pop_back();
    string& front();
    string& back();
    string& deref() const;
    StrBlob& incr();
private:
    size_t curr;
    shared_ptr<vector<string>> data;
    weak_ptr<vector<string>>wptr;
    shared_ptr<vector<string>> check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {
}

StrBlob::StrBlob(initializer_list<string> li):data(make_shared<vector<string>>()){}

shared_ptr<vector<string>> StrBlob::check(StrBlob::size_type i, const std::string &msg) const {
    auto ret=wptr.lock();
    if(ret){
       if(i>=ret->size()){
           throw out_of_range(msg);
       }
        return ret;
    }
}

string& StrBlob::front() {
   check(0,"front on empty StrBlob");
    return data->front();
}

void StrBlob::pop_back() {
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}

string& StrBlob::deref() const {
    auto p=check(curr,"dereference past end");
    return (*p)[curr];
}

StrBlob& StrBlob::incr() {
    check(curr,"increment past end");
    ++curr;
    return *this;
}

#endif //CLEARNING_DYNAMIC_MEMORY_H
