#ifndef _knjiga_h_
#define _knjiga_h_
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class Knjiga {

	string naziv, autor;
	int identifikator;

public:
	static  int iden;
	int poz = 1;

	Knjiga(string n, string a) : naziv(n), autor(a),identifikator(iden) { iden++; }
	Knjiga(const Knjiga& k) = delete;
	Knjiga(Knjiga&& k) = delete;
	Knjiga& operator=(const Knjiga& k) = delete;
	
	string dohvNaz()const { return naziv; }
	string dohvAut()const { return autor; }
	int dohvIden()const { return identifikator; }

	friend ostream& operator<<(ostream& os, const Knjiga& k) {
		return os << "KNJIGA " << k.identifikator << " : " << k.naziv << "-" << k.autor;
	}
	Knjiga* operator!()const {
		return new Knjiga(this->naziv, this->autor);
	}
};
#endif
