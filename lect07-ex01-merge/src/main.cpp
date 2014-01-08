/*
 * main.cpp
 *
 *  Created on: 04.01.2014
 *      Author: rko
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>

#include "merge_util.h"

using std::vector;
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
	const int max = 20;

	int arr1[] = { 3, 4, 5, 6, 7 };

	vector<int> vec1, vec2;
	for (int i = 0; i < 10; i++) {
		vec1.push_back(rand() % max);
		vec2.push_back(rand() % max);
	}

	// Merge vectors
	cout << "Vector test" << "\n";
	cout << "v1: ";
	std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(cout, " "));
	cout << "\n";
	cout << "v2: ";
	std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(cout, " "));
	cout << "\n";
	cout << "merged: ";
	nomnom::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::ostream_iterator<int>(cout, " "));
	cout << "\n" << endl;

	// Mixed test
	cout << "Mixed (Vector and arrays test)" << "\n";
	cout << "a1: ";
	std::copy(arr1, arr1 + 5, std::ostream_iterator<int>(cout, " "));
	cout << "\n";
	cout << "v1: ";
	std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(cout, " "));
	cout << "\n";
	cout << "merged: ";
	nomnom::merge(arr1, arr1 + 5, vec1.begin(), vec1.end(), std::ostream_iterator<int>(cout, " "));
	cout << "\n" << endl;

	return 0;
}
