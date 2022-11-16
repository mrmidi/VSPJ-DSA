#include "pch.h"

class ListNode
{
private:
	int value;
	ListNode *pNext;
public:
	ListNode(int value);

	friend class MyList;
};

class MyList
{
private:
	ListNode *pHead;

private:
	void TiskReverse(ListNode *pHead);

public:
	MyList();
	~MyList();

	// otestuje, jestli je seznam prazdny
	bool IsEmpty() const;

	// vytvori seznam z hodnot ulozenych v poli p
	void MakeList(int *p, int cnt);

	// vytiskne seznam na standardni vystup
	void Tisk() const;

	// prida prvek s hodnou value na konec seznamu a vrati ukazatel zacatku seznamu
	void Add(int value);

	// prida prvek s hodnotou value na zacatek seznamu
	void AddHead(int value);


	// odstrani prvek seznamu s hodnotou value
	bool Remove(int value);

	// otestuje, jestli existuje prvek s hodnotou value
	bool Contains(int value);

	// otestuje, jestli existuje prvek s hodnotou value
	bool Contains(ListNode *pNode);

	// otestuje zacatek seznamu
	bool Test_Begin(ListNode *pNode);

	// otestuje konec seznamu
	bool Test_End(ListNode* pNode);

	// vrati hodnotu poctu prvku seznamu
	int Pocet_Prvku();

	// --

	// tisken prvky bez krajnich hodnot
	void Tisk_Prvky_BezKrajnichHodnot();

	// vytiskne prvky v obracenem poradi
	void TiskReverse();

	// vrati soucet hodnot zapsanych v prvcich seznamu
	int SumaCisel();

	// vrati soucet hodnot zapsanych v prvich seznamu nevcetne krajnich prvku
	int SumaCisel_BezKrajnichHodnot();

	// vrati pocet ruznych hodnot v seznamu - nevyuziva zadnou specialni strukturu pro zapamatovani jiz zjistenych hodnot
	int PocetRuznych();

	// presune prvek s minimalni hodnotou na zacatek seznamu
	void MoveMinHead();

	// presune prvek s maximalni hodnotou na konec seznamu
	void MoveMaxTail();

	// odstrani ze seznamu vsechny prvky s lichou hodnotou 
	void RemoveLiche();

	// za kazdy prvek se sudym cislem vlozi prvek s dvojnasobnou hodnotu
	void AddSudeMultiple();
};





