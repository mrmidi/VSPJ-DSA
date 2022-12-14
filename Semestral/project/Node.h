//
// Created by Aleksandr Shabelnikov on 10.12.2022.
//


#ifndef SEM_NODE_H
#define SEM_NODE_H

#include <iostream>

class Node {
public:
    size_t key;
    std::string word;
    std::string definition;
    Node *pLeft;
    Node *pRight;
    Node(size_t key, std::string word, std::string definition)
    {
        this->key = key;
        this->word = word;
        this->definition = definition;
        pLeft = NULL;
        pRight = NULL;
    }
};
#endif //SEM_NODE_H
