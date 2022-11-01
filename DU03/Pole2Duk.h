#pragma once
#include <exception>
#include <iostream>
using namespace std;

class Pole2Duk
{
private:
	int m, n;	// m ... pocet radku; n ... pocet sloupcu
	int** p;

public:
	Pole2Duk(int m, int n);
	virtual ~Pole2Duk();
	int PocetRadku() const;
	int PocetSloupcu() const;
	void SetValue(int value, int m_pos, int n_pos);
	int GetValue(int m_pos, int n_pos) const;
	int** operator[](int index);
	int IndexOf(int value, int* m_pos, int* n_pos) const;

	void init(int m, int n);
	Pole2Duk* operator+(const Pole2Duk m1);
	Pole2Duk* operator*(const Pole2Duk m1);
	void realoc(int m_new, int n_new);
	static void tisk(const Pole2Duk& m);


};

Pole2Duk::Pole2Duk(int m, int n)
{
	// init vektoru
	init(m, n);
	/*
	this->m = m;
	this->n = n;
	p = new int*[this->m * this->n];
	for (int i = 0; i < this->m * this->n; i++)
		p[i] = new int();
	*/
}

/* virtual */ Pole2Duk::~Pole2Duk()
{
	// dealokace
	for (int i = 0; i < this->m * this->n; i++)
	{
		delete p[i];
		p[i] = NULL;
	}
	delete[]* p;   // !!!
	p = NULL;
}

void Pole2Duk::init(int m, int n)
{
	if (p != NULL)
	{
		// odstranit starou alookaci
		for (int i = 0; i < this->m * this->n; i++)
		{
			delete p[i];
			p[i] = NULL;
		}
		delete[]* p;   // !!!
		p = NULL;
	}
	// vytvorit novou alokaci
	this->m = m;
	this->n = n;
	p = new int*[this->m * this->n];
	for (int i = 0; i < this->m * this->n; i++)
		p[i] = new int();
}

int Pole2Duk::PocetRadku() const
{
	return m;
}

int Pole2Duk::PocetSloupcu() const
{
	return n;
}

void Pole2Duk::SetValue(int value, int m_pos, int n_pos)
{
	// {m_pos, n_pos} -> {index}
	if ((m_pos >= 0 && n_pos >= 0) && (m_pos < m && n_pos < n))		// !!! kontrola pristupu k prvku na pozici
		*p[m_pos * n + n_pos] = value;
}

int Pole2Duk::GetValue(int m_pos, int n_pos) const
{
	// {m_pos, n_pos} -> {index}
	if ((m_pos >= 0 && n_pos >= 0) && (m_pos < m && n_pos < n))		// !!! kontrola pristupu k prvku na pozici
		return *p[m_pos * n + n_pos];
}

int** Pole2Duk::operator[](int index)
{
	if (index >= 0 && index < m)		// !!! kontrola existujiciho radku
		return p + index * this->n;
	else
		return NULL;
}

int Pole2Duk::IndexOf(int value, int* m_pos, int* n_pos) const
{
	// vyuziti transformace {r, s} -> {index}, {index} -> {r, s}

	// verze 1
	for (int i = 0; i < m * n; i++)
		if (*p[i] == value)
		{
			*m_pos = i / n; // this->n;
			*n_pos = i % n; // this->n;
			return 1;
		}
	*m_pos = -1;
	*n_pos = -1;
	return 0;

	// ---
	/*
	// verze 2
	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
			if (GetValue(i, j) == value)
			{
				*m_pos = i;
				*n_pos = j;
				return 1;
			}
	*m_pos = -1;
	*n_pos = -1;
	return 0;
	*/
}

Pole2Duk* Pole2Duk::operator+(const Pole2Duk m1)
{
    if (m != m1.m || n != m1.n)
        throw ("Not equal size of matrices. Can't add them.");
    Pole2Duk *m2 = new Pole2Duk(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            m2->SetValue(GetValue(i, j) + m1.GetValue(i, j), i, j);
	return m2;
}

Pole2Duk* Pole2Duk::operator*(const Pole2Duk m1)
{
    if (n != m1.m)
        throw ("Wrong matrix dimensions. Number of rows of the first matrix must be equal to the number of columns of the second matrix.");
    Pole2Duk *m2 = new Pole2Duk(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value = 0;
            for (int k = 0; k < n; k++)
                value += GetValue(i, k) * m1.GetValue(k, j);
            m2->SetValue(value, i, j);
        }
    }
	return m2;
}

// I WILL NEVER DO THIS AGAIN!!!
// USE VECTOR INSTEAD
void Pole2Duk::realoc(int m_new, int n_new)
{
    if (m_new <= 0 || n_new <= 0) // self-explanatory throw
        throw ("Wrong matrix dimensions. Number of rows and columns must be greater than 0.");
    if (m_new == m && n_new == n)
        return; //nothing to do
    int **p_new = new int*[m_new * n_new];
    for (int i = 0; i < m_new * n_new; i++)
        p_new[i] = new int();
    for (int i = 0; i < m_new; i++)
        for (int j = 0; j < n_new; j++)
        {
            if (i < m && j < n)
                *p_new[i * n_new + j] = GetValue(i, j); //coping old values
            else
                *p_new[i * n_new + j] = 0; //adding zeroes if new matrix is bigger
        }
    // freeing old matrix
    for (int i = 0; i < m_new * n_new; i++)
    {
        delete p[i];
        p[i] = NULL;
    }
    delete[]* p;   // go away
    p = nullptr; // it's cleaner then NULL

    p = p_new;
    this->m = m_new;
    this->n = n_new;
    //cout << "dimensions: " << m << " " << n << endl;
}

// --

/* static */ void Pole2Duk::tisk(const Pole2Duk& m)
{
	// todo
	for (int i = 0; i < m.m; i++)
	{
		for (int j = 0; j < m.n; j++)
			cout << m.GetValue(i, j) << ';';
		cout << '\n';
	}
}


