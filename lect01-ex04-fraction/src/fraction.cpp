/*
 * fraction.cpp
 *
 *  Created on: 25.09.2013
 *      Author: rko
 */

#include "fraction.h"

// Constructor
fraction::fraction(int pCounter, int pDenom)
		: counter(pCounter) {
	validateDenominator(pDenom);
	denominator = pDenom;
}

int fraction::getCounter() {
	return counter;
}

void fraction::setCounter(int pCounter) {
	counter = pCounter;
}

int fraction::getDenominator() {
	return denominator;
}

void fraction::setDenominator(int pDenominator) {
	validateDenominator(pDenominator);
	denominator = pDenominator;
}

fraction fraction::operator +(fraction &pSummand) {
	fraction res;

	res.counter = (counter * pSummand.denominator) + (pSummand.counter * denominator);
	res.denominator = denominator * pSummand.denominator;
	res.reduce();          // normalize the resulting fraction

	return res;
}

fraction fraction::operator -(fraction &pSubtrahend) {
	fraction res;

	res.counter = (counter * pSubtrahend.denominator) - (pSubtrahend.counter * denominator);
	res.denominator = denominator * pSubtrahend.denominator;
	res.reduce();          // normalize the resulting fraction

	return res;
}

fraction fraction::operator *(fraction &pMultiplicator) {
	fraction res;

	res.counter = counter * pMultiplicator.counter;
	res.denominator = denominator * pMultiplicator.denominator;
	res.reduce();          // normalize the resulting fraction

	return res;
}

fraction fraction::operator /(fraction &pDivisor) {
	fraction res;

	res.counter = counter * pDivisor.denominator;
	res.denominator = denominator * pDivisor.counter;
	res.reduce();          // normalize the resulting fraction

	return res;
}

bool fraction::operator ==(int num) {
	if (denominator != 1) {
		// if denominator is not equals one they cannot be the same as
		// the fraction will always be reduced
		return false;
	}
	return counter == num;
}

bool fraction::operator !=(int num) {
	return !operator==(num);
}

bool fraction::operator <(const fraction &comp) const {
	int l = this->counter * comp.denominator;
	int r = comp.counter * this->denominator;

	return l < r;
}

std::istream& operator>>(std::istream& is, fraction &fraction) {
	char separator;
	is >> fraction.counter;
	// This is just to remove the '/' separator
	is >> separator;
	is >> fraction.denominator;

	return is;
}

std::ostream& operator<<(std::ostream& os, const fraction &fraction) {
	os << fraction.counter << "/" << fraction.denominator;
	return os;
}

// private api

// this is the euclidian algorithm for the biggest common divisor
int fraction::bcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void fraction::reduce() {
	// bcd only makes sense for positive numbers
	int i = counter;
	if (i < 0) {
		i *= -1;
	}
	int j = denominator;
	if (j < 0) {
		j *= -1;
	}

	int calc_bcd = bcd(i, j);

	// actually reduce the fraction
	counter /= calc_bcd;
	denominator /= calc_bcd;
}

void fraction::validateDenominator(int pDenom) {
	if (pDenom == 0) {
		throw "It is not possible to have a 0 denominator";
	}
}
