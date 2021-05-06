#include "tree.h"

template<typename T>
Tree<T>::Tree()
{
    _length = 0;
    root = nullptr;
}

template<typename T>
Node<T> *Tree<T>::push(T data, long int key, Node<T> *node, int height) {
    if(node == nullptr) {
        node = new Node<T>(data, key, height);
        if(!_length)
            root = node;
        _length++;
    }
    else {
        if(key >= node->key)
            node->right = push(data, key, node->right, height+1);
        else
            node->left = push(data, key, node->left, height+1);
    }
    return node;
}

template<typename T>
Node<T> *Tree<T>::getRoot() {
    return root;
}

template<typename T>
void Tree<T>::preBalance() {
    _length = 0;
    root = nullptr;
}

template<typename T>
void Tree<T>::balance(int f, int l) {
    int center = (f+l)/2;
    //qDebug() << "!" << traverseQueue[center]->data->getNumber();
    Node<T> *node = traverseQueue[center];
    T user = node->data;
    this->push(user, user->getNumber(), root);
    if(l-f == 1) {
      //  qDebug() << "!" << traverseQueue[l]->data->getNumber();;
        Node<T> *newNode = traverseQueue[l];
        T newUser = newNode->data;
        this->push(newUser, newUser->getNumber(),root);
        return;
    }
    if(l-f == 0) {
        return;
    }
    balance(f, center-1);
    balance(center+1, l);
}

template<typename T>
void Tree<T>::traveNLR(Node<T> *node) {
    if (node != nullptr) {
        traverseQueue.enqueue(node);
        traveNLR(node->left);
        traveNLR(node->right);
   }
}

template<typename T>
void Tree<T>::traveLNR(Node<T> *node) {
    if (node != nullptr) {
        traveLNR(node->left);
        traverseQueue.enqueue(node);
        traveLNR(node->right);
   }
}

template<typename T>
void Tree<T>::traveLRN(Node<T> *node) {
    if (node != nullptr) {
        traveLRN(node->left);
        traveLRN(node->right);
        traverseQueue.enqueue(node);
   }
}

template<typename T>
void Tree<T>::searchByKey(long int key, Node<T> *node) {
    if (node != nullptr) {
        if(key == node->key) {
            traverseQueue.enqueue(node);
            searchByKey(key, node->right);
        }
        else if(key < node->key) {
            searchByKey(key, node->left);
        }
        else {
            searchByKey(key, node->right);
        }
   }
}

template<typename T>
void Tree<T>::remove(long int key) {
    while(!traverseQueue.isEmpty()) {
        Node<T> *node = traverseQueue.dequeue();
        if(node->key != key) {
            T user = node->data;
            this->push(user, user->getNumber(),root);
        }
    }
}

template<typename T>
int Tree<T>::length() {
    return _length;
}
