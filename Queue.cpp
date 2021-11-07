//
// Created by julian on 01.09.2021.
//

#include "Queue.h"
#include "NewArray.h"

template<typename T>
void Queue<T>::push(T elem) {
    this->queue->insert(elem);
}
//TODO:Fix memory leak

template<typename T>
T Queue<T>::pop() {
    T elem = this->queue->get(0);
    this->queue->deleteFromIndex(0);
    return elem;
}


template<typename T>
T Queue<T>::get() {
    return this->queue->get(0);
}

template<typename T>
Queue<T>::Queue(int size) {
    this->queue = new NewArray<T>(size);
}
