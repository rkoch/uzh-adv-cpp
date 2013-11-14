/*
 * rpn.cpp
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#include <iostream>
#include <algorithm>

#include "rpn.h"

template<typename T>
rpn<T>::rpn(std::string fname)
		: stack(fname) {
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
void rpn<T>::organize_min() {
	T smallestElement = stack.front();

  	std::for_each(stack.begin(), stack.end(), [&](T c){if (c < smallestElement) smallestElement = c;});

  	stack.push_back(smallestElement);
}

template<typename T>
void rpn<T>::check_min(const T &element) {
	if (element < current_min) {
		current_min = element;
	}
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
void rpn<T>::print() {
	int index = 1;
	for (typename vector<T>::const_iterator itr = stack.begin(); itr != stack.end(); itr++) {
		std::cout << index++ << ": " << *itr << "\n";
	}
	std::cout << std::flush;
}

template<typename T>
void rpn<T>::checkSize() {
	if (stack.size() < 2) {
		throw "Less than two elements on the stack";
	}
}
