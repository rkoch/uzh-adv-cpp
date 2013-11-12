/*
 * pvector.h
 *
 *  Created on: 12.11.2013
 *      Author: rko
 */

#ifndef PVECTOR_H_
#define PVECTOR_H_

#include <iostream>
#include <vector>

using std::string;
using std::vector;

// traits

template<typename T>
struct persister;

template<>
struct persister<string> ;

// pvector class

template<typename T, typename P = persister<T> >
class pvector {

public:
	typedef P persister;
	typedef typename vector<T>::iterator iterator;
	typedef typename vector<T>::const_iterator const_iterator;

	pvector(string fname);
	~pvector();

	void push_back(const T &element);
	void pop_back();
	int size();
	bool empty();
	T at(int idx);
	T back();

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

private:
	string filename;
	vector<T> vector;

	void read_vector();
	void write_vector();

};

#endif /* PVECTOR_H_ */
