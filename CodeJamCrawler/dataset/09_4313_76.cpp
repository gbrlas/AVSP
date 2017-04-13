#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int L, D, N, i;
	
	ifstream in("A-large.in");
	ofstream out("A-large.out");
	in >> L >> D >> N;
	
	string* wordlist = new string[D];
	string pattern;
	string ignore;
	int* result = new int[N];
	
	getline(in, ignore);
	for (i = 0; i < D; i++) {
		getline(in, wordlist[i]);
	}
	
	for (i = 0; i < N; i++) {
		int u, v;
		getline(in, pattern);
		string* plist = new string[L];
		int index = 0;
		int pi = 0;
		while (index < pattern.size()) {
			if (pattern.at(index) != '(' && pattern.at(index) != ')') {
				plist[pi] = pattern.substr(index, 1);
				pi++;
				index++;
				continue;
			}
			if (pattern.at(index) == '(') {
				index++;
				int start = index;
				while (pattern.at(index) != ')') index++;
				plist[pi] = pattern.substr(start, index - start);
				pi++;
				index++;
			}
		}
		result[i] = 0;
		for (u = 0; u < D; u++) {
			bool flag = true;
			string word = wordlist[u];
			for (v = 0; v < L; v++) {
				char c = word.at(v);
				if (plist[v].find(c) == string::npos) {
					flag = false;
					break;
				}
			}
			if (flag)
				result[i]++;
		}
		delete plist;
	}
	
	for (i = 0; i < N; i++) {
		out << "Case #" << i+1 << ": " << result[i] << endl;
	}
	
	delete wordlist;
	delete result;
	
	return 0;
}
