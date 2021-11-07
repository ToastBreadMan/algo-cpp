//
// Created by julian on 01.09.2021.
//

#ifndef WITHOUT_STDLIBS_QUEUE_H
#define WITHOUT_STDLIBS_QUEUE_H
#include "NewArray.h"

template<typename T>
class Queue {
public:
    NewArray<T>* queue;
    explicit Queue(int size);
    void push(T);
    T pop();
    T get();
};


#endif //WITHOUT_STDLIBS_QUEUE_H
