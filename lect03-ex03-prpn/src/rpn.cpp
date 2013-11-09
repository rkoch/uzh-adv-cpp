/*
 * rpn.cpp
 *
 *  Created on: 09.11.2013
 *      Author: rko
 */

#include <iostream>
#include "rpn.h"

rpn::rpn()
		: stack("data/rpn-data.txt") {
}

void rpn::add() {
	checkSize();

	float num2 = stack.back();
	stack.pop_back();
	float num1 = stack.back();
	stack.pop_back();

	stack.push_back(num1 + num2);
}

void rpn::subtract() {
	checkSize();

	float num2 = stack.back();
	stack.pop_back();
	float num1 = stack.back();
	stack.pop_back();

	stack.push_back(num1 - num2);
}

void rpn::multiply() {
	checkSize();

	float num2 = stack.back();
	stack.pop_back();
	float num1 = stack.back();
	stack.pop_back();

	stack.push_back(num1 * num2);
}

void rpn::divide() {
	checkSize();

	float num2 = stack.back();
	stack.pop_back();
	float num1 = stack.back();
	stack.pop_back();

	if (num2 == 0) {
		// push numbers back into the stack
		stack.push_back(num1);
		stack.push_back(num2);

		throw "Division by zero.";
	}

	stack.push_back(num1 / num2);
}

void rpn::push(float pNumber) {
	stack.push_back(pNumber);
}

void rpn::pop() {
	if (!stack.empty()) {
		stack.pop_back();
	}
}

void rpn::print() {
	int index = 1;
	for (vector<float>::const_iterator itr = stack.begin(); itr != stack.end(); itr++) {
		std::cout << index++ << ": " << *itr << std::endl;
	}
}

void rpn::checkSize() {
	if (stack.size() < 2) {
		throw "Less than two elements on the stack";
	}
}
