//
// Created by xmly on 2019/10/11.
//

#ifndef CLEARNING_BULK_QUOTE_H
#define CLEARNING_BULK_QUOTE_H


#include "Quote.h"

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;

    Bulk_quote(const string &, double, size_t, double);

    double net_price(size_t) const override;

private:
    size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const {
    if (cnt >= min_qty) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}

#endif //CLEARNING_BULK_QUOTE_H
