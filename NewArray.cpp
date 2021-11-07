//
// Created by julian on 29.08.2021.
//

#include "NewArray.h"
#include <malloc.h>

template <typename T>
NewArray<T>::NewArray(int size) {
    this->maxsize = size;
    this->array = static_cast<T *>(malloc(size * sizeof(T)));
    this->length = 0;
};

template <typename T>
T NewArray<T>::insert(T element) {
    if (this->length >= this->maxsize) {
        this->array = static_cast<T *>(realloc(this->array, this->maxsize * 2 * sizeof(T)));
    }
    this->array[this->length] = element;
    this->maxsize = this->maxsize * 2;
    this->length++;
    return element;
}

template<typename T>
void NewArray<T>::deleteArray() {
    free(this->array);
}

template<typename T>
void NewArray<T>::insertAtLocation(int index, T value) {
    this->array[index] = value;
}

template<typename T>
void NewArray<T>::deleteFromIndex(int index) {
    if(this->length == this->maxsize/2) {
        this->array = static_cast<T *>(realloc(this->array, (this->maxsize/2) * sizeof(T)));
    }
    if (index >= this->length) {
        return;
    }
    T val = this->array[index];
    this->shift(index);
}

template<typename T>
T NewArray<T>::get(int index) {
    return this->array[index];
}

template<typename T>
NewArray<T>::~NewArray() {
    delete this->array;
}

//problem lies in shift function
template<typename T>
void NewArray<T>::shift(int index) {
    int ptr = index;
    while(ptr <= length) {
        this->array[ptr - 1] = this->array[ptr];
        ptr++;
    }
}