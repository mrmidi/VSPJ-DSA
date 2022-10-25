// App_Pole1D.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//
#include <stdio.h>
#include <tchar.h>

#include <iostream>
using namespace std;

#include "SeznamInt_1.h"
#include "SeznamInt_2.h"


int main()
{
	int pos;
	bool exist, comp;
	SeznamInt_1 cisla_1(5);
	SeznamInt_1* cisla_1_b;

	cisla_1.Add(5);
	cisla_1.Add(4);
	cisla_1.Add(7);
	cout << cisla_1;
	cisla_1.Remove(1);
	cout << cisla_1;

	pos = cisla_1.IndexOf(7);
	printf("%d ", pos);
	pos = cisla_1.IndexOf(4);
	printf("%d ", pos);

	exist = cisla_1.Contains(7);
	printf("%d ", exist);
	exist = cisla_1.Contains(4);
	printf("%d ", exist);

	cisla_1_b = new SeznamInt_1(cisla_1);
	comp = cisla_1 == *cisla_1_b;
	printf("%d ", comp);

	printf("\n");

	delete cisla_1_b;
	cisla_1_b = NULL;

	// -----------------------

	SeznamInt_2 cisla_2;

	cisla_2.Add(0, 15);
	cisla_2.Add(2, 10);
	cisla_2.Add(5, 25);

	cout << cisla_2;
	cout << '\n';

    //cout << cisla_2.CalcPosition() ;

	// cisla_2[1]



	return 0;
}


// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
