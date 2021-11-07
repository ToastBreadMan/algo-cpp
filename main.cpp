#include <iostream>
#include "NewArray.h"
#include "NewArray.cpp"
#include "HashTables.h"
#include "HashTables.cpp"
#include "Queue.h"
#include "Queue.cpp"

void printStr(char * string) {
    int index = 0;
    while (string[index]) {
        putchar(string[index]);
        index++;
    }
}
//when using template you have to include .cpp

int main() {
    auto *hashTable = new HashTable<char*, int>(5);
    hashTable->insert("test", 1);
    //std::cout << hashTable->get("test") << std::endl;
    hashTable->insert("tset", 2);
    hashTable->insert("stet", 3);
    return 0;
}