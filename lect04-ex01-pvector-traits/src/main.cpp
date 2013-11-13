/*
 * main.cpp
 *
 *  Created on: 12.11.2013
 *      Author: rko
 */

#include <iostream>
// We need to include the cpp file as the implementation is
// needed to compile the pvector for each used datatype
#include "pvector.cpp"
#include "pset.cpp"
#include "fraction.cpp"

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

template<typename T>
void print(pset<T> &set) {
	cout << "Size: " << set.size() << "\n";
	if (set.size() > 0) {
		cout << "Contents:" << endl;
		int i = 0;
		for (typename pset<T>::iterator itr = set.begin(); itr != set.end(); itr++) {
			cout << i++ << ": " << *itr << "\n";
		}
		cout << std::flush;
	}
}

int main(int pArgc, char** pArgv) {

	// Testing pvector with int values
	cout << "--- pvector int test ----------" << endl;
	pvector<int> int_vec("data/int-data.txt");
	print(int_vec);
	int_vec.push_back(32);

	// Testing pvector with float values
	cout << "\n" << "--- pvector float test --------" << endl;
	pvector<float> float_vec("data/float-data.txt");
	print(float_vec);
	float_vec.push_back(32.34);

	// Testing pvector with strings
	cout << "\n" << "--- pvector string test -------" << endl;
	pvector<string> string_vec("data/string-data.txt");
	print(string_vec);
	string_vec.push_back("Another Test");

	// Testing pvector with fraction
	cout << "\n" << "--- pvector fraction test -----" << endl;
	pvector<fraction> fraction_vec("data/fraction-data.txt");
	print(fraction_vec);
	fraction_vec.push_back(fraction(3,2));

	// Testing pset with int values
	cout << "--- pset int test ----------" << endl;
	pset<int> int_set("data/int-set.txt");
	print(int_set);
	int_set.insert(32);
	int_set.insert(32);

	// Testing pset with float values
	cout << "\n" << "--- pset float test --------" << endl;
	pset<float> float_set("data/float-set.txt");
	print(float_set);
	float_set.insert(32.34);
	float_set.insert(32.34);

	// Testing pset with strings
	cout << "\n" << "--- pset string test -------" << endl;
	pset<string> string_set("data/string-set.txt");
	print(string_set);
	string_set.insert("Another Test");
	string_set.insert("Another Test");

	cout << "\n" << "now validate if entries in set are not duplicated." << endl;

}
