//
// Created by xmly on 2020/1/28.
//

#ifndef CLEARNING_ADD_H
#define CLEARNING_ADD_H


class Add {
private:
    int addValue;
public:
    Add(int v) : addValue(v) {

    }

    void operator()(int &elem) const {
        elem += addValue;
    }
};


#endif //CLEARNING_ADD_H
