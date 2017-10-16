#ifndef DEF_ZFRACTION
#define DEF_ZFRACTION

#include <iostream>

class ZFraction
{
public:

	ZFraction(int num = 0, int denom = 1);
	void simplify();
	void denominatorZero() const;
	void setMinusToDenom();
	void display(std::ostream& flux) const;
	void numerator() const;
	void denominator() const;
	void nombreReel();
	ZFraction& operator+=(ZFraction const& autre);
	ZFraction& operator-=(ZFraction const& autre);
	ZFraction& operator*=(ZFraction const& autre);
	ZFraction& operator/=(ZFraction const& autre);
	bool compareEqual(ZFraction const& autre) const;
	bool biggerThan(ZFraction const& autre) const;

private:

	int m_num;
	int m_denom;
};
ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
ZFraction operator/(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a);

bool operator>(ZFraction const& a, ZFraction const& b);
bool operator==(ZFraction const& a, ZFraction const& b);


std::ostream& operator<<(std::ostream& flux, ZFraction const& fraction);
int pgcd(int, int);

#endif