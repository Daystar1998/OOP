#include "rational.h"

Rational::Rational(int numerator, int denominator)
	: numerator(numerator), denominator(denominator) {

	if (denominator == 0) {

		throw "Error: Divide by zero";
	}

	reduce();
}

// Author: Dana Steil
// Edited by Matthew Day to check for a denominator of zero
const Rational& Rational::operator=(const Rational &rValue) {

	numerator = rValue.numerator;
	denominator = rValue.denominator;

	if (denominator == 0) {

		throw "Error: Divide by zero";
	}

	reduce();

	return *this;
}

// Author: Dana Steil
Rational& Rational::operator++() {

	numerator += denominator;
	reduce();

	return *this;
}

// Author: Dana Steil
Rational Rational::operator++(int) {

	Rational result = *this;
	numerator += denominator;

	reduce();

	return result;
}

Rational& Rational::operator--() {

	numerator -= denominator;
	reduce();

	return *this;
}

// Author: Dana Steil
bool Rational::operator==(const Rational & rValue) const {

	bool result = true;

	if (numerator != rValue.numerator || denominator != rValue.denominator) {

		result = false;
	}

	return result;
}

// Author: Dana Steil
string Rational::operator()() const {

	std::stringstream stream;
	stream << numerator << "/" << denominator;

	return stream.str();
}

// Author: Dana Steil
long Rational::getNumerator() const {

	return numerator;
}

// Author: Dana Steil
long Rational::getDenominator() const {

	return denominator;
}

// Author: Dana Steil
long Rational::leastCommonMultiple(long x, long y) const {

	bool Continue = true;

	long result = x;

	while (result % y != 0) {

		result += x;
	}

	return result;
}

// Author: Dana Steil
long Rational::greatestCommonDivisor(long x, long y) const {

	long remainder = x % y;

	while (remainder != 0) {

		x = y;
		y = remainder;

		remainder = x % y;
	}

	return y;
}

// Author: Dana Steil
void Rational::reduce() {

	long GCD = greatestCommonDivisor(numerator, denominator);

	numerator = numerator / GCD;
	denominator = denominator / GCD;
}

// Author: Dana Steil
ostream &operator<<(ostream & out, const Rational &rational) {

	out << rational.getNumerator() << "\\" << rational.getDenominator();

	return out;
}