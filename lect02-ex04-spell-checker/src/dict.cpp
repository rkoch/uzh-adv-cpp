/*
 * dict.cpp
 *
 *  Created on: 30.10.2013
 *      Author: rko
 */

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using std::cout;
using std::cerr;
using std::endl;
using std::set;
using std::string;
using std::ifstream;

#define DICT "dict"

void printFileNotFound(const char* pFile) {
	cerr << DICT << ": " << pFile << ": No such file or directory" << endl;
}

int main(int pArgc, const char* pArgv[]) {

	// Validate input arguments
	if (pArgc < 3) {
		cerr << "usage: " << DICT << " [dict.txt] [text.txt]" << endl;
		exit(EXIT_FAILURE);
	}

	// Read dictionary
	set<string> dictionary;
	ifstream dfs(pArgv[1]);
	if (!dfs) {
		printFileNotFound(pArgv[1]);
	}
	while (dfs.good()) {
		string ent;
		dfs >> ent;
		dictionary.insert(ent);
	}
	dfs.close();

	// Spell check text file
	ifstream tfs(pArgv[2]);
	if (!tfs) {
		printFileNotFound(pArgv[2]);
	}
	while (tfs.good()) {
		string word;
		tfs >> word;

		// Replace some special chars
		char specialChars[] = ".,!?;";
		for (unsigned int i = 0; i < strlen(specialChars); i++) {
			word.erase(std::remove(word.begin(), word.end(), specialChars[i]), word.end());
		}

		if (dictionary.find(word) == dictionary.end()) {
			cout << word << endl;
		}
	}

}
