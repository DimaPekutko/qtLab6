#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
    Node(T data=T(), long int key=0, int height = 0) {
        this->left = nullptr;
        this->right = nullptr;
        this->data = data;
        this->key = key;
        this->height = height;
    }
    Node<T> *left;
    Node<T> *right;
    long key;
    int height;
    T data;
};

#endif // NODE_H
