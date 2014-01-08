/*
 * rpn.h
 *
 *  Created on: 09.11.2013
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

	void push(T number);
	void pop();

	void format(int type);

	void print();

private:
	pvector<T> stack;
	int formatType;

	void checkSize();

};

#endif /* RPN_H_ */
