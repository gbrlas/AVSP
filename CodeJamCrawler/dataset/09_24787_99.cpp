#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#define MAX 505
#define MOD 10000

using namespace std;

string linha;
int pd[MAX][30];
string seek = "welcome to code jam";

int f (int p, int in) {
	if (p >= (int)linha.size())
		return 0;
	if (in == (int)seek.size() - 1) {
		if (linha[p] == seek[in])
			return 1;
		return 0;
	}
	if (pd[p][in] != -1)
		return pd[p][in];
	int &ret = pd[p][in];
	ret = 0;
	if (seek[in] != linha[p])
		return ret;
	for (int i = p + 1; i < (int)linha.size(); i++)
		ret = (ret + f (i, in + 1)) % MOD;
	return ret;
}

int main () {
	int N, tes = 1;
	scanf ("%d ", &N);
	for (; N > 0; N--) {
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < 30; j++)
				pd[i][j] = -1;
		getline (cin, linha);
		int resp = 0;
		for (int i = 0; i < (int)linha.size(); i++)
			resp = (resp + f (i, 0)) % MOD;
		printf ("Case #%d: ", tes++);
		if (resp < 1000)
			printf ("0");
		if (resp < 100)
			printf ("0");
		if (resp < 10)
			printf ("0");
		printf ("%d\n", resp);
	}
	return 0;
}

