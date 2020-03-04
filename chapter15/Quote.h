//
// Created by xmly on 2019/10/11.
//

#ifndef CLEARNING_QUOTE_H
#define CLEARNING_QUOTE_H

#include <string>

using namespace std;

class Quote {
public:
    Quote() = default;

    Quote(const string &book, double sales_price);

    string isbn() const {
        return bookNo;
    };

    virtual double net_price(size_t n) const {
        return n * price;
    };

    virtual ~Quote() = default;

private:
    string bookNo;
protected:
    double price = 0.0;
};


#endif //CLEARNING_QUOTE_H
