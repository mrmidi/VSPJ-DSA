#include "pch.h"
#include <iostream>
#include "LinkedList.h"


/*
 * work results:
----------------------------------------
| List
----------------------------------------
1;2;3;4;5;
----------------------------------------
| List in reverse
----------------------------------------
5;4;3;2;1;
----------------------------------------
| Add 6 to the end of the list
----------------------------------------
1;2;3;4;5;6;
----------------------------------------
| Add 7 to the beginning of the list
----------------------------------------
7;1;2;3;4;5;6;
----------------------------------------
| Move min value to the head of the list
----------------------------------------
1;7;2;3;4;5;6;
----------------------------------------
| Move max value to the tail of the list
----------------------------------------
1;2;3;4;5;6;7;
----------------------------------------
| Is 5 in the list?
----------------------------------------
1

----------------------------------------
| Is 8 in the list?
----------------------------------------
0

----------------------------------------
| Remove 5 from the list
----------------------------------------
1;2;3;4;6;7;
----------------------------------------
| Count items in the list
----------------------------------------
6

----------------------------------------
| Sum of all items in the list
----------------------------------------
23

----------------------------------------
| Print values without start and end value
----------------------------------------
2;3;4;6;
----------------------------------------
| Add multiple of 2 to the every even number
----------------------------------------
1;2;4;3;4;8;6;12;7;
----------------------------------------
| Remove all odd numbers from the list
----------------------------------------
2;4;4;8;6;12;
----------------------------------------
| Count different numbers in the list
----------------------------------------
5

Process finished with exit code 0
 */

ListNode::ListNode(int value)
{
	this->value = value;
	this->pNext = NULL;
}

// ---------------------------------------------------

MyList::MyList()
{
	pHead = NULL;
}

MyList::~MyList()
{
	ListNode* pTmp;
	while (pHead != NULL)
	{
		pTmp = pHead;
		pHead = pHead->pNext;
		delete pTmp; pTmp = NULL;
	}
}

bool MyList::IsEmpty() const
{
	return (pHead == NULL);
}

void MyList::MakeList(int *p, int cnt)
{
	ListNode *pTmp, *pLast;

	pLast = pHead;

	for(int i = 0; i < cnt; i++)
	{
		pTmp = new ListNode(*(p + i) /* p[i] */);	
		if (pHead == NULL)
			pHead = pLast = pTmp;
		else
		{
			pLast->pNext = pTmp;
			pLast = pTmp;
		}
	}
}

void MyList::Tisk() const
{
	// todo 1
	ListNode *pTmp = pHead;
	while (pTmp != NULL)
	{
		printf("%d;", pTmp->value);
		pTmp = pTmp->pNext;
	}
}

void MyList::Add(int value)
{
	// todo 4 (samostatny ukol)
	// Klicove pripady:
	// -- prazdny seznam
	// -- neprazdny seznam - vice prvku
	// -- neprazdny seznam - jeden prvek
	ListNode *pLast = pHead, *pItem;

	pItem = new ListNode(value);
	//pItem->pNext = NULL;

	if (pHead == NULL)
		pHead = pItem;
	else
	{
		while (pLast->pNext != NULL)
			pLast = pLast->pNext;
		pLast->pNext = pItem;
	}
}

void MyList::AddHead(int value)
{
	// todo 3 (samostatny ukol)
	// Klicove pripady:
	// -- prazdny seznam
	// -- neprazdny seznam, jeden prvek / vice prvku
    if (pHead == NULL)
        pHead = new ListNode(value);
    else
    {
        ListNode *pItem = new ListNode(value);
        pItem->pNext = pHead;
        pHead = pItem;
    }
}

bool MyList::Remove(int value)
{
	// Klicove pripady: 
	// -- prazdny seznam, 
	// -- odstranuje se prvni prvek seznamu, odstranuje se posledni prvek seznamu, odstranuje se vnitrni prvek seznamu
	// -- prvek s odstranovanou hodnotou neexistuje
	ListNode* pPrev = NULL;  // inicializace kvuli prekladaci
	ListNode* pItem = pHead;
	
	// hledej prvek
	while (pItem != NULL && pItem->value != value)
	{
		pPrev = pItem;
		pItem = pItem->pNext;
	}

	if (pItem != NULL)
	{
		// Pokud jsi nasel, proved odstraneni.
		if (pHead == pItem)
		{
			// odstranuje se prvni prvek seznamu
			pHead = pItem->pNext;
			//delete pItem;
		}
		else
		{
			// odstranuje se prvek seznamu, ktery neni prvni
			pPrev->pNext = pItem->pNext;
			//delete pItem;
		}
		delete pItem;
		return true;
	}
	else
		return false;
}

bool MyList::Contains(int value)
{
	// todo 2a (samostatny ukol)
	// Klicove pripady:
	// -- prazdny seznam
	// -- neprazdny seznam, jeden prvek / vice prvku
	ListNode* pItem = pHead;
    if (pItem == NULL)
        return false;
    else
    {
        while (pItem != NULL && pItem->value != value)
            pItem = pItem->pNext;
        if (pItem != NULL)
            return true;
        else
            return false;
    }

	// hledej prvek
	while (pItem != NULL && pItem->value != value)
		pItem = pItem->pNext;

	if (pItem != NULL)
        return true;
    else
        return false;
	/*
	if (pItem != NULL)
		return true;
	else
		return false;
		*/
}

