//
// Created by xmly on 2019/9/15.
//

#ifndef CLEARNING_SALES_DATA_H
#define CLEARNING_SALES_DATA_H


#include <string>

class Sales_data {
public:
    //默认构造函数
    Sales_data() = default;
    Sales_data(std::istream &is);
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data &combine(const Sales_data &);
    Sales_data add(const Sales_data &, const Sales_data &);
    std::string isbn() const {
        return bookNo;
    }

private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::ostream &print(std::ostream &, const Sales_data &);

std::istream &read(std::istream &, Sales_data &);

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data Sales_data::add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

#endif //CLEARNING_SALES_DATA_H
