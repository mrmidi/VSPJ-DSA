//
// Created by Aleksandr Shabelnikov on 10.12.2022.
//

#ifndef SEM_BST_H
#define SEM_BST_H

#include "Node.h"


class BST {
private:
    Node *root;
public:
    BST(); // constructor
    void insert(size_t key, std::string word, std::string definition);
    Node * insertWithReturn(size_t key, std::string word, std::string definition);
    void remove(size_t key);
    Node* search(size_t key);
    void print();
    void print(Node *pNode);
    void clear();
    void clear(Node *pNode);
    void getRoot();
    Node *getSuccessor(Node *pDelNode);
    void makeFile();
    void makeFile(Node *pNode, std::ofstream &file);
    void makeFileEn();
    void makeFileEn(Node *pNode, std::ofstream &file);


    void drawtree();
    void drawtree(Node *pNode, int level);
};

#endif //SEM_BST_H
