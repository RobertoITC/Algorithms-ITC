//
// Created by Scout on 12/08/24.
//

#include "HashTable.h"

HashTable::HashTable(int size) {
    table.resize(size);
}

int HashTable::hash(const string key) {
   /* int sum = 0;
    for(char c : key){
        sum+=c;
    }
    return sum % table.size();*/
    unsigned long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % table.size();
}


int HashTable::findSlot(const string key) {
    int index = hash(key);
    int i = 0;

    while (i < table.size()) {
        int probeIndex = (index + i * i) % table.size();

        if (!table[probeIndex].isOccupied || table[probeIndex].key == key) {
            return probeIndex;
        }

        if (table[probeIndex].isDeleted) {
            return probeIndex;
        }

        i++;
    }

    return -1;
}
double HashTable::countOccupacy() {
    int sumOccupancy = 0;
    for (auto & i : table) {
        if (i.isOccupied && !i.isDeleted) {
            sumOccupancy += 1;
        }
    }
    return sumOccupancy;
}

void HashTable::resizeTable() {
    int newSize = table.size() * 2;
    vector<Entry> newTable(newSize);

    for (auto & i : table) {
        if (i.isOccupied && !i.isDeleted) {
            int newIndex = hash(i.key) % newSize;
            int j = 0;
            while (newTable[(newIndex + j) % newSize].isOccupied) {
                j++;
            }
            newTable[(newIndex + j) % newSize] = i;
        }
    }

    table = move(newTable);
}




void HashTable::insert(string key, int value) {

    int index = findSlot(key);
   // int index= hash(key);
    if (index == -1) {
        cout << "Hash table is full" << endl;
        return;
    }
    table[index].key = key;
    table[index].value = value;
    table[index].isOccupied = true;
    table[index].isDeleted = false;

    double loadFactor = countOccupacy() / table.size();
    if (loadFactor >= 0.8) {
        resizeTable();
    }
}

    int HashTable::search(const string key){
    int index = hash(key);
    int i = 0;
    while (i < table.size()) {
        int probeIndex = (index + i) % table.size();
        if (!table[probeIndex].isOccupied) {
            return NULL;
        }
        if (table[probeIndex].key == key && !table[probeIndex].isDeleted) {
            return table[probeIndex].value;
        }
        i++;
    }


    return NULL;
}

void HashTable::remove(string key) {
    int index = hash(key);
    int i = 0;
    while (i < table.size()) {
        int probeIndex = (index + i) % table.size();
        if (!table[probeIndex].isOccupied) {
            return;
        }
        if (table[probeIndex].key == key && !table[probeIndex].isDeleted) {
            table[probeIndex].isDeleted = true;
            return;
        }
        i++;
    }
}

void HashTable::display() {
    for (int i = 0; i < table.size(); ++i) {
        if (table[i].isOccupied && !table[i].isDeleted) {
            cout << i << ": (" << table[i].key << ", " << table[i].value << ")" << endl;
        } else {
            cout << i << ": empty" << endl;
        }
    }
}
