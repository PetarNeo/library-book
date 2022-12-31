#include "lispoz.h"

void Lispoz::kopiraj(const Lispoz& l){
	Elem* novi = nullptr;
	for (Elem* tek = l.prvi; tek; tek = tek->sled) {
		novi = new Elem(tek->poz);
		if (!prvi) prvi = novi;
		else posl->sled = novi;
		posl = novi;
	}
}

void Lispoz::premesti(Lispoz& l){
	prvi = l.prvi;
	l.prvi = nullptr;
}

void Lispoz::brisi(){
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
}

Lispoz& Lispoz::operator+=(Pozajmica& p){
	Elem* novi = new Elem(&p);
	if (!prvi) prvi = novi;
	else posl->sled = novi;
	posl = novi;
	return *this;
}

Pozajmica* Lispoz::dohvPoz(Knjiga* k){
	for (Elem* tek = prvi; tek; tek = tek->sled) {
		if (tek->poz->dohvKnj() == k) return tek->poz;
	}
	return nullptr;
}

Lispoz& Lispoz::operator-=(Pozajmica& p){
	Elem* pret = nullptr;
	for (Elem* tek = prvi; tek; tek = tek->sled) {
		if (tek->poz == &p) {
			Elem* sled = tek->sled;
			if (tek == prvi && sled == nullptr) {
				prvi = nullptr;
				delete tek;
				break;
			}
			else if (sled == nullptr) {
				pret->sled = sled;
				delete tek;
				break;
			}
			else {
				Elem* p = sled;
				Pozajmica* pom = tek->poz;
				tek->poz = sled->poz;
				sled->poz = pom;
				tek->sled = sled->sled;
				delete p;
			}
		}
		pret = tek;
	}
	return *this;
}
