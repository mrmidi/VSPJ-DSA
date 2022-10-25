// Ukol1.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

// ----------------------------------------------------------------
// Domaci ukol:

class CislaOperace
{
public:
    static int faktorialNerek(int n) // O(3N)
    {
        // todo du
        int result = 1;
        while (n > 0)
        {
            result = result * n;
            n--;
        }
        return result;
    }

    static int mocninaR(int c, int m) // O(2N)
    {
        // todo du
        if (m < 2)
            return c;
        return c * mocninaR(c, m - 1);
    }

    int mocninaNerek(int c, int m) // O(3N)
    {
        // todo du
        int result = c;
        while (m > 1)
        {
            result = result * c;
            m--;
        }
        return result;
    }

    static int zjistiPocetKladnych(int* hodnoty, int n) // O(6N)
    {
        int positiveCount = 0;
        while (n > 0) {
            if (hodnoty[n - 1] > 0)
                positiveCount++;
            n--;
        }
        // todo du
        return positiveCount;
    }
};

int main(void)
{
    int fakto = CislaOperace::faktorialNerek(10);
    int *values = new int[5];
    for (int i = 0; i < 5; i++)
    {
        int number = rand() % 19 + (-9);
        values[i] = number;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << values[i] << " ";
    }
    std::cout << '\n';
    printf("Pocet kladnych: %d\n", CislaOperace::zjistiPocetKladnych(values, 5));
    //int positiveCount = CislaOperace::zjistiPocetKladnych(values, 5);
    printf("faktorialNerek = %d\n", fakto);
    printf("mocninaR = %d\n", CislaOperace::mocninaR(2, 10));
    printf("mocninaNerek = %d\n", CislaOperace::mocninaR(2, 10));
    //CislaOperace::FaktorialNerek(5);
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