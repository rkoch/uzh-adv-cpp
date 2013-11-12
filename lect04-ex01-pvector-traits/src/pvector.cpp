/*
 * pvector.cpp
 *
 *  Created on: 12.11.2013
 *      Author: rko
 */

#include <fstream>
#include "pvector.h"

using std::ifstream;
using std::ofstream;
using std::string;

template<typename T, typename P>
pvector<T, P>::pvector(string fname)
		: filename(fname), vector() {
	read_vector();
}

template<typename T, typename P>
pvector<T, P>::~pvector() {
	// Rule of three: copy constructor and assignment operator are not implemented
	write_vector();
}

template<typename T, typename P>
void pvector<T, P>::push_back(const T &element) {
	vector.push_back(element);
}

template<typename T, typename P>
void pvector<T, P>::pop_back() {
	vector.pop_back();
}

template<typename T, typename P>
int pvector<T, P>::size() {
	return vector.size();
}

template<typename T, typename P>
bool pvector<T, P>::empty() {
	return vector.empty();
}

template<typename T, typename P>
T pvector<T, P>::at(int idx) {
	return vector.at(idx);
}

template<typename T, typename P>
T pvector<T, P>::back() {
	return vector.back();
}

// Iterators

template<typename T, typename P>
typename pvector<T, P>::iterator pvector<T, P>::begin() {
	return vector.begin();
}

template<typename T, typename P>
typename pvector<T, P>::iterator pvector<T, P>::end() {
	return vector.end();
}

template<typename T, typename P>
typename pvector<T, P>::const_iterator pvector<T, P>::begin() const {
	return vector.begin();
}

template<typename T, typename P>
typename pvector<T, P>::const_iterator pvector<T, P>::end() const {
	return vector.end();
}

// private methods

template<typename T, typename P>
void pvector<T, P>::read_vector() {
	ifstream ifs(filename.c_str());

	while (ifs.good()) {
		T inp;
		persister::read(ifs, inp);
		vector.push_back(inp);
	}

	ifs.close();
}

template<typename T, typename P>
void pvector<T, P>::write_vector() {
	ofstream ofs(filename.c_str());
	for (const_iterator itr = vector.begin(); itr != vector.end(); itr++) {
		if (itr != vector.begin()) {
			// only write new line after first has been processed
			// this is to ensure that no trailing line will exist
			// at the end of the file
			ofs << "\n";
		}
		persister::write(ofs, *itr);
	}
	ofs << std::flush;
	ofs.close();
}
