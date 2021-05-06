#ifndef TREE_H
#define TREE_H

#include <QDebug>

#include <QQueue>

#include "node.h"

template<typename T>
class Tree
{
public:
    Tree();
    Node<T> *push(T data, long int key, Node<T> *node, int height = 0);
    Node<T> *getRoot();
    void preBalance();
    void balance(int f=0, int l=0);
    void traveNLR(Node<T> *node);
    void traveLNR(Node<T> *node);
    void traveLRN(Node<T> *node);
    void searchByKey(long int key, Node<T> *node);
    void remove(long int key);
    int length();
    QQueue<Node<T>*> traverseQueue;
protected:
    int _length;
    Node<T> *root;
};

#endif // TREE_H
