#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cassert>

#include <iostream>
#include <sstream>
#include <iterator>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <list>
#include <complex>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

const double PI = atan(1.0) * 4;
const int inf = 1000000009;
const double eps = 1e-8;

#define F0(i, n) for (int i = 0; i < (n); ++i)
#define F1(i, n) for (int i = 1; i <= (n); ++i)
#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

using namespace std;

int M, N;
ll max_cnt, cnt;
int seat[100][100];

bool isIn(int r, int c) {
    return (0 <= r && r < M && 0 <= c && c < N);
}

bool isOk(int r, int c) {
    if (!isIn(r, c)) return false;
    if (isIn(r-1, c-1) && seat[r-1][c-1] == 1) return false;
    if (isIn(r-1, c+1) && seat[r-1][c+1] == 1) return false;
    if (isIn(r, c-1) && seat[r][c-1] == 1) return false;
    if (isIn(r, c+1) && seat[r][c+1] == 1) return false;
    return true;
}

void dfs(int r, int c) {    
    if (r > M-1) {
	max_cnt = max(max_cnt, cnt);
#if 0
	F0(i, M){
	    F0(j, N) {
		cout << (seat[i][j] == -1 ? 'x' : (seat[i][j] == 1 ? 'o' : '.'));
	    }
	    cout << endl;
	}
#endif
	return;
    }
    
    int remain = 0;
    if (N % 2 == 0) {
	remain += (M-1-r) * N / 2;	
    } else {
	remain += (M-1-r) * (N / 2 + 1);
    }

    if ((N-c) % 2 == 0) {
	remain += (N-c) / 2;	
    } else {
	remain += (N-c) / 2 + 1;
    }
    if (cnt + remain < max_cnt) return;

    if (isIn(r, c) && seat[r][c] == 0 && isOk(r, c)) {
	seat[r][c] = 1;
	cnt++;
	
	if (c+2 < N) { // same row
	    dfs(r, c + 2);	
	} else {
	    dfs(r + 1, 0);
	}

	seat[r][c] = 0;
	cnt--;
    }     
    
    dfs(r + (c+1) / N, (c+1) % N);
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    // TODO: check long long carefully.
    for (int cas = 1; cas <= caseN; ++cas) {
	printf("Case #%d: ", cas);
	cin >> M >> N;

	char ch;
	F0(i, M)
	    F0(j, N) {
		cin >> ch;
		if (ch == '.') seat[i][j] = 0;
		else if (ch == 'x') seat[i][j] = -1;
	    }
#if 0
	F0(i, M){
	    F0(j, N) {
		cout << (seat[i][j] == -1 ? 'x' : '.');
	    }
	    cout << endl;
	}
#endif

	max_cnt = cnt = 0;
	dfs(0, 0);
	cout << max_cnt;

	printf("\n");
    }

    return 0;
}
