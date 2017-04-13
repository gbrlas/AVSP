#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int res[20][505];
#define MOD 10000

int main() {
	freopen("C.in", "rt", stdin);
	freopen("C.out", "wt", stdout);
	char line[500];
	int T;
	scanf("%d\n", &T);
	const string w = "welcome to code jam";
	const int W = w.length();
	for(int test=1; test<=T; test++) {
		cin.getline(line, sizeof(line));
		memset(res, 0, sizeof(res));
		int L = strlen(line);
		for(int j = 1; j <= L; j++) {
			res[0][j] = 1;
		}
		for(int i = 1; i <= W; i++) {
			for(int j = 1; j <= L; j++) {
				res[i][j] = (res[i][j] + res[i][j - 1]) % MOD;
				if(line[j - 1] == w[i - 1]) {
					res[i][j] = (res[i][j] + res[i - 1][j]) % MOD;
				}
			}
		}
		cout << "Case #" << test << ": " ;
		printf("%04d\n", res[W][L]);
	}
	return 0;
}