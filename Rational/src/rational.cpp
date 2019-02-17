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

Rational& Rational::operator+=(const Rational &other) {

	*this = *this + other;

	return *this;
}

Rational& Rational::operator-=(const Rational &other) {

	*this = *this - other;

	return *this;
}

Rational& Rational::operator*=(const Rational &other) {

	*this = *this * other;

	return *this;
}

Rational& Rational::operator/=(const Rational &other) {

	*this = *this / other;

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

Rational Rational::operator--(int) {

	Rational result = *this;
	numerator -= denominator;

	reduce();

	return result;
}

Rational::operator double() const {

	return (double)this->getNumerator() / (double)this->getDenominator();
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

Rational operator+(const Rational &left, const Rational &right) {

	long leastCommonMultiple = left.leastCommonMultiple(left.getDenominator(), right.getDenominator());

	long numerator = 0;

	if (left.getDenominator() != leastCommonMultiple) {

		numerator += left.getNumerator() * leastCommonMultiple;
	} else {

		numerator += left.getNumerator();
	}

	if (right.getDenominator() != leastCommonMultiple) {

		numerator += right.getNumerator() * leastCommonMultiple;
	} else {

		numerator += right.getNumerator();
	}

	Rational result(numerator, leastCommonMultiple);

	return result;
}

Rational operator-(const Rational &left, const Rational &right) {

	long leastCommonMultiple = left.leastCommonMultiple(left.getDenominator(), right.getDenominator());

	long numerator = 0;

	if (left.getDenominator() != leastCommonMultiple) {

		numerator = left.getNumerator() * leastCommonMultiple;
	} else {

		numerator = left.getNumerator();
	}

	if (right.getDenominator() != leastCommonMultiple) {

		numerator -= right.getNumerator() * leastCommonMultiple;
	} else {

		numerator -= right.getNumerator();
	}

	Rational result(numerator, leastCommonMultiple);

	return result;
}

Rational operator*(const Rational &left, const Rational &right) {

	long numerator = left.getNumerator() * right.getNumerator();
	long denominator = left.getDenominator() * right.getDenominator();

	return Rational(numerator, denominator);
}

Rational operator/(const Rational &left, const Rational &right) {

	long numerator = left.getNumerator() * right.getDenominator();
	long denominator = left.getDenominator() * right.getNumerator();

	return Rational(numerator, denominator);
}

// Author: Dana Steil
// Edited by Matthew Day to not require the left value to be a Rational object
bool operator==(const Rational &left, const Rational &right) {

	bool result = true;

	if (left.getNumerator() != right.getNumerator() || left.getDenominator() != right.getDenominator()) {

		result = false;
	}

	return result;
}

bool operator!=(const Rational &left, const Rational &right) {

	bool result = true;

	if (left.getNumerator() == right.getNumerator() && left.getDenominator() == right.getDenominator()) {

		result = false;
	}

	return result;
}

bool operator>(const Rational &left, const Rational &right) {

	bool result = true;

	long leastCommonMultiple = left.leastCommonMultiple(left.getDenominator(), right.getDenominator());

	long numeratorLeft;
	long numeratorRight;

	if (leastCommonMultiple == left.getDenominator()) {

		numeratorLeft = left.getNumerator();
	} else {

		numeratorLeft = leastCommonMultiple * left.getNumerator();
	}

	if (leastCommonMultiple == right.getDenominator()) {

		numeratorRight = right.getNumerator();
	} else {

		numeratorRight = leastCommonMultiple * right.getNumerator();
	}

	result = numeratorLeft > numeratorRight;

	return result;
}

bool operator>=(const Rational &left, const Rational &right) {

	bool result = false;

	if (left == right || left > right) {

		result = true;
	}

	return result;
}

bool operator<(const Rational &left, const Rational &right) {

	bool result = false;

	if (!(left >= right)) {

		result = true;
	}

	return result;
}

bool operator<=(const Rational &left, const Rational &right) {

	bool result = false;

	if (!(left > right)) {

		result = true;
	}

	return result;
}

// Author: Dana Steil
// Edited by Matthew Day to only show '/' and the denominator if the denominator is not equal to 1
ostream& operator<<(ostream &out, const Rational &rational) {

	out << rational.getNumerator();

	if (rational.getDenominator() != 1) {

		out << "/" << rational.getDenominator();
	}

	return out;
}

istream& operator>>(istream &in, Rational &rational) {

	string data;

	std::getline(in, data);

	int i;

	for (i = 0; i < data.size(); i++) {

		if (data[i] == '/') {

			break;
		}
	}

	string numerator = data.substr(0, i);

	if (i < data.size()) {

		string denominator = data.substr(i + 1, data.size() - i);

		rational = Rational(stol(numerator), stol(denominator));
	} else {

		rational = Rational(stol(numerator));
	}

	return in;
}