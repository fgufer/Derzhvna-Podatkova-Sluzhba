#include <iostream>
#include <clocale>
#include "business.h"
#include "tax.h"
using namespace std;
void showFOPInfo() {
    cout << "ФОП 1 — малий бiзнес (5%)\n";
    cout << "ФОП 2 — середній бiзнес (10%)\n";
    cout << "ФОП 3 — великий бiзнес (15%)\n";
}
int main() {
    setlocale(0, "");
    Business* businesses = nullptr;
    int size = 0;
    loadFromFile(businesses, size);
    int choice;
    do {
        cout << "\n=== ДПС України ===\n"
            << "1. Додати бiзнес\n"
            << "2. Видалити бiзнес\n"
            << "3. Редагувати бiзнес\n"
            << "4. Сортувати за ФОП\n"
            << "5. Сортувати за реєстрацiйним номером\n"
            << "6. Iнформацiя про ФОП\n"
            << "7. Показати базу\n"
            << "8. Розрахувати податки\n"
            << "0. Вихiд\n";
        cin >> choice;
        switch (choice) {
        case 1:
            addBusiness(businesses, size);
            saveToFile(businesses, size);
            break;
        case 2:
            deleteBusiness(businesses, size);
            saveToFile(businesses, size);
            break;
        case 3:
            editBusiness(businesses, size);
            saveToFile(businesses, size);
            break;
        case 4:
            sortByFOP(businesses, size);
            saveToFile(businesses, size);
            break;
        case 5:
            sortByRegNumber(businesses, size);
            saveToFile(businesses, size);
            break;
        case 6:
            showFOPInfo();
            break;
        case 7:
            showBusinesses(businesses, size);
            break;
        case 8:
            taxMenu(businesses, size);
            break;
        case 1981:
            cout << "Vamos Fernando!";
            break;
        case 1994:
            cout << "Ja, Nein, Rammstein!";
            break;
        case 2000:
            cout << "Послухайте Собак у космосi!";
            break;
        }
    } while (choice != 0);
    saveToFile(businesses, size);
    delete[] businesses;
}
