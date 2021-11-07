//
// Created by julian on 31.08.2021.
//

#include "HashTables.h"
#include "HashNode.h"
#include "HashNode.cpp"
#include <typeinfo>
#include <iostream>
#include <malloc.h>

//implement hash function
template<typename Key, typename Value>
int HashTable<Key, Value>::hashFunction(Key key) {
    if (typeid(key) == typeid(int)){
        return this->ifInt((int) key);
    }
    //maybe with Key
    if (typeid(Key) == typeid(char *)){
        return this->ifString((char *)key);
    }

}

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(int size) {
    this->size = size;
    this->array = static_cast<HashNode<Key, Value> *>(malloc(this->size*sizeof(HashNode<Key, Value>)));//pointer to HashNode
    for (int i = 0;i <= size-1;i++){
        this->array[i] = HashNode<Key, Value>();
    }
}

template<typename Key, typename Value>
int HashTable<Key, Value>::insert(Key key, Value value) {
    int index = this->hashFunction(key);
    HashNode<Key, Value>* insertElem = new HashNode<Key,Value>(key, value);
    //std::cout << "Std input:" << insertElem.value << std::endl;
    //bcs nullptr does not have value hash
    if(this->array[index] != nullptr){
        HashNode<Key, Value>* curr = &this->array[index];
        while (curr->hasNext) { //look at binary operator
            curr = curr->next;
        }
        curr->setNext(insertElem);
        //std::cout << "here" << " " << curr->next->value << std::endl;
    }
    else {
       this->array[index] = *insertElem;
    } 

    return 0;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::remove(Key key) {

}

template<typename Key, typename Value>
Value HashTable<Key, Value>::get(Key key) {
    int index = this->hashFunction(key);

    HashNode<Key, Value>* curr = &this->array[index];
    std::cout << curr->value << " " << index << std::endl;
    //std::cout << curr->value << std::endl; // not init
    if (strcmp(curr->key, key) == 0){
        //std::cout << "strcmp" << std::endl;
        return curr->value;
    }
    while (curr->hasNext) {
        curr = curr->next;
    }
    return curr->value;
}


template<typename Key, typename Value>
int HashTable<Key, Value>::ifString(char * key) {
    int index = 0;
    int ges = 0;
    while(key[index]) {
        ges += key[index];
        index++;
    }
    return ges % this->size;
}

template<typename Key, typename Value>
int HashTable<Key, Value>::ifInt(int key) {
    return key % this->size;
}