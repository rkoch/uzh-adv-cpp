/*
 * pvector.h
 *
 *  Created on: 31.10.2013
 *      Author: rko
 */

#ifndef PVECTOR_H_
#define PVECTOR_H_

#include <iostream>
#include <vector>

using std::string;
using std::vector;

template<typename T>
class pvector {

public:
	pvector(string fname);
	~pvector();

	void push_back(const T &element);
	void pop_back();
	int size();
	T at(int idx);

private:
	string filename;
	vector<T> vector;
};

#endif /* PVECTOR_H_ */
