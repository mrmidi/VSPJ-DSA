#pragma once

// Trida reprezentuje pole celociselnych hodnot a umoznuje zapisovat hodnoty do pole na urcenou pozici. Pozice hodnoty v poli je vyznamova.
class SeznamInt_2
{
private:
	static const int DEFAULT_VALUE = -1;	// defautlni hodnota pro prvky pole, ktera znamena neobsazeny prvek
	static const int CAPACITY = 7;			// velikost pole
	//int p_hodnoty[CAPACITY];				// Pole celych cisel, velikost pole je dana atributem capacity
    int **p_hodnoty;

public:
	// Konstruktor. Provede potrebnou inicializaci pole.
	SeznamInt_2();

	// Destruktor.
	~SeznamInt_2();

	// ----------------------------------

	// Zajisti inicializaci hodnot prvku pole na defautlni hodnotu.
	void Init();

	// Zapise hodnotu value do pole na zadanou pozici.
	void Add(int i, int value);

	// Odstrani hodnotu ze zadane pozice prvku pole.
	void Remove(int i);

	// ----------------------------------

	// Vrati minimum z hodnot, ktere jsou zapsany v poli na pozicich. Pokud nebude v poli zapsana zadna platne hodnota, pak funkce vrati defaultni hodnotu.
	int GetMin() const;

	// Spocita prumernou hodnotu z hodnot zapsanych v poli na pozicich.
	double CalcAvg() const;

	// ----------------------------------

	// Indexer - zprostredkovava primy pristup k prvkum pole.
	int operator[](int id);

	// vytiskne pole hodnot na standardni vystup
	friend ostream &operator<<(ostream &os, SeznamInt_2 o);

	// ----------------------------------

	// Metoda ur�� pozici prvku pole. Parametr p_hodnoty je ukazatel na pole o velikosti n, p_prvek je ukazatel na prvek.
	static int CalcPosition(int *p_hodnoty, int n, int *p_prvek);
};