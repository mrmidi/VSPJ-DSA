// BinarySearchTree.cpp : Defines the entry point for the console application.
//


#include <iostream>
using namespace std;
#include "Node.h"
#include "BST.h"

void printTreeInTreeForm(Node *node) // pre-order traversal method
{
    if (node == NULL)
    {
        cout << 'x';
        return;
    }


    // Visit the root node.
    std::cout << node->key;

    // Traverse the left subtree.
    std::cout << " (";
    printTreeInTreeForm(node->pLeft);
    std::cout << " , ";

    // Traverse the right subtree.
    printTreeInTreeForm(node->pRight);
    std::cout << ") ";
}

int _tmain(int argc, _TCHAR* argv[])
{
	BST t;

	t.insert(6);
	t.insert(4);
	t.insert(8);
	t.insert(5);
	t.insert(7);
	t.insert(3);
	t.insert(9);

	printTreeInTreeForm(t.GetRoot());
	cout << endl << endl;

	t.Del(t.Search(3));
	t.Del(t.Search(4));
	t.Del(t.Search(8));
	t.Del(t.Search(6));
	printTreeInTreeForm(t.GetRoot());
	cout << endl << endl;

	return 0;
}

