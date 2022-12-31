#include "biblioteka.h"
int Biblioteka::br_knjiga = 0;

void Biblioteka::kopiraj(const Biblioteka& b){
	naziv = b.naziv;
	br_knjiga = b.br_knjiga;
	kapacitet = b.kapacitet;
	Elem* tek = b.prvi;
	Elem* novi = nullptr;
	while (tek) {
		novi = new Elem(tek->knj);
		if (!prvi) prvi = novi;
		else posl->sled = novi;
		posl = novi;
		tek = tek->sled;
	}
}

void Biblioteka::premesti(Biblioteka& b){
	naziv = b.naziv;
	br_knjiga = b.br_knjiga;
	kapacitet = b.kapacitet;
	prvi = b.prvi;
	b.prvi = nullptr;
}

void Biblioteka::brisi(){
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
}

void Biblioteka::dodaj(Knjiga* k) {
	Elem* novi = new Elem(k);
	if (!prvi) prvi = novi;
	else posl->sled = novi;
	posl = novi;
	br_knjiga++;
}

Biblioteka& Biblioteka::operator+=(Knjiga& k) {
	Knjiga* k1 = !k;
	dodaj(k1);
	return *this;
}

Knjiga* Biblioteka::dohvKnj(int id) {
	for (Elem* tek = prvi; tek; tek = tek->sled) {
		if (tek->knj->dohvIden() == id) {
			return tek->knj;
		}
	}
	return nullptr;
}

Biblioteka& Biblioteka::pozajmi(Datum* d, int id) {
	for (Elem* tek = prvi; tek; tek = tek->sled) {
		if (tek->knj->dohvIden() == id) {
			Pozajmica* p = new Pozajmica(tek->knj, d);
			tekuci += *p;
			tek->knj->poz = 0;
			//br_knjiga--;
			break;
		}
	}
	return *this;
}

Biblioteka& Biblioteka::vrati(Knjiga* k, Datum* d) {
	for (Lispoz::Elem* tek = tekuci.prvi; tek; tek = tek->sled) {
		if (tek->poz->dohvKnj()->dohvNaz() == k->dohvNaz()) {
			tek->poz->DatKraj(d);
			istorija += *tek->poz;
			tekuci -= *tek->poz;
			//br_knjiga++;
			break;
		}
	}
	for (Elem* tek = prvi; tek; tek = tek->sled) {
		if (tek->knj->poz == 0) {
			tek->knj->poz = 1;
			break;
		}
	}
	return *this;
}