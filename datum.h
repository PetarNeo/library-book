#ifndef _datum_h_
#define _datum_h_
#include <iostream>
#include <ostream>
using namespace std;

class Datum {

	int dan, mesec, godina;

public:

	Datum(int d = 1,int m = 1 ,int g = 1970):dan(d),mesec(m),godina(g){}

	int dohvDan()const { return dan; }
	int dohvMes()const { return mesec; }
	int dohvGod()const { return godina; }

	friend ostream& operator<<(ostream& os, const Datum& d) {
		if (d.dan < 10) os << "0" << d.dan;
		else os << d.dan;
		os << ".";
		if (d.mesec < 10) os << "0" << d.mesec;
		else os << d.mesec;
		os << ".";
		os << d.godina << ".";
		return os;
	}
};

#endif