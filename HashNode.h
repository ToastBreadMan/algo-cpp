//
// Created by julian on 25.10.2021.
//

#ifndef WITHOUT_STDLIBS_HASHNODE_H
#define WITHOUT_STDLIBS_HASHNODE_H
template<typename Key, typename Value>
class HashNode {
public:
    Key key;
    Value value;
    bool init;
    bool hasNext;
    void setNext(HashNode<Key, Value> *h);
    HashNode<Key, Value>* next;
    HashNode(Key key, Value value);
    HashNode();
    bool operator!=(HashNode<Key, Value> *h);
    bool operator==(HashNode<Key, Value> *h);
};

#endif //WITHOUT_STDLIBS_HASHNODE_H
