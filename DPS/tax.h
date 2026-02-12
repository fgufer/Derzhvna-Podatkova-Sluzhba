#ifndef TAX_H
#define TAX_H
#include "business.h"
struct TaxInfo {
    int regNumber;
    double income;
    double paidTax;
};
void taxMenu(Business* businesses, int bSize);
#endif
