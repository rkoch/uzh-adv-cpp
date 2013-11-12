/*
 * persister.h
 *
 *  Created on: 12.11.2013
 *      Author: rko
 */

#ifndef PERSISTER_H_
#define PERSISTER_H_

#include <fstream>

using std::ifstream;
using std::ofstream;
using std::string;

// Wouldn't it be better to just declare the structs here and implement them in persister.cpp?
// http://stackoverflow.com/questions/2578387/where-to-declare-structures-etc

template<typename T>
struct persister {
	static void read(ifstream &in, T &element) {
		in >> element;
	}

	static void write(ofstream &out, const T &element) {
		out << element;
	}
};

template<>
struct persister<string> {
	static void read(ifstream &in, string &element) {
		string res;
		std::getline(in, element);
	}

	static void write(ofstream &out, const string &element) {
		out << element;
	}
};

#endif /* PERSISTER_H_ */
