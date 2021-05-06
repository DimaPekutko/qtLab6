#include "customtree.h"

template<typename T>
CustomTree<T>::CustomTree()
{

}

template<typename T>
QList<int> CustomTree<T>::countNodes() {
    nodesCount.clear();
    for(int i = 0; i < this->_length; i++) {
        nodesCount.append(0);
    }
    traveCount(this->root);
    return nodesCount;
}

template<typename T>
void CustomTree<T>::traveCount(Node<T> *node) {
    if(node != nullptr) {
        nodesCount[node->height]++;
        traveCount(node->left);
        traveCount(node->right);
    }
}

