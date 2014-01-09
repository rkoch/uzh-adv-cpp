/*
 * main.cpp
 *
 *  Created on: 04.01.2014
 *      Author: rko
 */

#include <iostream>
#include <stdexcept>
#include <vector>

#include "range_iterator.h"

int main(int argc, const char **argv) {
	std::vector<int> vec;
	std::vector<double> vec2;

	for (int i = 0; i < 5; i++) {
		vec.push_back(std::rand());
		vec2.push_back(std::rand() + 0.03);
	}

	range_iterator<std::vector<int>::iterator> itr(vec.begin(), vec.end());

	try {
		for (int i = 0; i < 5; i++) {
			std::cout << *itr << std::endl;
			++itr;
		}
	} catch (const std::exception& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	try {
		for (int i = 0; i < 5; i++) {
			std::cout << *itr << std::endl;
			--itr;
		}
	} catch (const std::exception& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	range_iterator<std::vector<double>::iterator> itr2(vec2.begin(), vec2.end());

	try {
		for (int i = 0; i < 5; i++) {
			std::cout << *itr2 << std::endl;
			++itr2;
		}
	} catch (const std::exception& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	try {
		for (int i = 0; i < 5; i++) {
			std::cout << *itr2 << std::endl;
			--itr2;
		}
	} catch (const std::exception& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}
}
