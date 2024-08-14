//
// Created by Scout on 12/08/24.
//

#ifndef SUPERHASHTABLE_HASHTABLE_H
#define SUPERHASHTABLE_HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>
using namespace std;
class HashTable {
private:
    struct Entry {
        string key;
        int value;
        bool isOccupied;
        bool isDeleted;
        Entry() : isOccupied(false), isDeleted(false) {}
    };
    vector<Entry> table;
    int sizePtr;
    int hash(const string key);
public:
    HashTable(int size);
    void insert(string key,int value);
    int search(string key);
    void remove(string key);
    void display();
    int findSlot(const string key);
    double countOccupacy();
    void resizeTable();
};
#endif //SUPERHASHTABLE_HASHTABLE_H
