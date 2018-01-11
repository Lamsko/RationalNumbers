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
	void getNumerator() const;
	void setDenumerator(int den);
	void getDenumerator() const;

private:
	int numerator;
	int denumerator;
};

