#ifndef _biblioteka_h_
#define _biblioteka_h_
#include "knjiga.h"
#include "lispoz.h"

class Biblioteka {

	string naziv;
	static int br_knjiga;
	int kapacitet;
	Lispoz istorija, tekuci;
	friend class Lispoz;

	struct Elem {

		Knjiga* knj;
		Elem* sled;
		Elem(Knjiga* k, Elem* s = nullptr) : knj(k), sled(s) {}

	};
	Elem* prvi = nullptr, * posl = nullptr;

	void kopiraj(const Biblioteka& b);
	void premesti(Biblioteka& b);
	void brisi();

public:

	Biblioteka(string naz, int kap) : naziv(naz), kapacitet(kap) {}
	Biblioteka(const Biblioteka& b) { kopiraj(b); }
	Biblioteka(Biblioteka&& b) { premesti(b); }
	~Biblioteka() { brisi(); }
	Biblioteka& operator=(const Biblioteka& b) { if (this != &b) { brisi(); kopiraj(b); }return *this; }
	Biblioteka& operator=(Biblioteka&& b) { if (this != &b) { brisi(); premesti(b); }return *this; }

	string dohvNaz() const { return naziv; }
	int dohvBr_knj()const { return br_knjiga; }
	const int dohvKap()const { return kapacitet; }

	friend ostream& operator<<(ostream& os, const Biblioteka& b) {
		os << "BIBLIOTEKA " << b.naziv << "  " << b.br_knjiga << "/" << b.kapacitet << endl;
		for (Elem* tek = b.prvi; tek; tek = tek->sled) {
			if (tek->knj->poz == 0) os << "?" << endl;
			else os << *tek->knj << endl;
		}
		os << "TEKUCI" << endl;
		for (Lispoz::Elem* tek = b.tekuci.prvi; tek; tek = tek->sled) {
			os << *tek->poz << endl;
		}
		os << "ISTORIJA" << endl;
		for (Lispoz::Elem* tek = b.istorija.prvi; tek; tek = tek->sled) {
			os << *tek->poz << endl;
		}
		return os;
	}

	void dodaj(Knjiga* k);
	Biblioteka& operator+=(Knjiga& k);
	Knjiga* dohvKnj(int id);

	Biblioteka& pozajmi(Datum* d, int id);
	Biblioteka& vrati(Knjiga* k, Datum* d);

};
#endif