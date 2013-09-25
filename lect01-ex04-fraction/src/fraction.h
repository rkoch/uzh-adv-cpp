/*
 * fraction.h
 *
 *  Created on: 25.09.2013
 *      Author: rko
 */

#ifndef FRACTION_H_
#define FRACTION_H_

#include <exception>

class fraction {

private:
	int counter;
	int denominator;

	int bcd(int a, int b);
	void reduce();
	void validateDenominator(int pDenom);

public:
	fraction(int pCounter=0, int pDenom=1);

	int getCounter();
	void setCounter(int pCounter);

	int getDenominator();
	void setDenominator(int pDenominator);

	fraction operator+(fraction &pSummand);
	fraction operator-(fraction &pSubtrahend);
	fraction operator*(fraction &pMultiplicator);
	fraction operator/(fraction &pDivisor);

};


#endif /* FRACTION_H_ */
