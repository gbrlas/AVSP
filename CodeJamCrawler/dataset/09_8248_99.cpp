#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<string> mas;

int main() {
	freopen("A.in", "rt", stdin);
	freopen("A.out", "wt", stdout);

	int L, N , D;	
	cin >> L >> D >> N;
	string word;
	for(int i = 0; i < D; i++) {
		cin >> word;
		mas.push_back(word);
	}
	vector<string> v;
	for(int i =1; i <= N; i++) {
		cin >> word;
		v.clear();
		int pos = 0;
		string cur;
		int open = 0;
		for(int  j = 0; j < word.length(); j++) {
			if(word[j] == '(') {
				cur.clear();
				open++;
			}
			else if (word[j] == ')') {
				v.push_back(cur);
				open--;
			} else {
				if(open) cur += word[j]; 
				else v.push_back(string() + word[j]);
			}
		}
		cout << "Case #" << i << ": ";
		int res = 0;
		if(v.size() == L){
		for(int j = 0; j < mas.size(); j++) {
			bool ok = 1;
			for(int k = 0; ok && k < L; k++) {
				if(v[k].find(mas[j][k]) == string::npos) {
					ok = 0;
				}
			}
			res += ok;
		}
		}
		cout << res << endl;
	}
	return 0;
}