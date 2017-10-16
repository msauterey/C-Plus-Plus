#include <iostream>
#include "ZFraction.h"
using namespace std;

int main()
{
	ZFraction a(8, 7);      //Déclare une fraction valant 4/5
	a.numerator();
	a.denominator();
	a.nombreReel();
	ZFraction b(6);        //Déclare une fraction valant 2/1 (ce qui vaut 2)
	ZFraction c, d, e, f, g;         //Déclare deux fractions valant 0

	c = a + b;               //Calcule 4/5 + 2/1 = 14/5

	d = a*b;               //Calcule 4/5 * 2/1 = 8/5

	e = a - b;

	f = a / b;

	g = -a;

	cout << " - " << a << " = " << g << endl;

	cout << a << " + " << b << " = " << c << endl;

	cout << a << " * " << b << " = " << d << endl;

	cout << a << " - " << b << " = " << e << endl;

	cout << a << " / " << b << " = " << f << endl;

	if (a > b)
		cout << "a est plus grand que b." << endl;
	else if (a == b)
		cout << "a est egal a b." << endl;
	else
		cout << "a est plus petit que b." << endl;

	system("pause");
	return 0;

}