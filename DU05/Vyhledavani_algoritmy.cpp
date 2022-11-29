// Vyhledavani_algoritmy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "Vyhledavani_algoritmy.h"


/*
 * Find_noorder : sekvencni vyhledani v neserazene posloupnosti
 * Params :
 *	p - pole hodnot
 *	N - pocet hodnot v poli, velikost pole
 *	value - hledana hodnota
*/

int Find_order(int p[], int l, int r, int value);

void Find_noorder_1(int p[], int N, int value)
{
	int pos = -1;
	for (int i = 0; i < N; i++)
		if (p[i] == value)
		{
			pos = i;
			break;
		}

	printf("Find-noorder %d\n", pos);
}

void Find_noorder_2(int p[], int N, int value)
{
	// neni to uplne dobry
	int pos = -1;
	for (int i = 0; i < N; i++)
		if ((p[i] == value) && (pos == -1))
		{
			pos = i;
		}

	printf("Find-noorder %d\n", pos);
}

void Find_noorder_3(int p[], int N, int value)
{
	int pos = -1;
	for (int i = 0; i < N & pos == -1; i++)
		if (p[i] == value)
		{
			pos = i;
			//i = N;
		}

	printf("Find-noorder %d\n", pos);
}

void Find_noorder_4_1(int p[], int N, int value)
{
	int pos = -1;
	int i = 0;
	// hledam, dokud nejsem na konci, anebo jsem nasel
	while (i < N && p[i] != value)
		i++;
	if (i < N)	// nasel jsem
		pos = i;

	printf("Find-noorder %d\n", pos);
}

void Find_noorder_4_2(int p[], int N, int value)
{
	int pos = -1;
	int i = 0;
	// hledam, dokud nejsem na konci, anebo jsem nasel
	while ((i < N) && (pos == -1))
	{
		if (p[i] == value)
		{
			pos = i;
			// break;
		}
		i++;
	}

	printf("Find-noorder %d\n", pos);
}

void Find_noorder_4_3(int p[], int N, int value)
{
	// lepsi je while
	int pos = -1;
	int i = 0;
	do
	{
		if (p[i] == value)
		{
			pos = i;
			//break;
		}
	} while ((i < N) && (pos == -1));

}

int Find_noorder(int p[], int N, int value)
{
	int pos = -1;
	int i = 0;
	// hledam, dokud nejsem na konci, anebo jsem nasel
	while ((i < N) && (pos == -1))
	{
		if (p[i] == value)
		{
			pos = i;
			// break;
		}
		i++;
	}

	return pos; //printf("Find-noorder %d\n", pos);
}




/*
 * Find_order : vyhledavani pulenim intervalu (binarni vyhledavani) v serazene posloupnosti
 * Params :
 *	p - pole hodnot
 *	l - dolni mez intervalu hledani
 *	r - horni mez intervalu hledani
 *	value - hledana hodnota
*/
void Find_order_tisk(int p[], int l, int r, int value)
{
	if (l > r)
		return;

	int pivot = (l + r) / 2;

	if (p[pivot] == value)
		printf("Find-order %d\n", pivot);
	else
		if (value < p[pivot])
			Find_order(p, l, pivot - 1, value);
		else
			Find_order(p, pivot + 1, r, value);
}

int Find_order(int p[], int l, int r, int value)
{
	if (l > r)
		return -1;

	int pivot = (l + r) / 2;

	if (p[pivot] == value)
		return pivot;  //printf("Find-order %d\n", pivot);
	else
		if (value < p[pivot])
			return Find_order(p, l, pivot - 1, value);
		else
			return Find_order(p, pivot + 1, r, value);
}


/*
 * Find_interpolation : interpolacni vyhledavani
 * Params: 
 *	p - pole hodnot
 *	l - dolni mez intervalu hledani
 *	r - horni mez intervalu hledani
 *	x0 - dolni mez hledane hodnoty
 *	x1 - horni mez hledane hodnoty
 *	value - hledana hodnota
 */
int Find_interpolation(char p[], int l, int r, char x0, char x1, char value)
{
	if (l > r)
        return -1;

	int pivot = l + (value - x0) * (r - l) / (x1 - x0);

	if (p[pivot] == value)
		return pivot; // printf("Find-order-interpolation %d\n", pivot);
	else
        if (value < p[pivot])
            return Find_interpolation(p, l, pivot - 1, x0, x1, value);
        else
            return Find_interpolation(p, pivot + 1, r, x0, x1, value);
}

/*
 * Main.
 */



int _tmain(int argc, _TCHAR* argv[])
{
	int p[] = { 5, 2, 4, 1, 3 };
	int p2[] = { 3, 5, 10, 15, 26 };
	char p3[] = { 'B', 'C', 'F', 'G', 'I', 'J', 'K', 'L', 'O', 'P', 'Q', 'R', 'Z' };

	int pos1 = Find_noorder(p, 5, 1);
	int pos2 = Find_order(p2, 0, 4, 15);
	int pos3 = Find_interpolation(p3, 0, 13, 'A', 'Z', 'C');

	printf("%d;%d;%d\n", pos1, pos2, pos3);

	return 0;
}

