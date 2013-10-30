/*
 * main.cpp
 *
 *  Created on: 30.10.2013
 *      Author: rko
 */

#include <iostream>
#include <exception>

#include "fraction.h"

using std::exception;
using std::cout;
using std::endl;

using fractions::fraction;

int main(int pArgc, const char* pArgv[]) {

	// some test cases for fraction as I don't know
	// how to use an actual unittest framework in C++
	// I'm more of a Java guy :-P

	// Test 1: Instantiation with denominator = 0 should throw an error
	cout << "Test 1: ";
	try {
		fraction f(1, 0);
		cout << "FAILED  (no exception thrown)";
	} catch (char* &pEx) {
		cout << "SUCCESS (exception was thrown)";
	}
	cout << endl;

	// Test 2: Setting the denominator to 0 should throw an error
	cout << "Test 2: ";
	fraction f(1, 2);
	try {
		f.setDenominator(0);
		cout << "FAILED  (no exception thrown)";
	} catch (char* &pEx) {
		cout << "SUCCESS (exception was thrown)";
	}
	cout << endl;

	// instantiate some fractions
	fraction f1_2(1, 2);
	fraction f1_4(1, 4);
	fraction fn1_4(-1, 4);
	fraction f1_n8(1, -8);

	// Test 3: Adding 1/2 + 1/4 should result in 3/4
	cout << "Test 3: ";
	fraction f3 = f1_2 + f1_4;
	if ((f3.getCounter() != 3) || (f3.getDenominator() != 4)) {
		cout << "FAILED ";
	} else {
		cout << "SUCCESS";
	}
	cout << " (result was " << f3.getCounter() << "/" << f3.getDenominator() << ")" << endl;

	// Test 4: Subtracting 1/2 - 1/4 should result in 1/4
	cout << "Test 4: ";
	fraction f4 = f1_2 - f1_4;
	if ((f4.getCounter() != 1) || (f4.getDenominator() != 4)) {
		cout << "FAILED ";
	} else {
		cout << "SUCCESS";
	}
	cout << " (result was " << f4.getCounter() << "/" << f4.getDenominator() << ")" << endl;

	// Test 5: Multiplicating 1/2 * 1/4 should result in 1/8
	cout << "Test 5: ";
	fraction f5 = f1_2 * f1_4;
	if ((f5.getCounter() != 1) || (f5.getDenominator() != 8)) {
		cout << "FAILED ";
	} else {
		cout << "SUCCESS";
	}
	cout << " (result was " << f5.getCounter() << "/" << f5.getDenominator() << ")" << endl;

	// Test 6: Dividing 1/2 / 1/4 should result in 2/1
	cout << "Test 6: ";
	fraction f6 = f1_2 / f1_4;
	if ((f6.getCounter() != 2) || (f6.getDenominator() != 1)) {
		cout << "FAILED ";
	} else {
		cout << "SUCCESS";
	}
	cout << " (result was " << f6.getCounter() << "/" << f6.getDenominator() << ")" << endl;

	// Test 7: Multiplicating 1/2 * -1/4 should result in -1/8
	cout << "Test 7: ";
	fraction f7 = f1_2 * fn1_4;
	if ((f7.getCounter() != -1) || (f7.getDenominator() != 8)) {
		cout << "FAILED ";
	} else {
		cout << "SUCCESS";
	}
	cout << " (result was " << f7.getCounter() << "/" << f7.getDenominator() << ")" << endl;

	// Test 8: Multiplicating 1/2 * 1/-8 should result in 1/-16
	cout << "Test 8: ";
	fraction f8 = f1_2 * f1_n8;
	if ((f8.getCounter() != 1) || (f8.getDenominator() != -16)) {
		cout << "FAILED ";
	} else {
		cout << "SUCCESS";
	}
	cout << " (result was " << f8.getCounter() << "/" << f8.getDenominator() << ")" << endl;

	// Test 9: Adding -1/4 + 1/-8 should result in -3/8
	cout << "Test 9: ";
	fraction f9 = fn1_4 + f1_n8;
	if (((f9.getCounter() == -3) && (f9.getDenominator() == 8)) || (((f9.getCounter() == 3) && (f9.getDenominator() == -8)))) {
		cout << "SUCCESS";
	} else {
		cout << "FAILED ";
	}
	cout << " (result was " << f9.getCounter() << "/" << f9.getDenominator() << ")" << endl;

	return 0;

}

