/*
 * main.cpp
 *
 *  Created on: 03-Sep-2009
 *      Author: samkit
 */

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
#include <list>
#include <vector>
#include <regex.h>

using namespace std;

void readFile(const string &inFileName, vector<string> &words, vector<string> &patterns, int &numberOfLowerCase)
{
	ifstream inFile(inFileName.c_str());

	int L, D, N;
	inFile >> L >> D >> N;

	numberOfLowerCase = L;
//	cout << L << " " << D << " " << N << endl;

	string line;
	int i = 0;
	while(++i <= D && inFile >> line) {
		words.push_back(line);
	}

	i = 0;
	while(++i <= N && inFile >> line) {
		patterns.push_back(line);
	}
	return;
}

void print(const string &line)
{
	cout << line << endl;
}

bool extractLetters(const string &pattern, vector<string> &letters)
{
	unsigned int startPos = 0;
	unsigned int endPos = 0;

	while(true) {
		endPos = pattern.find('(', startPos);

		if(startPos < pattern.length() && pattern[startPos] != '(') {
//			cout << pattern.substr(startPos, endPos - startPos) << endl;
			if(endPos == string::npos) {
				letters.push_back(pattern.substr(startPos, pattern.length() - startPos));
			}
			else {
				letters.push_back(pattern.substr(startPos, endPos - startPos));
			}
		}
		if(endPos == string::npos) break;

		startPos = endPos;	// CHECKME: Patterns which are inside parenthesis will be prefixed by '('.
		endPos = pattern.find(')', startPos);	// FIXME: Assuming that '(' will always close ')'.
//		cout << pattern.substr(startPos, endPos - startPos) << endl;
		letters.push_back(pattern.substr(startPos, endPos - startPos));
		startPos = endPos + 1;
	}
	return true;
}

//int match(vector<string> &letters, const int &numberOfLowerCase, set<string> &wordSet, const int &pos, string &word, int &returnValue)
//{
//	string pattern;
//
//	if(pos < letters.size()) {
//		pattern = letters[pos];
//	}
//
////	cout << "New call" << endl;
//	if(pattern[0] == '(') {
//		for(int j = 1; j < pattern.length(); ++j) {
////			cout << "Here  " << word << endl;
//			int index = word.length();
//			word.append(1, pattern[j]);
////			cout << "Here2 " << word << endl;
//			match(letters, numberOfLowerCase, wordSet, pos + 1, word, returnValue);
//			word.erase(index);
//		}
//	}
//	else {
//		word.append(pattern);
//	}
//
//	if(wordSet.find(word) != wordSet.end()) {
////		cout << "++" << word << endl;
//		return ++returnValue;
//	}
//	return 0;
//}

int getMaxCombinations(vector<string> letters)
{
	int i = 1;

	for(vector<string>::const_iterator j = letters.begin(); j != letters.end(); ++j) {
		if((*j)[0] == '(') {
			i *= (*j).length() - 1;		// CHECKME: '- 1' to exclude '(' from length.
		}
	}
	return i;
}

bool isOpeningBracket(const char letter)
{
	if(letter == '(')
		return true;
	return false;
}

bool isClosingBracket(const char letter)
{
	if(letter == ')')
		return true;
	return false;
}

int match(string pattern, set<string> &wordSet, const int &maxCombinations)
{
//	cout << "Input Pattern: " << pattern << endl;
	regex_t compiled_regex;

	replace_if(pattern.begin(), pattern.end(), isOpeningBracket, '[');
	replace_if(pattern.begin(), pattern.end(), isClosingBracket, ']');

//	cout << "Modified input pattern: " << pattern << endl;

	if(regcomp(&compiled_regex, pattern.c_str(), REG_EXTENDED) != 0) {
		cout << "Error compiled regex: " << pattern << endl;
		return 0;
	}

	regmatch_t matches[maxCombinations];
	int totalMatches = 0;

	for(set<string>::const_iterator i = wordSet.begin(); i != wordSet.end(); ++i) {
		if(regexec(&compiled_regex, (*i).c_str(), maxCombinations, matches, REG_EXTENDED) != 0) {
			continue;
		}
		int j;
		for(j = 0; j < maxCombinations; ++j) {
//			cout << "match at " << j << " " << matches[j].rm_so << " " << matches[j].rm_eo << endl;
			if(matches[j].rm_eo == -1) {
				break;
			}
		}
		totalMatches += j;

	}
	regfree(&compiled_regex);

	return totalMatches;
}

int matchPattern(const string &pattern, const int &numberOfLowerCase, vector<string> &words, ofstream &outFile)
{
//	cout << "Input Pattern " << pattern << " ";

	static int caseCount = 1;
	vector<string> letters;
	extractLetters(pattern, letters);

//	cout << letters.size() << " " << numberOfLowerCase << endl;
//	for_each(letters.begin(), letters.end(), print);

//	for_each(words.begin(), words.end(), print);

	set<string> wordSet;
	for(vector<string>::const_iterator i = words.begin(); i != words.end(); ++i) {
		wordSet.insert(*i);
	}

	string temp;
	int totalMatch = 0;
//	match(letters, numberOfLowerCase, wordSet, 0, temp, totalMatch);

//	totalMatch = match(pattern, wordSet, getMaxCombinations(letters));
	totalMatch = match(pattern, wordSet, 50000);

	outFile << "Case #" << caseCount++ << ": " << totalMatch << endl;
//	return totalMatch;

	return 0;
}

int main(int argc, char *argv[])
{
//	string inFileName(argv[1]);
	vector<string> words;
	vector<string> patterns;
	int numberOfLowerCase;

	ofstream outFile("output");

	readFile("input_small", words, patterns, numberOfLowerCase);

//	cout << numberOfLowerCase << endl;
//	for_each(words.begin(), words.end(), print);

//	for_each(patterns.begin(), patterns.end(), print);

	for(vector<string>::const_iterator i = patterns.begin(); i != patterns.end(); ++i) {
		matchPattern(*i, numberOfLowerCase, words, outFile);
	}
	outFile.close();

//	matchPatttern("(ab)(bc)(ca)");

	return 0;
}
