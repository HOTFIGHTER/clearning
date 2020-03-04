//
// Created by xmly on 2019/10/19.
//

#ifndef CLEARNING_STACK_H
#define CLEARNING_STACK_H

template<typename T>
class my_stack;

//list_node模板定义
template<typename T>
class list_node {
    T value;
    list_node *next;

    list_node(T const &v, list_node *n) : value(v), next(n) {};

    friend class my_stack<T>;
};

template<typename T=int>
class my_stack {
    typedef list_node<T> node_type;
    node_type *head;

    my_stack operator=(my_stack const &) {}

    my_stack(my_stack const &s) {};
public:
    my_stack() : head(0) {};

    ~my_stack() {
        while (!empty()) {
            pop();
        }
    }

    bool empty() const {
        return head == 0;
    }

    void pop();

    void push(T const &v) {
        //初始化函数定义在list_node的私有化函数
        head = new node_type(v, head);
    }
};

template<typename T>
void my_stack<T>::pop() {
    if (head) {
        node_type *tmp = head;
        head = head->next;
        delete tmp;
    }
}

#endif //CLEARNING_STACK_H
