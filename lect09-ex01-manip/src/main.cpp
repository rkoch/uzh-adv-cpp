/*
 * main.cpp
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#include <iostream>

#include "manipulator.cc"

using std::cout;
using std::endl;
using std::ostream;

ostream& float_prec(ostream &stream) {
	stream.precision(3);
	return stream;
}

int main(int argc, char **argv) {
	cout << &float_prec << 3.14159265359 << endl;
	cout << io_manipulator::scientific << 3.14159265359 << endl;
	cout << io_manipulator::normal << 3.14159265359 << endl;
}
