/*
 * pset.cpp
 *
 *  Created on: 12.11.2013
 *      Author: rko
 */

#include <fstream>
#include "pset.h"

using std::ifstream;
using std::ofstream;
using std::string;

template<typename T, typename P>
pset<T, P>::pset(string fname)
		: filename(fname), set() {
	read_set();
}

template<typename T, typename P>
pset<T, P>::~pset() {
	// Rule of three: copy constructor and assignment operator are not implemented
	write_set();
}

template<typename T, typename P>
void pset<T, P>::insert(const T &element) {
	set.insert(element);
}

template<typename T, typename P>
void pset<T, P>::erase(iterator position) {
	set.erase(position);
}

template<typename T, typename P>
int pset<T, P>::size() {
	return set.size();
}

template<typename T, typename P>
bool pset<T, P>::empty() {
	return set.empty();
}

// Iterators

template<typename T, typename P>
typename pset<T, P>::iterator pset<T, P>::begin() {
	return set.begin();
}

template<typename T, typename P>
typename pset<T, P>::iterator pset<T, P>::end() {
	return set.end();
}

template<typename T, typename P>
typename pset<T, P>::const_iterator pset<T, P>::begin() const {
	return set.begin();
}

template<typename T, typename P>
typename pset<T, P>::const_iterator pset<T, P>::end() const {
	return set.end();
}

// private methods

template<typename T, typename P>
void pset<T, P>::read_set() {
	ifstream ifs(filename.c_str());

	while (ifs.good()) {
		T inp;
		persister::read(ifs, inp);
		set.insert(inp);
	}

	ifs.close();
}

template<typename T, typename P>
void pset<T, P>::write_set() {
	ofstream ofs(filename.c_str());
	for (const_iterator itr = set.begin(); itr != set.end(); itr++) {
		if (itr != set.begin()) {
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
