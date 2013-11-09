/*
 * pvector.cpp
 *
 *  Created on: 31.10.2013
 *      Author: rko
 */

#include <fstream>
#include "pvector.h"

template<typename T>
pvector<T>::pvector(string fname)
		: filename(fname), vector() {
	std::ifstream ifs(filename.c_str());
	T inp;
	// Problem: >> is formatted input which is determined by whitespace,
	// so strings which are longer than one word are separated
	// Solution: use getline instead of >>
	while (ifs >> inp) {
		vector.push_back(inp);
	}
	ifs.close();
}

template<typename T>
pvector<T>::~pvector() {
	// Rule of three: copy constructor and assignment operator are not implemented
	std::ofstream ofs(filename.c_str());
	for (typename std::vector<T>::iterator itr = vector.begin(); itr != vector.end(); itr++) {
		ofs << *itr << "\n";
	}
	ofs << std::flush;
	ofs.close();
}

template<typename T>
void pvector<T>::push_back(const T &element) {
	vector.push_back(element);
}

template<typename T>
void pvector<T>::pop_back() {
	vector.pop_back();
}

template<typename T>
int pvector<T>::size() {
	return vector.size();
}

template<typename T>
T pvector<T>::at(int idx) {
	return vector.at(idx);
}
