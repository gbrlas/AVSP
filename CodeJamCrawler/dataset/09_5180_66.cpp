//============================================================================
// Name        : StringTest.cpp
// Author      : Thomasan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

bool belong(char c, string str){
	for(unsigned int i=0; i<str.length(); i++){
		if(c == str.at(i))
			return true;
	}
	return false;
}

bool match(string word, string pattern[]){

	for(unsigned int i=0; i<word.length(); i++){
		if(!belong(word.at(i), pattern[i]))
			return false;
	}
	return true;
}

void parse_pattern(string line, string *pattern){
	if(pattern == NULL){
		cerr << "parse_pattern error\n";
		return;
	}

	bool in = false;
	int j = 0;
	for(int i=0; i<line.length(); i++){
		if(!in){
			if(line.at(i) == '('){
				in = true;
				continue;
			}
			if (line.at(i) != '('){
				pattern[j] += line.at(i);
				j++;
				continue;
			}
		}
		if(in){
			if(line.at(i) == ')'){
				in = false;
				j++;
				continue;
			}
			if (line.at(i) != ')'){
				pattern[j] += line.at(i);
				continue;
			}
		}
	}
}

void clear(string array[], int n){
	for(int i=0; i<n; i++)
		array[i] = "";
}

int main() {
	ifstream in("A-small-practice.in");
	string line;
	getline(in, line);
	int L, D, N;
	istringstream iss(line);
	iss >> L >> D >> N;
	//cout << L<<D<<N<<endl;
	string *words = new string[D];
	for(int d=0; d<D; d++){
		getline(in, words[d]);
	}
	string *pattern = new string[L];
	int count;
	for(int n=0; n<N; n++){
		clear(pattern, L);
		count = 0;
		getline(in, line);
		parse_pattern(line, pattern);
		for(int i=0; i<D; i++){
			if(match(words[i], pattern))
				count++;
		}
		cout << "Case #" << n+1 << ": " << count << endl;
	}
	delete[] words;
	delete[] pattern;
	return 0;
}
