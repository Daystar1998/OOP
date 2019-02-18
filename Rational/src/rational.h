#pragma once

#include <sstream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class Rational {

private:

	long numerator;
	long denominator;
public:

	Rational(long numerator = 0, long denominator = 1);

	const Rational& operator=(const Rational &rValue);

	Rational& operator+=(const Rational &other);

	Rational& operator-=(const Rational &other);

	Rational& operator*=(const Rational &other);

	Rational& operator/=(const Rational &other);

	Rational& operator++();

	Rational operator++(int);

	Rational& operator--();

	Rational operator--(int);

	Rational operator^(int exponent) const;

	operator double() const;

	string operator()() const;

	long leastCommonMultiple(long x, long y) const;

	long greatestCommonDivisor(long x, long y) const;
private:

	void reduce();
public:

	long getNumerator() const;

	long getDenominator() const;
};

Rational operator+(const Rational &left, const Rational &right);

Rational operator-(const Rational &left, const Rational &right);

Rational operator*(const Rational &left, const Rational &right);

Rational operator/(const Rational &left, const Rational &right);

bool operator==(const Rational &left, const Rational &right);

bool operator!=(const Rational &left, const Rational &right);

bool operator>(const Rational &left, const Rational &right);

bool operator>=(const Rational &left, const Rational &right);

bool operator<(const Rational &left, const Rational &right);

bool operator<=(const Rational &left, const Rational &right);

ostream& operator<<(ostream &out, const Rational &rational);

istream& operator>>(istream &in, Rational &rational);