#include <iostream>
#include "BST.h"
#include "Node.h"



BST::BST()
{
	pRoot = NULL;
}

BST::~BST()
{
	// todo, sam. dcv.
}

Node *BST::GetRoot()
{
	return pRoot;
}

void BST::insert(int key)
{
	// Vytvor uzel stromu s hodnotou key. A zarad uzel do stromu tak, aby se vytvarel binarni "vyhledavaci" strom.
	//
	if (pRoot == NULL)
		pRoot = new Node(key);
	else
	{
		Node *pTmp = pRoot, *pTmpPrev = NULL;
		if (key == pTmp->key)
			return;
		else
		{
			// hledani listu stromu (podle pravidel BVS)
			do
			{
				pTmpPrev = pTmp;
				if (key < pTmp->key)
					pTmp = pTmp->pLeft;
				else
					pTmp = pTmp->pRight;
			} while (pTmp != NULL);

			// vlozeni noveho uzlu jako potomka listu stromu
			if (key < pTmpPrev->key)
				pTmpPrev->pLeft = new Node(key);
			else
				pTmpPrev->pRight = new Node(key);

		}
	}
}

Node* BST::Search(int key)
{
	return ::Search(pRoot, key);
}


Node* BST::Parent(Node *pNode)
{
	// Hledej na ceste od korene stromu ke hledanemu uzlu. 
	if (pNode == pRoot)
		return NULL;

	Node *pTmp = pRoot, *pTmpPrev = NULL;
	// todo: nalezeni rodice uzlu pNode
	do
	{
		pTmpPrev = pTmp;
		if (pTmp->key > pNode->key)
			pTmp = pTmp->pLeft;
		else
			pTmp = pTmp->pRight;
	} while ((pTmp != pNode) && (pTmp != NULL));

	if (pTmp == NULL)
		return NULL;
	return pTmpPrev;
}

Node* BST::Prec(Node *pNode)
{
	return ::Max(pNode->pLeft);
}

Node* BST::Succ(Node *pNode)
{
	return ::Min(pNode->pRight);
}

bool BST::Contain(int key)
{
	return !(::Search(pRoot, key) == NULL);
}

// -----------------------------------

#define MAX_INT(x, y) ((x) > (y) ? x : y);

/* protected */ int BST::Height(Node *pNode)
{
	if (pNode == NULL)
		return 0;
	return 1 + MAX_INT(Height(pNode->pLeft), Height(pNode->pRight));
}

int BST::Height()
{
	if (pRoot == NULL)
		return -1;
	return Height(pRoot);
}

void BST::Del(Node *pNode)
{
    if (pNode == NULL)
        return;
    // node to be deleted is a leaf
    if (pNode->pLeft == NULL && pNode->pRight == NULL)
    {
        // odstranuje se uzel, ktery nema potomky, tj list
        // uprav odkaz u rodiËe na NULL a zruö uzel

        // todo: odstraneni listu stromu
        Node *pParent = Parent(pNode);
        if (pParent == NULL)
        {
            // odstranuje se koren stromu (pNode == pRoot)

            // remove root

            if (pNode == pRoot)
            {
                delete pRoot;
                pRoot = NULL;
            } else
            {
                // remove leaf
                if (pParent->pLeft == pNode)
                    pParent->pLeft = NULL;
                else
                    pParent->pRight = NULL;
                delete pNode;
            }
        }
        //
    }
    // node to be deleted has only one child:
    if (pNode->pLeft == NULL || pNode->pRight == NULL)
    {
        // odstranuje se uzel, ktery ma pouze jednoho potomka
        Node *pParent = Parent(pNode), *x;
        if (pNode->pLeft)
            x = pNode->pLeft;
        else
            x = pNode->pRight;

        if (pParent == NULL)
            pRoot = x;               // rodiË je ko¯en stromu
            // potomka ruöenÈho uzlu navaû na rodiËe ruöenÈho uzlu
        else
        if (pParent->pLeft == pNode)  // (pParent->key > pNode->key)
            pParent->pLeft = x;
        else
            pParent->pRight = x;

        delete pNode;
        return;
    }
    // node to be deleted has two children


    Node *y = Prec(pNode); // y is successor of pNode

    // najde se rodic predchudce
    Node *z = Parent(y); // z is parent of y
    // potomkem rodice (z) se stane levy potomek uzlu y
    z->pLeft = y->pRight;
    // uzel y se zkopiruje do uzlu p
    pNode->key = y->key;
    // totez pro data
    // zrusi se uzel y
    delete y;

}