#include "ZFraction.h"

using namespace std;


//////////////////////////  fraction constructor //////////////////////////////////
ZFraction::ZFraction(int num, int denom) : m_num(num), m_denom(denom)
{
	simplify();
	denominatorZero();
	setMinusToDenom();
}
////////////////////////// if negative fraction, - sign is at denom ////////////////////////
void ZFraction::setMinusToDenom()
{
	if (m_num<0)
	{
		//TO BE DONE
	}
}

//////////////////////////  warns if denom is 0 //////////////////////////////////

void ZFraction::denominatorZero() const
{
	if (m_denom == 0)
	{
		cout << "ATTENTION denominator cannot be null ! Please exit now" << endl;
		system("pause");
	}
}

//////////////////////////  simplify fraction //////////////////////////////////
void ZFraction::simplify()
{
	if (m_num != 0 && m_denom != 0)
	{
		int commonFactor = pgcd(m_num, m_denom);
		m_num /= commonFactor;
		m_denom /= commonFactor;
	}
}

int pgcd(int a, int b)
{
	int i = 0;
	if (a < b || a == b) {
		for (i = a; !(b % i == 0 && a % i == 0); i--) {}
	}

	else if (a > b) {
		for (i = b; !(b % i == 0 && a % i == 0); i--) {}
	}

	return i;

}

//////////////////////////  convert fraction to real number //////////////////////////////////
void ZFraction::nombreReel()
{
	double reelNum = m_num;
	reelNum /= m_denom;

	cout << "Cela correspond au un chiffre reel: " << reelNum << endl;
}

//////////////////////////  method display fraction //////////////////////////////////
void ZFraction::display(ostream &flux) const
{
	flux << m_num << '/' << m_denom;
}

void ZFraction::numerator() const
{
	cout << "Le denominateur de la fraction est" << m_num << endl;
}

void ZFraction::denominator() const
{
	cout << "Le denominateur de la fraction est" << m_denom << endl;
}

//////////////////////////  cout operator for object //////////////////////////////////
ostream& operator<<(ostream& flux, ZFraction const& fraction)
{
	fraction.display(flux);

	return flux;
}
////////////////////////// - unary operator ///////////////////////////////////////////
ZFraction operator-(ZFraction const& a)
{
	ZFraction copy(a);
	copy = copy - 2 * a;

	return copy;
}

//////////////////////////  accessor method += operator for fraction object //////////////////////////////////
ZFraction& ZFraction::operator+=(ZFraction const& autre)
{
	m_num = m_num  *autre.m_denom + m_denom * autre.m_num;
	m_denom = m_denom*autre.m_denom;

	simplify();

	return *this;
}
//////////////////////////  + operator for object //////////////////////////////////
ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
	ZFraction copy(a);
	copy += b;

	return copy;
}

//////////////////////////  accessor method -= operator for fraction object //////////////////////////////////
ZFraction& ZFraction::operator-=(ZFraction const& autre)
{
	m_num = m_num  *autre.m_denom - m_denom * autre.m_num;
	m_denom = m_denom*autre.m_denom;

	simplify();

	return *this;
}
//////////////////////////  - operator for object //////////////////////////////////
ZFraction operator-(ZFraction const& a, ZFraction const& b)
{
	ZFraction copy(a);
	copy -= b;

	return copy;
}

//////////////////////////  accessor method *= operator for fraction object //////////////////////////////////
ZFraction& ZFraction::operator*=(ZFraction const& autre)
{
	m_num *= autre.m_num;
	m_denom *= autre.m_denom;

	simplify();

	return *this;
}

//////////////////////////  * operator for object //////////////////////////////////
ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
	ZFraction copy(a);
	copy *= b;

	return copy;
}

//////////////////////////  accessor method /= operator for fraction object //////////////////////////////////
ZFraction& ZFraction::operator/=(ZFraction const& autre)
{
	m_num *= autre.m_denom;
	m_denom *= autre.m_num;

	simplify();

	return *this;

}

//////////////////////////  / operator for object //////////////////////////////////
ZFraction operator/(ZFraction const& a, ZFraction const& b)
{
	ZFraction copy(a);
	copy /= b;

	return copy;
}

///////////////////////// accessor method compares equality with another fraction /////////////////////
bool ZFraction::compareEqual(ZFraction const& autre) const
{
	return (m_num*autre.m_denom == m_denom*autre.m_num);
}

//////////////////////////  == comparison operator between 2 fractions //////////////////////////////////
bool operator==(ZFraction const& a, ZFraction const& b)
{
	return a.compareEqual(b);
}

///////////////////////// accessor method compares if larger than fraction /////////////////////
bool ZFraction::biggerThan(ZFraction const& autre) const
{
	return (m_num*autre.m_denom > m_denom*autre.m_num);
}

//////////////////////////  > comparison operator between 2 fractions //////////////////////////////////
bool operator>(ZFraction const& a, ZFraction const& b)
{
	return a.biggerThan(b);

}
