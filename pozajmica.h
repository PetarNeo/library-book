#ifndef _pozajmica_h_
#define _pozajmica_h_
#include "knjiga.h"
#include "datum.h"

class Pozajmica {

	Knjiga* knjiga;
	Datum *pocetak, *kraj = nullptr;
	bool status = false;
	friend class Biblioteka;

public:

	Pozajmica(Knjiga* k, Datum *poc) :knjiga(k), pocetak(poc) {}

	Knjiga* dohvKnj()const { return knjiga; }

	bool operator~() {
		if (status) return true;
		else return false;
	}

	void DatKraj(Datum* d) { kraj = d; status = true; }

	friend ostream& operator<<(ostream& os, const Pozajmica& p) {
		os << *p.knjiga << "( " << *p.pocetak;
		if (!p.kraj) { os << " )"; }
		else { os << "-" << *p.kraj << " )"; }
		return os;
	}

};

#endif