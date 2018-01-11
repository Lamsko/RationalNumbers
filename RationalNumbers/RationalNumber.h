#pragma once

#include <iostream>

using namespace std;

class RationalNumber
{
	friend RationalNumber operator+(const RationalNumber& a, const RationalNumber& b);
	friend RationalNumber operator-(const RationalNumber& a, const RationalNumber& b);
	friend RationalNumber operator*(const RationalNumber& a, const RationalNumber& b);
	friend RationalNumber operator/(const RationalNumber& a, const RationalNumber& b);
	friend bool operator==(const RationalNumber& a, const RationalNumber& b);
	friend bool operator!=(const RationalNumber& a, const RationalNumber& b);
	friend bool operator<(const RationalNumber& a, const RationalNumber& b);
	friend bool operator>(const RationalNumber& a, const RationalNumber& b);
	friend bool operator<=(const RationalNumber& a, const RationalNumber& b);
	friend bool operator>=(const RationalNumber& a, const RationalNumber& b);
	friend ostream& operator<<(ostream& out, const RationalNumber& obj);
	//friend istream& operator>>(istream& in, RationalNumber& obj);



public:
	RationalNumber();
	RationalNumber(double x);
	RationalNumber(int num, int den = 1);
	~RationalNumber();

	RationalNumber& operator=(const RationalNumber& obj);
	RationalNumber& operator+=(const RationalNumber& obj);
	RationalNumber& operator-=(const RationalNumber& obj);
	RationalNumber& operator*=(const RationalNumber& obj);
	RationalNumber& operator/=(const RationalNumber& obj);
	RationalNumber& operator++();
	RationalNumber& operator--();
	RationalNumber& operator+() const;
	RationalNumber& operator-() const;

	void setNumerator(int num);
	int getNumerator() const;
	void setDenominator(int den);
	int getDenominator() const;

private:
	int numerator;
	int denominator;
	void simplify();
};

