// App_Pole2D.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include "Pole2D.h"
#include "Pole2Duk.h"
#include "Pole2D_2.h"
#include "Pole2Duk_2.h"

//improved random number generator
#include <random>
#include <cctype>

using u32    = uint_least32_t;
using engine = std::mt19937;


void InitMe(Pole2Duk &pole)
{
    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator( seed );
    const int MY_MAX = 15;		// RAND_MAX

    int n = pole.PocetRadku();
    int m = pole.PocetSloupcu();


    // init
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int rnd = std::uniform_int_distribution< u32 >( -15, MY_MAX )( generator );
            //cout << "row " << i << "; col " << j << "; val " << rnd << endl;
            pole.SetValue(rnd, i, j);   // <0; 100>
        }
}
void PrintSplit()
{
    std::cout << "----------------------------------------" << std::endl;
}

void ukazka2()
{
    Pole2Duk *pole = new Pole2Duk(4, 3); // pole(4, 3);
    Pole2Duk *multiplyme = new Pole2Duk(3, 4); // pole(3, 4) have same number of columns for multiplication
    Pole2Duk *summe = new Pole2Duk(4, 3); // pole(4, 3) equal size for sum


    //Error handling testing
    Pole2Duk *error = new Pole2Duk(5, 5); // 5x5 matrix for error testing

    // init matrix 1 (original)
    InitMe(*pole);
    // init matrix 2 (for multiplying)
    InitMe(*multiplyme);
    // init matrix 3 (for summing)
    InitMe(*summe);
    // init matrix 4 (for error testing)
    InitMe(*error);

    PrintSplit();
    cout << "Pole 1 (original):" << endl;
    Pole2Duk::tisk(*pole);
    PrintSplit();
    cout << "Pole 2 (for multiplying):" << endl;
    Pole2Duk::tisk(*multiplyme);
    PrintSplit();
    cout << "Pole 3 (for summing):" << endl;
    Pole2Duk::tisk(*summe);
    PrintSplit();
    cout << "Pole 4 (for error testing and realloc):" << endl;
    Pole2Duk::tisk(*error);
    PrintSplit();
    cout << "Pole 4 reallocated:" << endl;
    try {
        error->realoc(6, 6); // reallocating matrix 4 to 6x6 matrix
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }
    Pole2Duk::tisk(*error);
    cout << "rows: " << error->PocetRadku() << " columns:" << error->PocetRadku() << endl;
    PrintSplit();
    try {
        error->realoc(2, 2); // realocating matrix 4 to 2x2 matrix
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }
    cout << "Pole 4 realocated to 2x2:" << endl;
    Pole2Duk::tisk(*error);
    cout << "rows: " << error->PocetRadku() << " columns:" << error->PocetRadku() << endl;
    PrintSplit();

    //multiply and print result
    try {
        Pole2Duk* result = (*pole) * (*multiplyme);
        cout << "Pole 1 * Pole 2:" << endl;
        Pole2Duk::tisk(*result);
        delete result; //free memory
    }
    catch (const char* msg) { //catch incorrect dimensions
        cout << "Error: " << msg << endl;
    }
    PrintSplit();
    //sum and print result
    try {
        Pole2Duk* result = (*pole) + (*summe);
        cout << "Pole 1 + Pole 3:" << endl;
        Pole2Duk::tisk(*result);
        delete result; //free memory
    }
    catch (const char* msg) { //catch incorrect dimensions
        cout << "Error: " << msg << endl;
    }

    PrintSplit();
    //error testing
    try {
        Pole2Duk* result = (*pole) * (*error);
        cout << "Pole 1 * Error:" << endl;
        Pole2Duk::tisk(*result);
        delete result; //free memory
    }
    catch (const char* msg) { //catch incorrect dimensions
        cout << "Error: " << msg << endl;
    }
    PrintSplit();
    try {
        Pole2Duk* result = (*pole) + (*error);
        cout << "Pole 1 + Error:" << endl;
        Pole2Duk::tisk(*result);
        delete result; //free memory
    }
    catch (const char* msg) { //catch incorrect dimensions
        cout << "Error: " << msg << endl;
    }

    PrintSplit();
    delete pole;
}

// ----

void ukazka3()
{
    Pole2D_2 pole(3, 4);

    const int MY_MAX = 100;		// RAND_MAX

    srand(time(NULL));

    // init
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            pole.SetValue(rand() % (MY_MAX + 1), i, j);   // <0; 100>  //pole.SetValue(i * 4 + j, i, j);

    // tisk
    Pole2D_2::tisk(pole);

    // index of
    int r, s;
    int result;
    result = pole.IndexOf(5, &r, &s);
    cout << result << '\t' << "5 -> " << '[' << r << ';' << s << ']' << endl;

    // ---

    int* row = pole[1];
    int value = row[0];
    int value2 = row[4]; // !!!
    int value3 = row[8]; // !!!
    //int value4 = row[12]; // !!!
    //row[12] = 100000;
}

void ukazka4()
{
    Pole2Duk_2 *pole_uk = new Pole2Duk_2(3, 4);


    const int MY_MAX = 100;		// RAND_MAX

    srand(time(NULL));

    // init
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            pole_uk->SetValue(rand() % (MY_MAX + 1), i, j);   // <0; 100>  //pole.SetValue(i * 4 + j, i, j);

    // tisk
    Pole2Duk_2::tisk(*pole_uk);

    // index of
    int r, s;
    int result;
    result = pole_uk->IndexOf(5, &r, &s);
    cout << result << '\t' << "5 -> " << '[' << r << ';' << s << ']' << endl;

    // ---

    int** row = (*pole_uk)[1];
    int* value = row[0];
    int* value2 = row[4]; // !!!
    int* value3 = row[8]; // !!!
    //int value4 = row[12]; // !!!
    //row[12] = 100000;

    delete pole_uk;
}

int main()
{
    //ukazka1();
    ukazka2();
    //ukazka3();
    //ukazka4();
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
