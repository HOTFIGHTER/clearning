//
// Created by xmly on 2019/10/13.
//

#ifndef CLEARNING_BASE_H
#define CLEARNING_BASE_H


#include "Quote.h"

class Base {
public:
    string f(Quote quote){
        return quote.isbn();
    }
};


#endif //CLEARNING_BASE_H
