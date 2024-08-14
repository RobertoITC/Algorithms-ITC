#include <iostream>
#include "HashTable.h"
#include <string>
using namespace std;



int main() {
    HashTable ht(10);

    ht.insert("apple", 5);
    ht.insert("banana", 8);
    ht.insert("cherry", 12);
    ht.insert("date", 15);
    ht.insert("hola", 30);
    ht.insert("bonjour", 10);
    ht.insert("hello", 60);
   /* ht.insert("hola", 14);
    ht.insert("nihao", 43);
    ht.insert("gutten tag", 22);
    ht.insert("Ola", 11);*/


    cout << "Hash table contents:" << endl;
    ht.display();

    auto value = ht.search("banana");
    if (value!=NULL) {
        cout << "Value for 'banana': " << value << endl;
    }

    ht.remove("apple");

    cout<< "After removing 'apple':" <<endl;
    ht.display();

    return 0;
}