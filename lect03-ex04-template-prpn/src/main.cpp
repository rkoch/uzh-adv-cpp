/*
 * main.cpp
 *
 *  Created on: 09.11.2013
 *      Author: rko
 */

#include <iostream>
#include <sstream>

#include "rpn.cpp"
#include "fraction.cpp"

#define FRACTION_TYPE

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;

int main(int pArgc, char* pArgv[]) {

#ifdef FRACTION_TYPE
	typedef fraction rpn_type;
	string save_location = "data/fraction-data.txt";
#elif defined(INT_TYPE)
	typedef int rpn_type;
	string save_location = "data/int-data.txt";
#else
	typedef float rpn_type;
	string save_location = "data/float-data.txt";
#endif

	rpn<rpn_type> calc = rpn<rpn_type>(save_location);

	string input;
	string cmd;

	while (true) {
		cout << "Command: ";
		try {
			getline(cin, input);

			std::stringstream ss(input);
			while (ss >> cmd) {
				if ((cmd.compare("n") == 0) || (cmd.compare("N") == 0)) {
					// Entering a number
					rpn_type num;
					ss >> num;
					calc.push(num);
				} else if (cmd.compare("+") == 0) {
					calc.add();
				} else if (cmd.compare("-") == 0) {
					calc.subtract();
				} else if (cmd.compare("*") == 0) {
					calc.multiply();
				} else if (cmd.compare("/") == 0) {
					calc.divide();
				} else if ((cmd.compare("d") == 0) || (cmd.compare("D") == 0)) {
					calc.pop();
				} else if ((cmd.compare("q") == 0) || (cmd.compare("Q") == 0)) {
					// Small change for pRPN: no call to exit() as exit() terminates without calling any destructors.
					return 0;
				} else {
					cerr << "Invalid command " << cmd << " entered." << endl;
				}
			}
			calc.print();
		} catch (char* &pEx) {
			cerr << "Error: " << pEx << endl;
		}
	}

}
