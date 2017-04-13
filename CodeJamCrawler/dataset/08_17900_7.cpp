#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <map>
#include <set>

using namespace std;

#define foreach(i, s, v) for(int i = (s); i < int((v).size()); ++i)
#define forX(i, m) for(typeof((m).begin()) i = (m).begin(); i != (m).end(); ++i)

int N;
int A[10000], B[10000], C[10000];
map <string, int> M;
short v[10000][301];
int COLS;
int allowed[3];
short mem[10100];

int solve(int pos) {
	if(pos == 10000)
		return 0;
	if(mem[pos] != -1)
		return mem[pos];
	int result = -1, t;
	for(int j = 0; j < 3; ++j) {
		int i = allowed[j];
		if(v[pos][i] == -1)
			continue;
		t = solve(v[pos][i]);
		if(t == -1)
			continue;
		if(result == -1 || result > (t + 1))
			result = t + 1;
	}
	return mem[pos] = result;
}

int main() {
	int T;
	char col[16];
	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		memset(v, 0xff, sizeof(v));
		M.clear();
		int cur = 0;
		scanf("%d", &N);
		string s;
		for(int i = 0; i < N; ++i) {
			scanf("%s%d%d", &col, &A[i], &B[i]);
			--A[i], --B[i];
			s = col;
			if(!M.count(s))
				M[s] = cur++;
			C[i] = M[s];
		}
		for(int i = 0; i < N; ++i)
			for(int j = A[i]; j <= B[i]; ++j)
				if(v[j][C[i]] < B[i] + 1)
					v[j][C[i]] = B[i] + 1;
		COLS = M.size();
		int result = -1;
		for(int i = 0; i < COLS; ++i)
			for(int j = i; j < COLS; ++j)
				for(int k = j; k < COLS; ++k) {
					memset(mem, 0xff, sizeof(mem));
					allowed[0] = i;
					allowed[1] = j;
					allowed[2] = k;
					int res = solve(0);
					if(res == -1)
						continue;
					if(result == -1 || result > res)
						result = res;
				}
		if(result == -1)
			printf("Case #%d: IMPOSSIBLE\n", t + 1);
		else
			printf("Case #%d: %d\n", t + 1, result);
	}
	return 0;
}
