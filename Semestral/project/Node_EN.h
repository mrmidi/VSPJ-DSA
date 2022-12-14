//
// Created by Aleksandr Shabelnikov on 10.12.2022.
//

#ifndef SEM_NODE_EN_H
#define SEM_NODE_EN_H
#include <iostream>
#include "Node.h"

class Node_EN {
public:
    size_t key;
    Node_EN *pLeft;
    Node_EN *pRight;
    Node *pNode;
    Node_EN(size_t key, Node &pNode)
    {
        this->key = key;
        this->pNode = &pNode; // reference to the node in another language
        pLeft = NULL;
        pRight = NULL;
    }
};


#endif //SEM_NODE_EN_H
