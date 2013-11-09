/*
 * main.cpp
 *
 *  Created on: 31.10.2013
 *      Author: rko
 */

#include <iostream>
// We need to include the cpp file as the implementation is
// needed to compile the pvector for each used datatype
#include "pvector.cpp"

using std::string;
using std::cout;
using std::endl;

template<typename T>
void print(pvector<T> &vec) {
	cout << "Size: " << vec.size() << "\n";
	if (vec.size() > 0) {
		cout << "Contents:" << endl;
		for (int i = 0; i < vec.size(); i++) {
			cout << i << ": " << vec.at(i) << "\n";
		}
	}
}

int main(int pArgc, char** pArgv) {

	// Testing with int values
	cout << "--- int test ----------" << endl;
	pvector<int> int_vec("data/int-data.txt");
	print(int_vec);
	int_vec.push_back(32);

	// Testing with float values
	cout << "\n" << "--- float test --------" << endl;
	pvector<float> float_vec("data/float-data.txt");
	print(float_vec);
	float_vec.push_back(32.34);

	// Testing with strings
	cout << "\n" << "--- string test -------" << endl;
	pvector<string> string_vec("data/string-data.txt");
	print(string_vec);
	string_vec.push_back("Another Test");

}
