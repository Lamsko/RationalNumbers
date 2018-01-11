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

void simplify(int& a, int& b)
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
	return RationalNumber();
}

RationalNumber operator-(const RationalNumber & a, const RationalNumber & b)
{
	return RationalNumber();
}
