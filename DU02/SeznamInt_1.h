#pragma once

// Trida reprezentuje pole celociselnych hodnot a umoznuje postupne zapisovat hodnoty do pole.
class SeznamInt_1
{
private:
	int *p_hodnoty;		// ukazatel na dynamicky alokovane pole celych cisel, velikost pole je dana atributem capacity
	int capacity;		// velikost pole
	int n;				// pocet hodnot postupne zapsanych do pole. Udava index prvnich neobsazeneho prvku.

private:
	// Provede realokaci pole.
	void realokace();

public:
	// Konstruktor - parametricky. Vytvoøi pole o pøedané velikosti (kapacite).
	SeznamInt_1(int capacity);

	// Konstruktor kopirovaci - vytvori identickou kopii objektu s polem celociselnych hodnot.
	SeznamInt_1(const SeznamInt_1 &o);

	// Destruktor.
	~SeznamInt_1();

	// Vrati pocet hodnot zapsanych do pole.
	int Count() const;

	// Vrati velikost pole, max. pocet hodnot, ktery lze do pole zapsat. 
	int Capacity() const;

	// ----------------------------------
	// - zakladni metody pro praci s pole a cisly

	// Zapise hodnotu do pole na prvni neobsazenou pozici. Vrati hodnotu true, pokud doslo k uspesnemu zapisu a pole jiz nebylo zaplnene.
	bool Add(int value);

	// Odstrani hodnotu ze zadane pozice a hodnoty na vyssich pozicich posune o jednu pozici vlevo.
	bool Remove(int id);

	// Otestuje vyskyt hodnoty value v poli. Vrati hodnotu true, pokud hodnota v poli existuje. 
	bool Contains(int value) const;

	// Vrati vyskyt hodnoty value v poli, pocitano od 0. Pokud hodnota v poli neexistuje, pak vrati hodnotu -1.
	int IndexOf(int value) const;
	int IndexOf(int value, int pos/* = 0*/) const;

	// Vrati posledni vyskyt hodnoty value v poli, pocitano od 0. Pokud hodnota v poli neexistuje, pak vrati hodnotu -1.
	int LastIndexOf(int value) const;

	// Vrati kopii pole hodnot. Velikost pole je dana poctem hodnot zapsanych do pole.
	int* Copy() const;

	// -----------------------------------
	// - metody pro zpracovani hodnot

	// Vrati minimalni hodnotu zapsanou do pole. 
	int GetMin() const;

	// Vrati maximalni hodnotu zapsanou do pole. 
	int GetMax() const;

	// Spocita a vrati prumernou hodnotu z cisel zapsanych do pole. 
	double CalcAvg() const;

	// Vrati minimalni a maximalni hodnotu prostrednictvim vystupnich parametru.
	void GetMinMax(int *p_min, int *p_max) const;

	// Vrati pozici s maximalni hodnotou. Pokud je pole prazdne, pak vrati hodnotu -1.
	int GetIdMax() const;

	// Vrati vsechny pozice vyskytu maximalni hodnoty jako pole hodnot. Parametrem n_max je predana velikost pole, resp. pocet zjistenych vyskytu.
	int* GetIdsMax(int v, int *n_max /* int &n_max */);

	// Otestuje, jestli jsou hodnoty zapsane v poli ve vzestupne posloupnosti.
	bool JeSerazenoVzestupne() const;

	// ----------------------------------
	// - operatory

	friend bool operator==(SeznamInt_1 &o1, SeznamInt_1 &o2);

	// nacte posloupnost celych cisel zakoncenou ukoncovacim symbolem a naplni pole nactenimi cisly
	friend istream &operator >> (istream &is, SeznamInt_1 &o);

	// vytiskne pole hodnot na standardni vystup
	friend ostream &operator<<(ostream &os, SeznamInt_1 o);
};
