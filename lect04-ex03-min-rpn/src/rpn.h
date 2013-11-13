/*
 * rpn.h
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#ifndef RPN_H_
#define RPN_H_

#include "pvector.cpp"

template<typename T>
class rpn {

public:

	rpn(std::string fname);

	void add();
	void subtract();
	void divide();
	void multiply();

	void organize_min();

	void push(T number);
	void pop();

	void print();

private:
	pvector<T> stack;
	T current_min;

	void check_min(const T &element);

	void checkSize();
};

#endif /* RPN_H_ */
