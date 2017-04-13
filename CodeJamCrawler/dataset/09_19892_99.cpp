/*
 * alien.cpp
 *
 *  Created on: 03/09/2009
 *      Author: Victor
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

int L, D, N;
set<string> dic;
set<string> temp;
int total;
string expr;

void nextToken(string str, int index) {
	if (str.size() == (size_t) L) {
		if (dic.find(str) != dic.end()) total++;
		return;
	}

	if (temp.find(str) == temp.end()) return;

	if (isalpha(expr[index])) {
		str += expr[index];
		nextToken(str, index+1);
	} else {
		index++;
		vector<char> letras;
		while(isalpha(expr[index])){
			letras.push_back(expr[index]);
			index++;
		}
		index++;

		string tmp;
		for (int i = 0; i < (int) letras.size(); i++) {
			tmp = str + letras[i];
			nextToken(string(tmp), index);
		}
	}
}

int main() {
	cin >> L >> D >> N;
	getline(cin, expr);

	dic.clear();
	temp.clear();

	temp.insert("");

	for (int i = 0; i < D; i++) {
		getline(cin, expr);
		dic.insert(expr);

		for (int j = 1; j <= (int) expr.size(); j++) {
			temp.insert(expr.substr(0, j));
		}
	}

	for (int i = 0; i < N; i++) {
		getline(cin, expr);
		total = 0;
		nextToken("", 0);
		cout << "Case #" << i+1 << ": " << total << endl;
	}

	return (0);
}
