//
// Created by Aleksandr Shabelnikov on 10.12.2022.
//

#ifndef SEM_BST_EN_H
#define SEM_BST_EN_H
#include "Node_EN.h"
#include "Node.h"


class BST_EN {
private:
    Node_EN *root;

public:
    BST_EN(); // constructor
    void insert(size_t key, Node pNode);
    void remove(size_t key);
    Node_EN* search(size_t key);
    void print();
    void print(Node_EN *pNode);
    void clear();
    void clear(Node_EN *pNode);
    void getRoot();
    void insert(size_t key, Node *pNode);
    Node_EN *getSuccessor(Node_EN *pNode);

    void makeFile();

    void makeFile(Node_EN *pNode, std::ofstream &file);
};


#endif //SEM_BST_EN_H
