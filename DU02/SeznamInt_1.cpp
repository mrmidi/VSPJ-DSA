#include <stdio.h>
//#include <tchar.h> - NO SUPPORT ON MACOS AND LINUX

#include <iostream>
using namespace std;
#include "SeznamInt_1.h"

SeznamInt_1::SeznamInt_1(int capacity)
{
	this->capacity = capacity;
	n = 0;
	p_hodnoty = new int[this->capacity];
}

SeznamInt_1::SeznamInt_1(const SeznamInt_1 &o)
{
	this->capacity = o.capacity;
	this->n = o.n;

	//this->p_hodnoty = o.p_hodnoty; 
	
	this->p_hodnoty = new int[this->capacity];
	for (int i = 0; i < this->n; i++)
		this->p_hodnoty[i] = o.p_hodnoty[i];				
		
}

SeznamInt_1::~SeznamInt_1()
{
	delete[] p_hodnoty;
}

int SeznamInt_1::Count() const
{
	return n;
}

int SeznamInt_1::Capacity() const
{
	return capacity;
}

// ----------------------------------

int* SeznamInt_1::Copy() const
{
	// todo du
    int *result = new int[this->capacity];
    for (int i = 0; i < this->capacity; i++)
        result[i] = this->p_hodnoty[i];
	return result;
}

void SeznamInt_1::realokace()
{
    int *p_hodnoty2 = new int[this->capacity + 1];
    for (int i = 0; i < this->capacity; i++)
        p_hodnoty2[i] = this->p_hodnoty[i];
    delete[] this->p_hodnoty;
    this->p_hodnoty = p_hodnoty2;
    delete[] p_hodnoty2;
	// todo du - realokace pole
	;
}

bool SeznamInt_1::Add(int value)
{
	// todou du - vyuziti realokace


if (this->n == this->capacity)
        this->realokace();

    this->p_hodnoty[this->n] = value;
    this->n++;
//	if (n == capacity)
//		return false;
//	//if (n < capacity)
//		p_hodnoty[n++] = value;
	return true;
}

bool SeznamInt_1::Remove(int id)
{
	if (id < 0 || id >= n)
		return false;
	for (int i = id; i < n - 1; i++)
		p_hodnoty[i] = p_hodnoty[i + 1];
	n--;
	return true;
}

bool SeznamInt_1::Contains(int value) const
{
	return IndexOf(value) != -1;
	/*
	for (int i = 0; i < n; i++)
		if (p_hodnoty[i] == value)
			return true;
	return false;
	*/

}

int SeznamInt_1::IndexOf(int value) const
{
	return IndexOf(value, 0);
	/*
	for (int i = 0; i < n; i++)
		if (p_hodnoty[i] == value)
			return i;
	return -1;
	*/
}

int SeznamInt_1::IndexOf(int value, int pos/* = 0*/) const
{
	for (int i = pos; i < n; i++)
		if (p_hodnoty[i] == value)
			return i;
	return -1;
}

int SeznamInt_1::LastIndexOf(int value) const
{
	for (int i = n-1; i >= 0; i--)
		if (p_hodnoty[i] == value)
			return i;
	return -1;
}

// ----------------------------------

int SeznamInt_1::GetMin() const
{
	if (n == 0)
		return -1;
	/*
	int m = p_hodnoty[0];
	for (int i = 1; i < n; i++)
		if (m > p_hodnoty[i])
			m = p_hodnoty[i];
			*/
	int m;
	for (int i = 0; i < n; i++)
		if (i == 0 || m > p_hodnoty[i])
			m = p_hodnoty[i];
	return m;
}

int SeznamInt_1::GetMax() const
{
	if (n == 0)
		return -1;
	int m = p_hodnoty[0];
	for (int i = 1; i < n; i++)
		if (m < p_hodnoty[i])
			m = p_hodnoty[i];
	return m;
}

double SeznamInt_1::CalcAvg() const
{
	int s = 0;
	for (int i = 0; i < n; i++)
		s += p_hodnoty[i];
	return (double)s / n;
}

void SeznamInt_1::GetMinMax(int *p_min, int *p_max) const
{
	/*
	if (p_min == NULL || p_max == NULL)
		return;
		*/
	if (p_min != NULL) 
		*p_min = GetMin();
	if (p_max != NULL)
		*p_max = GetMax();
}

int SeznamInt_1::GetIdMax() const
{
	return IndexOf(GetMax());
}

int* SeznamInt_1::GetIdsMax(int v, int *n_max /* int &n_max */)
{
	int m = GetMax();
	*n_max = 0;
	for (int i = 0; i < n; i++)
		if (m == p_hodnoty[i])
			*n_max++;
	int *p_max_hodnoty = new int[*n_max];
	int id_m = 0;

	// todo
	for (int i = 0; i < n; i++)
		if (m == p_hodnoty[i])
			p_max_hodnoty[id_m++] = i;

	return p_max_hodnoty;	
}

bool SeznamInt_1::JeSerazenoVzestupne() const
{
	/*
	bool isOrder = true;
	for (int i = 0; i < n - 1; i++)
		if (p_hodnoty[i] > p_hodnoty[i + 1])
			isOrder = false;
	return isOrder;
	*/

	// jine reseni (rychlejsi)
	for (int i = 0; i < n - 1; i++)
		if (p_hodnoty[i] > p_hodnoty[i + 1])
			return false;
	return true;
}

// ----------------------------------

/*friend*/ bool operator==(SeznamInt_1 &o1, SeznamInt_1 &o2)
{
	if (o1.capacity != o2.capacity)
		return false;
	if (o1.n != o2.n)
		return false;
	for (int i = 0; i < o1.n; i++)
		if (o1.p_hodnoty[i] != o2.p_hodnoty[i])
			return false;
	return true;
}

// operator
/*friend*/ istream &operator >> (istream &is, SeznamInt_1 &o)
{
	int i = 0;	
	int v;

	// todo

	return is;
}

/*friend*/ ostream &operator<<(ostream &os, SeznamInt_1 o)
{
	os << '[';
	for (int i = 0; i < o.n; i++)
	{
		printf("%d", o.p_hodnoty[i]);
		if (i < o.n - 1)
			printf(";");
	}
	os << ']';
	os << '\n';
	return os;
}
