#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
int passibilities(vector< string > words, vector< string > patterns, int index) {
	if (index == patterns.size()) {
		/*
		for (int i = 0; i < words.size(); i++)
			cout << words[i] << endl;
		*/
		return words.size();
	}
	int p = 0;
	for (int i = 0; i < patterns[index].length(); i++) {
		vector< string > _words;
		for (int j = 0; j < words.size(); j++) {
			if (patterns[index][i] == words[j][index])
				_words.push_back(words[j]);
		}
		if (!_words.empty()) {
			p += passibilities(_words, patterns, index + 1);
		}
	}
	return p;
}
int main(int argc, char **argv) {
	int L, D, N;
	ifstream fin(argv[1]);
	fin >> L >> D >> N;
	vector< string > words;
	for (int d = 0; d < D; d++) {
		string tmp;
		fin >> tmp;
		words.push_back(tmp);
	}
	for (int n = 0; n < N; n++) {
		string tmp;
		fin >> tmp;
		vector< string > patterns;
		bool parenthesis;
		string buffer;
		for (int i = 0; i < tmp.length(); i++) {
			if (tmp[i] == '(') {
				parenthesis = true;
			}
			else if (tmp[i] == ')') {
				parenthesis = false;
				patterns.push_back(buffer);
				buffer.clear();
			}
			else if (parenthesis) {
				buffer += tmp[i];
			}
			else {
				buffer += tmp[i];
				patterns.push_back(buffer);
				buffer.clear();
			}
		}
		/*
		for (int i = 0; i < patterns.size(); i++) {
			for (int j = 0; j < patterns[i].length(); j++)
				cout << patterns[i][j];
			cout << " ";
		}
		cout << endl;
		*/
		int p = passibilities(words, patterns, 0);
		cout << "Case #" << n + 1 << ": " << p << endl;
	}
	return 0;
}
