//
// Created by julian on 31.08.2021.
//

#ifndef WITHOUT_STDLIBS_HASHTABLES_H
#define WITHOUT_STDLIBS_HASHTABLES_H
#include "NewArray.h"
#include "HashNode.h"

//why does this work
template<typename Key, typename Value>
class HashTable {
private:
    int size;
    HashNode<Key, Value>* array;
    int hashFunction(Key key);
    int ifString(char * key);
    int ifInt(int key);
public:
    explicit HashTable(int size);
    int insert(Key key, Value value);
    void remove(Key key);
    Value get(Key key);
};


#endif //WITHOUT_STDLIBS_HASHTABLES_H
