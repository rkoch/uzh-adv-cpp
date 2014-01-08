/*
 * manipulator.h
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#ifndef _MANIPULATOR_H_
#define _MANIPULATOR_H_

#include <iostream>

using std::ios_base;
using std::ostream;

class io_manipulator {

public:

	static ostream& scientific(ostream &stream) {
		stream.setf(ios_base::scientific, ios_base::floatfield);
		return stream;
	}

	static ostream& normal(ostream &stream) {
		stream.unsetf(ios_base::scientific);
		return stream;
	}

	static ostream& float_prec(ostream &stream) {
		stream.precision(10);
		return stream;
	}

};

#endif
