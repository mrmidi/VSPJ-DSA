//
// Created by Aleksandr Shabelnikov on 10.12.2022.
//

#include "Node.h"
#include "BST.h"
#include <iostream>
#include <fstream>

BST::BST() {
    root = NULL;
}

void BST::print() {
    print(root);
}

void BST::print(Node *pNode) {
    if (pNode != NULL) {
        print(pNode->pLeft);
        std::cout << pNode->key << " " << pNode->word << " " << pNode->definition << std::endl;
        print(pNode->pRight);
    }
}


// search

Node* BST::search(size_t key) {
    Node *pNode = root;
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

void BST::insert(size_t key, std::string word, std::string definition) {
    Node *p = new Node(key, word, definition);
    if (root == NULL) {
        root = p;
    } else {
        Node *current = root;
        Node *parent = NULL;
        while (true) {
            parent = current;
            if (key < current->key) { // go left
                current = current->pLeft;
                if (current == NULL) {  // insert to the left
                    parent->pLeft = p;
                    break; // exit while loop
                }
            } else {
                current = current->pRight; // go right
                if (current == NULL) {
                    parent->pRight = p; // insert to the right
                    break; // exit while loop
                }
            }
        }
    }
}

Node * BST::insertWithReturn(size_t key, std::string word, std::string definition) {
    Node *pNode = new Node(key, word, definition);
    if (root == NULL) {
        root = pNode;
    } else {
        Node *pCurrent = root;
        Node *pParent = NULL;
        while (true) {
            pParent = pCurrent;
            if (key < pCurrent->key) {
                pCurrent = pCurrent->pLeft;
                if (pCurrent == NULL) {
                    pParent->pLeft = pNode;
                    break;
                }
            } else {
                pCurrent = pCurrent->pRight;
                if (pCurrent == NULL) {
                    pParent->pRight = pNode;
                    break;
                }
            }
        }
    }
    //std::cout << "CS Node in BST: " << pNode << std::endl;
    return pNode;
}

void BST::remove(size_t key) {
    Node *pCurrent = root;
    Node *pParent = root;
    bool isLeftChild = true;

    // search for node
    while (pCurrent->key != key) {
        pParent = pCurrent;
        if (key < pCurrent->key) {
            isLeftChild = true;
            pCurrent = pCurrent->pLeft;
        } else {
            isLeftChild = false;
            pCurrent = pCurrent->pRight;
        }
        if (pCurrent == NULL) {
            return; // didn't find it
        }
    }

    // if no children, simply delete it
    if (pCurrent->pLeft == NULL && pCurrent->pRight == NULL) {
        if (pCurrent == root) {
            root = NULL;
        } else if (isLeftChild) {
            pParent->pLeft = NULL;
        } else {
            pParent->pRight = NULL;
        }
    }

    // if no right child, replace with left subtree
    else if (pCurrent->pRight == NULL) {
        if (pCurrent == root) {
            root = pCurrent->pLeft;
        } else if (isLeftChild) {
            pParent->pLeft = pCurrent->pLeft;
        } else {
            pParent->pRight = pCurrent->pLeft;
        }
    }

    // if no left child, replace with right subtree
    else if (pCurrent->pLeft == NULL) {
        if (pCurrent == root) {
            root = pCurrent->pRight;
        } else if (isLeftChild) {
            pParent->pLeft = pCurrent->pRight;
        } else {
            pParent->pRight = pCurrent->pRight;
        }
    }

    // two children, so replace with inorder successor
    else {
        Node *pSuccessor = getSuccessor(pCurrent);

        // connect parent of current to successor instead
        if (pCurrent == root) {
            root = pSuccessor;
        } else if (isLeftChild) {
            pParent->pLeft = pSuccessor;
        } else {
            pParent->pRight = pSuccessor;
        }

        // connect successor to current's left child
        pSuccessor->pLeft = pCurrent->pLeft;
    }


}

Node * BST::getSuccessor(Node *pDelNode) {
    Node *pSuccessorParent = pDelNode;
    Node *pSuccessor = pDelNode;
    Node *pCurrent = pDelNode->pRight; // go to right child
    while (pCurrent != NULL) { // until no more
        pSuccessorParent = pSuccessor;
        pSuccessor = pCurrent;
        pCurrent = pCurrent->pLeft; // go to left child
    }

    // if successor not
    if (pSuccessor != pDelNode->pRight) {
        pSuccessorParent->pLeft = pSuccessor->pRight;
        pSuccessor->pRight = pDelNode->pRight;
    }
    return pSuccessor;
}

void BST::clear() {
    clear(root);
}

void BST::clear(Node *pNode) {
    if (pNode != NULL) {
        clear(pNode->pLeft);
        clear(pNode->pRight);
        delete pNode;
    }
}

void BST::drawtree() {
    drawtree(root, 3);
}

void BST::drawtree(Node *pNode, int level) {
    if (pNode != NULL) {
        drawtree(pNode->pRight, level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << "---";
        }
        std::cout << "x" << std::endl;
        drawtree(pNode->pLeft, level + 1);
    }
}

void BST::makeFile() {
    std::ofstream file;
    // get the current folder
    std::string folder = __FILE__;
    folder = folder.substr(0, folder.find_last_of("\\/"));
    // create the file
    file.open(folder + "/cs-en.txt");

    makeFile(root, file);
    file.close();
}

void BST::makeFile(Node *pNode, std::ofstream &file) {
    if (pNode != NULL) {
        makeFile(pNode->pLeft, file);
        file << pNode->word << " -> " << pNode->definition << std::endl;
        makeFile(pNode->pRight, file);
    }
}

void BST::makeFileEn() {
    std::ofstream file;
    // get the current folder
    std::string folder = __FILE__;
    folder = folder.substr(0, folder.find_last_of("\\/"));
    // create the file
    file.open(folder + "/en-cs.txt");

    makeFileEn(root, file);
    file.close();
}

void BST::makeFileEn(Node *pNode, std::ofstream &file) {
    if (pNode != NULL) {
        makeFileEn(pNode->pLeft, file);
        file << pNode->definition << " -> " << pNode->word << std::endl;
        makeFileEn(pNode->pRight, file);
    }
}