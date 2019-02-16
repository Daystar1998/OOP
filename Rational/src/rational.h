#pragma once

#include <sstream>
#include <string>

using std::ostream;
using std::string;

class Rational {

private:

	long numerator;
	long denominator;
public:

	Rational(int numerator = 0, int denominator = 1);

	const Rational& operator=(const Rational &rValue);

	Rational& operator++();

	Rational operator++(int);

	Rational& operator--();

	Rational operator--(int);

	Rational& operator+=(const Rational &other);

	bool operator==(const Rational &rValue) const;

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

ostream& operator<<(ostream &out, const Rational &rational);