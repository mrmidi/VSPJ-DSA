#include <stdio.h>
//#include <tchar.h>

#include <iostream>
using namespace std;
#include "SeznamInt_2.h"

SeznamInt_2::SeznamInt_2() 
{ 
	Init();
}

SeznamInt_2::~SeznamInt_2() {
    for (int i = 0; i < this->CAPACITY; i++)
    {
        p_hodnoty[i] = NULL;
        delete p_hodnoty[i];
    }
    p_hodnoty = NULL;
    delete[] p_hodnoty;
}

// ----------------------------------

void SeznamInt_2::Init()
{
    p_hodnoty = new int* [CAPACITY];
	for (int i = 0; i < CAPACITY; i++)
		p_hodnoty[i] = NULL;
}

void SeznamInt_2::Add(int i, int value)
{
	if (i < 0 || i >= CAPACITY)
		return;
	p_hodnoty[i] = new int(value);
}

void SeznamInt_2::Remove(int i)
{
	if (i < 0 || i >= CAPACITY)
		return;
	p_hodnoty[i] = NULL;
}

// ----------------------------------

int SeznamInt_2::GetMin() const
{
	int m = *p_hodnoty[0];
	for (int i = 0; i < CAPACITY; i++)
		if ((p_hodnoty[i] != NULL) && (m > *p_hodnoty[i]))
			m = *p_hodnoty[i];
	return m;
}

// Spocita prumernou hodnotu z hodnot zapsanych v poli na pozicich.
double SeznamInt_2::CalcAvg() const
{
	int s = 0;	// suma platnych hodnot
	int n = 0;	// pocet platnych hodnot
	for (int i = 0; i < CAPACITY; i++)
		if (p_hodnoty[i] != NULL)
		{
			s += *p_hodnoty[i];
			n++;
		}
	return (double)s / n;
}

// --------------------------------------

int SeznamInt_2::operator[](int id)
{
	// Co tu je za problem a jak jej ho lze vyresit?
	if (id < 0 || id >= CAPACITY || p_hodnoty[id] == NULL)
		return DEFAULT_VALUE;
	return *p_hodnoty[id];
}

// vytiskne pole hodnot na standardni vystup
/*friend*/ ostream &operator<<(ostream &os, SeznamInt_2 o)
{
	for (int i = 0; i < o.CAPACITY; i++)
		if (o.p_hodnoty[i] == NULL)
			os << "- x -";
		else
			os << "- " << *o.p_hodnoty[i] << " -";
	return os;
}

// --------------------------------------

/*static*/ int SeznamInt_2::CalcPosition(int *p_hodnoty, int n, int *p_prvek)
{
	// todo: du
    for (int i = 0; i < n; i++)
        if (p_hodnoty[i] == *p_prvek)
            return i;
	return -1;
}