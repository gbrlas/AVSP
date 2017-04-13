#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int decode(string code, vector<string>& text) {
	int i = 0;

	while (i < code.length()) {
		if (code[i] == '(') {
			string digit;
			i++;
			while (code[i] != ')') {
				digit.push_back(code[i++]);
			}
			i++;
			text.push_back(digit);
		} else {
			string s;
			s.insert(s.begin(), code[i++]);
			text.push_back(s);
		}
	}

	return 0;
}

bool check(string word, string code) {
	vector<string> text;
	int i;

	decode(code, text);
	for (i = 0; i < word.length(); i++) {
		if (strchr(text[i].data(), word[i]) == NULL) {
			return false;
		}
	}
	return true;
}


int check_lang(vector<string>& lang, string code) {
	int ret = 0;

	for (int i = 0; i < lang.size(); i++) {
		if (check(lang[i], code)) {
			ret++;
		}
	}
	return ret;
}


int main(int argc, char* argv[]) {
	int L;
	int D;
	int N;
	int i;
	vector<string> lang;

	cin >> L >> D >> N;
	for (i = 0; i < D; i++) {
		string s;
		cin >> s;
		lang.push_back(s);
	}
	for (i = 0; i < N; i++) {
		string code;
		cin >> code;
		printf("Case #%d: %d\n", i+1, check_lang(lang, code));
	}
	return 0;
}


