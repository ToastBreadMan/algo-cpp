//
// Created by julian on 29.08.2021.
//

#ifndef WITHOUT_STDLIBS_NEWARRAY_H
#define WITHOUT_STDLIBS_NEWARRAY_H

template <typename T>
class NewArray {
private:
    T* array;
    int maxsize{};
    void shift(int index);
public:
    int length{};
    T insert(T element);
    explicit NewArray(int size);
    NewArray();
    ~NewArray();
    void deleteFromIndex(int index);
    T get(int index);
    void insertAtLocation(int index, T value);
    void deleteArray();
};


#endif //WITHOUT_STDLIBS_NEWARRAY_H
