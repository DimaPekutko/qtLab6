#ifndef CUSTOMTREE_H
#define CUSTOMTREE_H

#include "tree.h"
#include "tree.cpp"

template<typename T>
class CustomTree : public Tree<T>
{
public:
    CustomTree();
    QList<int> countNodes();
    void traveCount(Node<T> *node);
private:
    QList<int> nodesCount;
};

#endif // CUSTOMTREE_H
