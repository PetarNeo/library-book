#include "biblioteka.h"
#include "datum.h"
#include "pozajmica.h"
#include "lispoz.h"


int main() {

	/*Knjiga a("Tri praseta", "Petar");
	Knjiga b("Pepeljuga", "Sofija");
	Knjiga d("Zoro", "Stefan");
	Knjiga* c = !b;

	Biblioteka B("Skolska",10);
	 << a.dohvIden() << endl;
	cout << b.dohvIden() << endl;
	cout << c->dohvIden() << endl;
	B += a;
	B += b;
	B += *c;
	cout << B;

	Knjiga *e = B.dohvKnj(4);
	cout << *e << endl << endl;
	
	Datum d1(23, 3, 2001);
	Datum d2(26, 10, 2015);
	Datum d3(1, 7, 1972);
	Datum d4;
	
	Pozajmica p1(&a, &d1);
	Pozajmica p2(&b, &d3);
	Pozajmica p3(&a, &d4);
	p2.DatKraj(&d2);

	Lispoz l;
	l += p1;
	l += p2;
	l += p3;
	cout << l << endl;*/
	Knjiga a("Tri praseta", "Petar");
	Knjiga b("Pepeljuga", "Sofija");
	Knjiga d("Zoro", "Stefan");
	Knjiga* c = &a;

	Datum d1(23, 3, 2001);
	Datum d2(26, 10, 2015);
	Datum d3(1, 7, 1972);
	Datum d4;

	Biblioteka B("Skolska", 10);
	B += a;
	B += b;
	B += d;
	cout << B << endl;

	B.pozajmi(&d1, 4);
	B.pozajmi(&d2, 5);
	B.pozajmi(&d4, 6);
	
	B.vrati(&a, &d3);
	B.vrati(&d, &d4);
	B.vrati(&b, &d1);
	cout << B;


	



}