/*
 * pset.h
 *
 *  Created on: 12.11.2013
 *      Author: rko
 */

#ifndef PSET_H_
#define PSET_H_

#include <iostream>
#include <set>

#include "persister.h"

using std::string;
using std::set;

template<typename T, typename P = persister<T> >
class pset {

public:
	typedef P persister;
	typedef typename set<T>::iterator iterator;
	typedef typename set<T>::const_iterator const_iterator;

	pset(string fname);
	~pset();

	iterator find(const T &element);
	void insert(const T &element);
	void erase(iterator position);
	int size();
	bool empty();

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

private:
	string filename;
	set<T> set;

	void read_set();
	void write_set();

};

#endif /* PSET_H_ */
