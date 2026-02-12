#ifndef BUSINESS_H
#define BUSINESS_H
#include <string>
using namespace std;

struct Business {
    string ownerName;
    string companyName;
    int regNumber;
    int fopGroup;
};

void addBusiness(Business*& arr, int& size);
void deleteBusiness(Business*& arr, int& size);
void editBusiness(Business* arr, int size);
void sortByFOP(Business* arr, int size);
void sortByRegNumber(Business* arr, int size);
void showBusinesses(Business* arr, int size);
void saveToFile(Business* arr, int size);
void loadFromFile(Business*& arr, int& size);
void saveToFile(Business* arr, int size);
void loadFromFile(Business*& arr, int& size);
int normalizeFOPGroup(int group);

#endif
