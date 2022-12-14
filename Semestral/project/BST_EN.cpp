//
// Created by Aleksandr Shabelnikov on 10.12.2022.
//

#include "BST_EN.h"
#include <iostream>
#include <fstream>
#include "Node.h"

BST_EN::BST_EN() {
    root = NULL;
}

void BST_EN::insert(size_t key, Node *pNode) {
    Node_EN *p = new Node_EN(key, *pNode);
    if (root == NULL) {
        root = p;
    } else {
        Node_EN *current = root;
        Node_EN *parent = NULL;
        while (true) {
            parent = current;
            if (key < current->key) { // go left
                current = current->pLeft;
                if (current == NULL) {  // insert to the left
                    parent->pLeft = p;
                    break;
                }
            } else {
                current = current->pRight; // go right
                if (current == NULL) {
                    parent->pRight = p; // insert to the right
                    break;
                }
            }
        }
    }
}

Node_EN* BST_EN::search(size_t key) {
    Node_EN *pNode = root;
    while (pNode != NULL) {
        if (key == pNode->key) {
            return pNode;
        }
        else if (key < pNode->key) {
            pNode = pNode->pLeft;
        }
        else {
            pNode = pNode->pRight;
        }
    }
    return NULL;
}

void BST_EN::remove(size_t key) {
    Node_EN *current = root;
    Node_EN *parent = root;
    bool isLeft = true;
    while (current->key != key) {
        parent = current;
        if (key < current->key) {
            isLeft = true;
            current = current->pLeft;
        } else {
            isLeft = false;
            current = current->pRight;
        }
        if (current == NULL) {
            return;
        }
    }
    if (current->pLeft == NULL && current->pRight == NULL) {
        if (current == root) {
            root = NULL;
        } else if (isLeft) {
            parent->pLeft = NULL;
        } else {
            parent->pRight = NULL;
        }
    } else if (current->pRight == NULL) {
        if (current == root) {
            root = current->pLeft;
        } else if (isLeft) {
            parent->pLeft = current->pLeft;
        } else {
            parent->pRight = current->pLeft;
        }
    } else if (current->pLeft == NULL) {
        if (current == root) {
            root = current->pRight;
        } else if (isLeft) {
            parent->pLeft = current->pRight;
        } else {
            parent->pRight = current->pRight;
        }
    } else {
        Node_EN *successor = getSuccessor(current);
        if (current == root) {
            root = successor;
        } else if (isLeft) {
            parent->pLeft = successor;
        } else {
            parent->pRight = successor;
        }
        successor->pLeft = current->pLeft;
    }
}

Node_EN* BST_EN::getSuccessor(Node_EN *pNode) {
    Node_EN *successor = NULL;
    Node_EN *successorParent = NULL;
    Node_EN *current = pNode->pRight;
    while (current != NULL) {
        successorParent = successor;
        successor = current;
        current = current->pLeft;
    }
    if (successor != pNode->pRight) {
        successorParent->pLeft = successor->pRight;
        successor->pRight = pNode->pRight;
    }
    return successor;
}



