/*
 * util.cpp
 *
 *  Created on: 30.10.2013
 *      Author: rko
 */

namespace util {

// this is the euclidian algorithm for the biggest common divisor
int bcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

}
