/*
 * rpn.cpp
 *
 *  Created on: 09.11.2013
 *      Author: rko
 */

#include <iostream>

#include "manipulator.cc"
#include "rpn.h"

template<typename T>
rpn<T>::rpn(std::string fname)
		: stack(fname), formatType(0) {
}

template<typename T>
void rpn<T>::add() {
	checkSize();

	T num2 = stack.back();
	stack.pop_back();
	T num1 = stack.back();
	stack.pop_back();

	stack.push_back(num1 + num2);
}

template<typename T>
void rpn<T>::subtract() {
	checkSize();

	T num2 = stack.back();
	stack.pop_back();
	T num1 = stack.back();
	stack.pop_back();

	stack.push_back(num1 - num2);
}

template<typename T>
void rpn<T>::multiply() {
	checkSize();

	T num2 = stack.back();
	stack.pop_back();
	T num1 = stack.back();
	stack.pop_back();

	stack.push_back(num1 * num2);
}

template<typename T>
void rpn<T>::divide() {
	checkSize();

	T num2 = stack.back();
	stack.pop_back();
	T num1 = stack.back();
	stack.pop_back();

	if (num2 == 0) {
		// push numbers back into the stack
		stack.push_back(num1);
		stack.push_back(num2);

		throw "Division by zero.";
	}

	stack.push_back(num1 / num2);
}

template<typename T>
void rpn<T>::push(T pNumber) {
	stack.push_back(pNumber);
}

template<typename T>
void rpn<T>::pop() {
	if (!stack.empty()) {
		stack.pop_back();
	}
}

template<typename T>
void rpn<T>::format(int type) {
	formatType = type;
}

template<typename T>
void rpn<T>::print() {
	if (formatType == 1) {
		std::cout << io_manipulator::scientific;
	} else if (formatType == 2) {
		std::cout << io_manipulator::float_prec;
	} else {
		std::cout << io_manipulator::normal;
	}

	int index = 1;
	for (typename vector<T>::const_iterator itr = stack.begin(); itr != stack.end(); itr++) {
		std::cout << index++ << ": " << *itr << "\n";
	}
	std::cout << io_manipulator::normal << std::flush; // flush and reset format
}

template<typename T>
void rpn<T>::checkSize() {
	if (stack.size() < 2) {
		throw "Less than two elements on the stack";
	}
}
