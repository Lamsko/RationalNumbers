#include "RationalNumber.h"

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <limits.h>

int abs(int x)
{
	if (x >= 0)
	{
		return x;
	}
	else
	{
		return -x;
	}
}

void getFactors(int num, vector<int>& factorSet)
{
	if (num != 1)
	{
		factorSet.push_back(num);
	}
	for (int i = 2; i <= sqrt(static_cast<double>(num)); i++)
	{
		if (num % i == 0)
		{
			factorSet.push_back(i);
			factorSet.push_back(num / i);
		}
	}
}

void simplifyF(int& a, int& b)
{
	int tempN = a;
	int tempD = b;
	int small, temp;
	vector<int> factorSet;
	if (tempN == -tempD)
	{
		a = -1;
		b = 1;
		return;
	}
	else if (tempN == 0)
	{
		b = 1;
		return;
	}

	if (abs(tempN) < abs(tempD))
	{
		small = abs(tempN);
	}
	else
	{
		small = abs(tempD);
	}

	getFactors(small, factorSet);
	for (int i = 0; i < factorSet.size(); i++)
	{
		temp = factorSet[i];
		while (tempN % temp == 0 && tempD % temp == 0)
		{
			tempN /= temp;
			tempD /= temp;
		}
	}
	a = tempN;
	b = tempD;
}

RationalNumber::RationalNumber()
{
	setNumerator(0);
	setDenominator(1);
}

RationalNumber::RationalNumber(double x)
{
	int i = 1;
	while (x * i - static_cast<int> (x * i) != 0)
	{
		if (i > INT_MAX / 10)
		{
			cout << "Tej liczby: " << x << " nie mozna zamienic na liczbe wymierna. Jest zbyt dluga i zostala ustawiona na 0." << endl;
			setNumerator(0);
			setDenominator(1);
			return;
		}
		else
		{
			i *= 10;
		}
	}
	setNumerator(x*i);
	setDenominator(i);
	simplify();
}


RationalNumber::RationalNumber(int num, int den)
{
	setNumerator(num);
	setDenominator(den);
	simplify();
}

RationalNumber::~RationalNumber()
{
}

RationalNumber & RationalNumber::operator=(const RationalNumber & obj)
{
	setNumerator(obj.getNumerator());
	setDenominator(obj.getDenominator());
	return *this;
}

RationalNumber & RationalNumber::operator+=(const RationalNumber & obj)
{
	*this = *this + obj;
	return *this;
}

RationalNumber & RationalNumber::operator-=(const RationalNumber & obj)
{
	*this = *this - obj;
	return *this;
}

RationalNumber & RationalNumber::operator*=(const RationalNumber & obj)
{
	*this = *this * obj;
	return *this;
}

RationalNumber & RationalNumber::operator/=(const RationalNumber & obj)
{
	*this = *this / obj;
	return *this;
}

RationalNumber & RationalNumber::operator++()
{
	*this = *this + 1;
	return *this;
}

RationalNumber & RationalNumber::operator--()
{
	*this = *this - 1;
	return *this;
}

RationalNumber RationalNumber::operator+() const
{
	return *this;
}

RationalNumber RationalNumber::operator-() const
{
	RationalNumber temp;
	temp.setNumerator(-getNumerator());
	temp.setDenominator(getDenominator());
	return temp;
}

RationalNumber operator+(const RationalNumber & a, const RationalNumber & b)
{
	RationalNumber temp;
	int tempLD = a.getDenominator();
	int tempRD = b.getDenominator();
	simplifyF(tempLD, tempRD);
	temp.setDenominator(a.getDenominator() * tempRD);
	temp.setNumerator(a.getNumerator() * tempRD + b.getNumerator() * tempLD);
	temp.simplify();
	return temp;
}

RationalNumber operator-(const RationalNumber & a, const RationalNumber & b)
{
	return a + (-b);
}

RationalNumber operator*(const RationalNumber & a, const RationalNumber & b)
{
	RationalNumber temp;
	int a1 = a.getDenominator();
	int b1 = a.getNumerator();
	int a2 = b.getDenominator();
	int b2 = b.getNumerator();
	temp.setNumerator(b1*b2);
	temp.setDenominator(a1*a2);
	return temp;
}

RationalNumber operator/(const RationalNumber & a, const RationalNumber & b)
{
	RationalNumber temp_1(a.getNumerator(), a.getDenominator());
	RationalNumber temp_2(b.getNumerator(), b.getDenominator());
	return temp_1 * temp_2;
}

bool operator==(const RationalNumber & a, const RationalNumber & b)
{
	return (a.numerator == b.numerator && a.denominator == b.denominator);
}

bool operator!=(const RationalNumber & a, const RationalNumber & b)
{
	return !(a == b);
}

bool operator<(const RationalNumber & a, const RationalNumber & b)
{
	int left = a.getNumerator() * b.getDenominator();
	int right = a.getDenominator() * b.getNumerator();
	return (left < right);
}

bool operator>(const RationalNumber & a, const RationalNumber & b)
{
	int left = a.getNumerator() * b.getDenominator();
	int right = a.getDenominator() * b.getNumerator();
	return (left > right);
}

bool operator<=(const RationalNumber & a, const RationalNumber & b)
{
	return ((a < b) || (a == b));
}

bool operator>=(const RationalNumber & a, const RationalNumber & b)
{
	return ((a > b) || (a == b));
}

ostream & operator<<(ostream & out, const RationalNumber & obj)
{
	out << obj.numerator;
	if (obj.numerator != 0 && obj.denominator != 1)
	{
		out << "/" << obj.denominator;
	}
	return out;
}

/*istream & operator>>(istream & in, RationalNumber & obj)
{
	// TODO: insert return statement here
}*/

void RationalNumber::setNumerator(int num)
{
	numerator = num;
}

int RationalNumber::getNumerator() const
{
	return numerator;
}

void RationalNumber::setDenominator(int den)
{
	denominator = den;
}

int RationalNumber::getDenominator() const
{
	return denominator;
}

void RationalNumber::simplify()
{
	int tempN = numerator;
	int tempD = denominator;
	simplifyF(tempN, tempD);
	setNumerator(tempN);
	setDenominator(tempD);
}
