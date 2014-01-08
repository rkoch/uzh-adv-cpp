/*
 * dumb_test.cpp
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#include <iostream>
#include <string>
#include "dumb_pointer.cpp"

using std::cout;
using std::endl;
using std::string;

struct car {
	string brand;
};

int main(int argc, char **argv) {
	car* c = new car();
	c->brand = "BMW";

	dumb_pointer<car> ptr(c);
	cout << ptr->brand << endl;
	cout << (*ptr).brand << endl;

	return 0;
}
