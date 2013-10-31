/*
 * rpn.h
 *
 *  Created on: 30.10.2013
 *      Author: rko
 */

#ifndef RPN_H_
#define RPN_H_

#include <vector>

using std::vector;

class rpn {

public:

	rpn();

	void add();
	void subtract();
	void divide();
	void multiply();

	void push(float pNumber);
	void pop();

	void print();

private:
	vector<float> stack;

	void checkSize();
};

#endif /* RPN_H_ */
