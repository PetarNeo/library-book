#ifndef _lispoz_h_
#define _lispoz_h_
#include "pozajmica.h"

class Lispoz {

	void kopiraj(const Lispoz& l);
	void premesti(Lispoz& l);
	void brisi();

public:
	struct Elem {
		Pozajmica* poz;
		Elem* sled;
		Elem(Pozajmica* p, Elem* s = nullptr) :poz(p), sled(s) {}
	};
	Elem* prvi = nullptr;
	Elem* posl = nullptr;

	Lispoz() = default;
	Lispoz(const Lispoz& l) { kopiraj(l); }
	Lispoz(Lispoz&& l) { premesti(l); }
	~Lispoz() { brisi(); }
	Lispoz& operator=(const Lispoz& l) {
		if (this != &l) { brisi(); kopiraj(l); }
		return *this;
	}
	Lispoz& operator=(Lispoz&& l) {
		if (this != &l) { brisi(); premesti(l); }
		return *this;
	}

	Lispoz& operator+=(Pozajmica& p);
	Pozajmica* dohvPoz(Knjiga* k);
	Lispoz& operator-=(Pozajmica & p);

	friend ostream& operator<<(ostream& os, const Lispoz& l) {
		for (Elem* tek = l.prvi; tek; tek = tek->sled) {
			os << *tek->poz << endl;
		}
		return os;
	}

};

#endif