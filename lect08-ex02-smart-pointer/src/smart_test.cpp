/*
 * smart_test.cpp
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#include <iostream>
#include <string>

#include "smart_pointer.cpp"

using std::cout;
using std::endl;
using std::string;

struct bike {
	string brand;
};

void foo(smart_pointer<bike> org) {
	smart_pointer<bike> sp4(org);
	// why 5? because the copy ctr will be called on passing the org obj
	cout << "References (5 expected): " << sp4.ref_counter() << endl;
}

int main(int argc, char **argv) {

	bike* b = new bike();
	b->brand = "BMW";

	smart_pointer<bike> sp1(b);
	smart_pointer<bike> sp2;
	sp2 = sp1;
	smart_pointer<bike> sp3(sp1);

	cout << "Brand (->): " << sp3->brand << endl;

	sp1->brand = "Honda";

	cout << "Brand (*) (after changing to Honda through different ref): " << (*sp2).brand << endl;

	cout << "References (3 expected): " << sp3.ref_counter() << endl;

	foo(sp3);

	cout << "References (3 expected): " << sp3.ref_counter() << endl;

	return 0;
}
