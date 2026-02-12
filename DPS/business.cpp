#include "business.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

static int lastRegNumber = 1000;

int normalizeFOPGroup(int group) {
    if (group < 1) return 1;
    if (group > 3) return 3;
    return group;
}

void sortByRegNumber(Business* arr, int size) {
    sort(arr, arr + size, [](const Business& a, const Business& b) {
        return a.regNumber < b.regNumber;
        });
}

void addBusiness(Business*& arr, int& size) {
    Business* temp = new Business[size + 1];
    for (int i = 0; i < size; i++)
        temp[i] = arr[i];

    cin.ignore();
    cout << "ПIБ власника: ";
    getline(cin, temp[size].ownerName);

    cout << "Назва компанiї: ";
    getline(cin, temp[size].companyName);

    cout << "Група ФОП (1-3): ";
    cin >> temp[size].fopGroup;
    temp[size].fopGroup = normalizeFOPGroup(temp[size].fopGroup);

    temp[size].regNumber = lastRegNumber++;

    delete[] arr;
    arr = temp;
    size++;
}

void deleteBusiness(Business*& arr, int& size) {
    int num;
    cout << "Реєстрацiйний номер: ";
    cin >> num;

    int index = -1;
    for (int i = 0; i < size; i++)
        if (arr[i].regNumber == num)
            index = i;

    if (index == -1) return;

    Business* temp = new Business[size - 1];
    for (int i = 0, j = 0; i < size; i++)
        if (i != index)
            temp[j++] = arr[i];

    delete[] arr;
    arr = temp;
    size--;
}

void editBusiness(Business* arr, int size) {
    int num;
    cout << "Реєстрацiйний номер: ";
    cin >> num;

    for (int i = 0; i < size; i++) {
        if (arr[i].regNumber == num) {
            cin.ignore();
            cout << "Нове ПIБ: ";
            getline(cin, arr[i].ownerName);

            cout << "Нова назва: ";
            getline(cin, arr[i].companyName);

            cout << "Нова група ФОП (1-3): ";
            cin >> arr[i].fopGroup;
            arr[i].fopGroup = normalizeFOPGroup(arr[i].fopGroup);
        }
    }
}

void sortByFOP(Business* arr, int size) {
    sort(arr, arr + size, [](const Business& a, const Business& b) {
        return a.fopGroup < b.fopGroup;
        });
}

void showBusinesses(Business* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i].regNumber << " | "
            << arr[i].ownerName << " | "
            << arr[i].companyName << " | ФОП "
            << arr[i].fopGroup << endl;
    }
}

void saveToFile(Business* arr, int size) {
    ofstream file("base.txt");
    if (!file) return;

    file << size << endl;
    for (int i = 0; i < size; i++) {
        file << arr[i].ownerName << endl;
        file << arr[i].companyName << endl;
        file << arr[i].regNumber << endl;
        file << arr[i].fopGroup << endl;
    }
    file.close();
}

void loadFromFile(Business*& arr, int& size) {
    ifstream file("base.txt");
    if (!file) {
        arr = nullptr;
        size = 0;
        return;
    }

    file >> size;
    file.ignore();

    arr = new Business[size];
    for (int i = 0; i < size; i++) {
        getline(file, arr[i].ownerName);
        getline(file, arr[i].companyName);
        file >> arr[i].regNumber;
        file >> arr[i].fopGroup;
        file.ignore();

        if (arr[i].regNumber >= lastRegNumber)
            lastRegNumber = arr[i].regNumber + 1;
    }
    file.close();
}