bool MyList::Contains(ListNode *pNode)
{
	// todo 2b
	ListNode* pItem = pHead;
    if (pItem == NULL)
        return false;
    else
    {
        while (pItem != NULL && pItem != pNode)
            pItem = pItem->pNext;
        if (pItem != NULL)
            return true;
        else
            return false;
    }

	// hledej prvek
	while (pItem != NULL && pItem != pNode /* ! */)
		pItem = pItem->pNext;

	return pItem != NULL;
	return false;
}

bool MyList::Test_Begin(ListNode* pNode)
{
	return false;
}

bool MyList::Test_End(ListNode* pNode)
{
	return false;
}

int MyList::Pocet_Prvku()
{
    // count number of items in the list
    int count = 0;
    ListNode* pItem = pHead;
    while (pItem != NULL)
    {
        count++;
        pItem = pItem->pNext;
    }
    return count;
	//return -1;
}

// --

void MyList::Tisk_Prvky_BezKrajnichHodnot()
{
    // print values without start and end value
    ListNode* pItem = pHead;
    if (pItem != NULL)
    {
        pItem = pItem->pNext;
        while (pItem != NULL && pItem->pNext != NULL)
        {
            printf("%d;", pItem->value);
            pItem = pItem->pNext;
        }
    }

}

void MyList::TiskReverse(ListNode *pItem)
{
	// todo 6
	if (pItem == NULL)
		return;
    // print linked list in reverse order
    TiskReverse(pItem->pNext);
    printf("%d;", pItem->value);

}

void MyList::TiskReverse()
{
	// todo 7
    // print linked list in reverse order
    TiskReverse(pHead);
}

int MyList::SumaCisel()
{
	// todo du
    //sum all numbers in the list
    int sum = 0;
    ListNode* pItem = pHead;
    while (pItem != NULL)
    {
        sum += pItem->value;
        pItem = pItem->pNext;
    }
    return sum;
}

int MyList::SumaCisel_BezKrajnichHodnot()
{
    // sum all numbers in the list without start and end value
    int sum = 0;
    ListNode* pItem = pHead;
    if (pItem != NULL)
    {
        pItem = pItem->pNext;
        while (pItem != NULL && pItem->pNext != NULL)
        {
            sum += pItem->value;
            pItem = pItem->pNext;
        }
    }
    return sum;
}

int MyList::PocetRuznych()
{
    // count number of different numbers in the list
    int count = 0;
    ListNode* pItem = pHead;
    MyList* pList = new MyList(); // list of different numbers
    while (pItem != NULL)
        {
            if (!pList->Contains(pItem->value))
            {
                pList->Add(pItem->value);
                count++;
            }
            pItem = pItem->pNext;
        }
    delete pList; // dealocate memory


	return count;
}

void MyList::RemoveLiche()
{
    // remove all odd numbers from the list
    ListNode* pItem = pHead;
    // check pHead is odd
    if (pItem != NULL && pItem->value % 2 != 0)
    {
        pHead = pItem->pNext;
        delete pItem;
        pItem = pHead;
    }
    while (pItem != NULL)
    {
        // look ahead
        if (pItem->pNext != NULL)
        {
            if (pItem->pNext->value % 2 != 0)
            {
                // remove odd number
                ListNode* pTemp = pItem->pNext;
                pItem->pNext = pItem->pNext->pNext;
                delete pTemp; // dealocate memory
            }
            else
                pItem = pItem->pNext;
        }
        else
            pItem = pItem->pNext;
    }
}

void MyList::AddSudeMultiple()
{
    // za kazdy prvek se sudym cislem vlozi prvek s dvojnasobnou hodnotu
    // after every even number add a new item with double value
    ListNode* pTmp;
    ListNode* pItem = pHead;
    //check if pHead is even
    if (pItem != NULL && pItem->value % 2 == 0)
    {
        pTmp = new ListNode(pItem->value * 2);
        pTmp->pNext = pItem->pNext;
        pItem->pNext = pTmp;
        pItem = pItem->pNext->pNext;
    }
    while (pItem != NULL)
    {
        if (pItem->value % 2 == 0) {
            // create new item
            pTmp = new ListNode(pItem->value * 2);
            // insert new item after current item
            pTmp->pNext = pItem->pNext;
            pItem->pNext = pTmp;
            // move to next item
            pItem = pItem->pNext;
        }
        pItem = pItem->pNext;
    }
}


void MyList::MoveMinHead()
{
	// todo du
    //find min
    //remove min
    //add min to head
    int min = INT32_MAX;
    ListNode* pMin = NULL;
    for (ListNode* p = pHead; p != NULL; p = p->pNext)
    {
        if (p->value < min)
        {
            min = p->value;
            pMin = p;
        }
    }
    // simple way
//    if (pMin != NULL)
//    {
//        Remove(pMin->value);
//        AddHead(min);
//    }
   if (pMin != NULL && pMin != pHead)
   {
       ListNode* p = pHead;
       while (p->pNext != pMin)
           p = p->pNext;
       p->pNext = pMin->pNext;
       pMin->pNext = pHead;
       pHead = pMin;
   }
}



void MyList::MoveMaxTail()
{
	// todo du
    // find max
    // remove max
    // add max to tail
    int max = INT32_MIN;
    ListNode* pMax = NULL;
    for (ListNode* p = pHead; p != NULL; p = p->pNext)
    {
        if (p->value > max)
        {
            max = p->value;
            pMax = p;
        }
    }
    // simple way
//    if (pMax != NULL)
//    {
//        Remove(pMax->value);
//        Add(max);
//    }
    if (pMax != NULL && pMax != pHead)
    {
        ListNode* p = pHead;
        while (p->pNext != pMax)
            p = p->pNext;
        p->pNext = pMax->pNext;
        pMax->pNext = NULL;
        Add(max);
    }
}
