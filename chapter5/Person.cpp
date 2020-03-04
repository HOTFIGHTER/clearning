//
// Created by xmly on 2020/1/4.
//

#include <csignal>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Person {
public:
    string name;
    /**shared_ptr是非线程安全的*/
    shared_ptr<Person> mother;
    shared_ptr<Person> father;
    //vector<shared_ptr<Person>> kids;
    /**weak_ptr可以保证在initFamily退出作用域后即使kid被持有也会被释放掉kid*/
    vector<weak_ptr<Person>> kids;

    Person(const string &n, shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr)
            : name(n), mother(m), father(f) {
        cout << "create " << name << endl;
    }

    ~Person() {
        cout << "delete " << name << endl;
    }
};

shared_ptr<Person> initFamily(const string &name) {
    shared_ptr<Person> mon(new Person(name + "'s mon"));
    shared_ptr<Person> dad(new Person(name + "'s dad"));
    shared_ptr<Person> kid(new Person(name + "'s kid"));
    mon->kids.push_back(kid);
    dad->kids.push_back(kid);
    /**离开作用域时mon和dad就被释放了*/
    return kid;
}

int main() {
    shared_ptr<Person> p = initFamily("nico");
    cout << "nico is shared " << p.use_count() << " times" << endl;
    shared_ptr<Person> m = initFamily("yu");
    //atomic_store(&p,m);
    atomic_exchange(&p, m);
    p = initFamily("jim");
}