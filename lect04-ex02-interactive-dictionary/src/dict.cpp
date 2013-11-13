/*
 * dict.cpp
 *
 *  Created on: 30.10.2013
 *      Author: rko
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "pvector.cpp"
#include "pset.cpp"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::set;
using std::string;
using std::ifstream;
using std::stringstream;

#define DICT "extended-dict"

void writeFileNotFoundError(const char* pFile) {
	cerr << DICT << ": " << pFile << ": No such file or directory" << endl;
}

int main(int pArgc, const char* pArgv[]) {

	// Validate input arguments
	if (pArgc < 3) {
		cerr << "usage: " << DICT << " [dict.txt] [text.txt]" << endl;
		exit(EXIT_FAILURE);
	}

	// Check if dictionary exists
	ifstream dfs(pArgv[1]);
	if (!dfs) {
		writeFileNotFoundError(pArgv[1]);
		exit(EXIT_FAILURE);
	}
	dfs.close();

	// Check if text file exists
	ifstream tfs(pArgv[2]);
	if (!tfs) {
		writeFileNotFoundError(pArgv[2]);
		exit(EXIT_FAILURE);
	}
	tfs.close();

	// Open dictionary
	pset<string> dict(pArgv[1]);

	// Open text file
	pvector<string> text(pArgv[2]);

	stringstream correct_ss;
	for (pvector<string>::iterator itr = text.begin(); itr != text.end(); itr++) {
		// This is for each line in the pvector
		stringstream ss(*itr);
		string current_word;
		while (ss >> current_word) {
			// Replace some special chars
			char specialChars[] = ".,!?;";
			for (unsigned int i = 0; i < strlen(specialChars); i++) {
				current_word.erase(std::remove(current_word.begin(), current_word.end(), specialChars[i]), current_word.end());
			}

			// Search word in dictionary
			if (dict.find(current_word) == dict.end()) {
				// Word not found
				cout << "Word \"" << current_word << "\" not found in the dictionary. Would you like to (a)dd it to the dictionary or (c)orrect it or (I)gnore it?" << endl;
				char sel;
				cin >> sel;
				if (sel == 'a') {
					// Add to dictionary
					dict.insert(current_word);
				} else if (sel == 'c') {
					// correct it
					cout << "Enter the correct spelling:" << endl;
					cin >> current_word;
				}
			}
			// Write word to corrected line
			correct_ss << current_word << " ";
		}

		// Save line
		correct_ss << "\n";
	}

	cout << "Corrected text:\n";
	cout << correct_ss.str() << endl;

}
