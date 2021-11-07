//
// Created by julian on 25.10.2021.
//
#include <iostream>
#include "HashNode.h"

template<typename Key, typename Value>
HashNode<Key, Value>::HashNode(Key key, Value value) {
    this->value = value;
    this->key = key;
    this->init = true;
    this->hasNext = false;
    this->next = nullptr;
}

template<typename Key, typename Value>
HashNode<Key, Value>::HashNode() {
    this->init = false;// infinite initialization ?
    this->hasNext = false;
    this->next = nullptr;
}
//look how to detect now written element
template<typename Key, typename Value>
bool HashNode<Key, Value>::operator!=(HashNode<Key, Value> *h) {
    if (h == nullptr) {
        return this->init;
    }
    if (this->key == h->key) {
        return false;
    }
    else {
        return true;
    }
}

template<typename Key, typename Value>
bool HashNode<Key, Value>::operator==(HashNode<Key, Value> *h) {
    if (h == nullptr) {
        return !this->init;
    }
    else if (this->key == h->key) {
        return true;
    }
    else {
        return false;
    }
}

template<typename Key, typename Value>
void HashNode<Key, Value>::setNext(HashNode<Key, Value> *h) {
    this->next = h;
    this->hasNext = true;
}
