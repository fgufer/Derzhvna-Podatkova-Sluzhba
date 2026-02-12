#include "tax.h"
#include <iostream>

double taxRate(int group) {
    if (group == 1) return 0.05;
    if (group == 2) return 0.1;
    return 0.15;
}
void taxMenu(Business* b, int size) {
    int num;
    cout << "Реєстрацiйний номер: ";
    cin >> num;

    for (int i = 0; i < size; i++) {
        if (b[i].regNumber == num) {
            double income, paid;
            cout << "Дохiд: ";
            cin >> income;
            cout << "Оплачено податкiв: ";
            cin >> paid;

            double mustPay = income * taxRate(b[i].fopGroup);
            double diff = paid - mustPay;

            if (diff > 0)
                cout << "Переплата: " << diff << endl;
            else
                cout << "Недоплата: " << -diff << endl;
        }
    }
}
