/*
 * main.cpp
 *
 *  Created on: 03-Sep-2009
 *      Author: samkit
 */

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int countMatch(const string &line, const string &pattern, size_t index, size_t from, unsigned long long &matches)
{
	if(index == pattern.length()) {
		++matches;
		return 0;
	}

	for(size_t i = from; i < line.length(); ++i) {
		if(line[i] != pattern[index])
			continue;

		countMatch(line, pattern, index + 1, i + 1, matches);
	}
	return 0;
}

int main()
{
	string pattern = "welcome to code jam";
	string line;

	ifstream inFile("input");
	ofstream outFile("output");

	int T = 0;

	inFile >> T;

	unsigned long long matches;

	getline(inFile, line);

	for(int i = 0; i < T; ++i) {
		getline(inFile, line);
		matches = 0;
		countMatch(line, pattern, 0, 0, matches);

		cout << "Case #" << i + 1 << ": ";
		cout.width(4);
		cout.fill('0');
		cout << right << matches % 10000 << endl;

		outFile << "Case #" << i + 1 << ": ";
		outFile.width(4);
		outFile.fill('0');
		outFile << right << matches % 10000 << endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}
