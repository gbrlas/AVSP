#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define FU(i,a,b) for(i = a; i < b; i++)
#define FD(i,a,b) for(i = a; i > b; i--)
#define FE(i,a) for(i = a.begin(); i != a.end(); i++)
#define PB(a,b) a.push_back(b)
#define SZ(a) (int)a.size()

typedef long long LL;
typedef vector<int> VI;

int n, m;
bool bad[100][100];
int a[11][1 << 10+1];
int R[1 << 11];

bool is[1 << 11][11];
bool F[1 << 11];

bool can[1 << 11+1][1 << 11+1];

int C[15];

void trans(int k, VI &A) {
	int i = 0;
	A = VI(100, 0);
	while(k) {
		if(k%2 == 1) A[i] = 1;
		else A[i] = 0;

		k /= 2;
		i++;
	}
}

int main(void) {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j, k, t, e, c;
	VI A(100, 0), B(100, 0);
	string s;

	FU(i, 0, 1 << 10) {
		F[i] = 1;
		FU(j, 0, 10) R[i] += (is[i][j] = ((i & (1 << j)) != 0));
		FU(j, 1, 9) if((is[i][j] && is[i][j-1]) || (is[i][j] && is[i][j+1])) F[i] = 0;
	}


	FU(i, 0, 1 << 10) if(F[i]) {
		FU(j, 0, 1 << 10) if(F[j]) {
			can[i][j] = 1;
			FU(k, 1, 9) if(is[i][k] && (is[j][k-1] || is[j][k+1])) {
				can[i][j] = 0;
				break;
			}
		}
	}

	scanf("%d", &t);
	FU(c, 1, t+1) {
		scanf("%d%d", &n, &m);
		FD(i, n-1, -1) {
			C[i] = 0;
			cin >> s;
			FU(j, 0, m) if(s[j] == 'x') C[i] += (1 << j);
		}

		FU(i, 0, n) FU(j, 0, 1 << m) a[i][j] = 0;

		FU(i, 0, 1 << m)
			if(F[i] && ((C[n-1] & i) == 0)) {
			a[n-1][i] = R[i];
		}

		FD(i, n-1, 0) FU(j, 0, 1 << m) 
			if(F[j] && ((j & C[i]) == 0)) {
			
			FU(k, 0, 1 << m) 
				if(F[k] && ((k & C[i-1]) == 0)) {
		

				if(can[j][k])  {
					a[i-1][k] = max(a[i-1][k], a[i][j]+R[k]);
				}
			}
		}

			int sol = 0;
			FU(i, 0, 1 << m) {
				sol = max(sol, a[0][i]);
			}

		printf("Case #%d: %d\n", c, sol);
	}

	exit(0);
}