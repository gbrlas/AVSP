#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#define MAX 5005

using namespace std;

struct letras{
	bool pode[30];
};

int L, D, N;
string dic[MAX];
letras l[20];

int main () {
	scanf ("%d%d%d", &L, &D, &N);
	for (int i = 0; i < D; i++)
		cin >> dic[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++)
			for (int k = 0; k < 30; k++)
				l[j].pode[k] = 0;
		string s;
		cin >> s;
		int p = 0;
		for (int j = 0; j < L; j++) {
			if (s[p] == '(') {
				p++;
				for (; s[p] != ')'; p++)
					l[j].pode[s[p]-'a'] = 1;
			}
			else
				l[j].pode[s[p]-'a'] = 1;
			p++;
		}
		bool br = 0;
		int cnt = 0;
		for (int j = 0; j < D; j++) {
			br = 0;
			for (int k = 0; k < L; k++)
				if (l[k].pode[dic[j][k]-'a'] == false) {
					br = true;
					break;
				}
			if (!br)
				cnt++;
		}
		printf ("Case #%d: %d\n", i+1, cnt);
	}
	return 0;
}
