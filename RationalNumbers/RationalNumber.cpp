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
}


RationalNumber::~RationalNumber()
{
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
	RationalNumber temp_2(b.getNumerator(), a.getDenominator());
	RationalNumber temp_3(a.getNumerator(), b.getDenominator());
	int a1 = temp_2.getDenominator();
	int b1 = temp_2.getNumerator();
	int a2 = temp_3.getDenominator();
	int b2 = temp_3.getNumerator();
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
