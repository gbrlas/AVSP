#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <numeric>

using namespace std;   

#define SZ(a) ((int)(a).size())
#define SQR(a) ((a)*(a))
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; --i)
#define FILL(a, b) memset(a, b, sizeof(a))
#define FHAS(a, b) (find((a).begin(), (a).end(), (b))!=(a).end())
#define HAS(a, b) ((a).find(b) != (a).end())
#define HASB(a, b) ((a & (1 << b))>0)

template<class A, class B> A convert(B x) {stringstream s; s << x; A r; s >> r; return r;}

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long LL;

int n, k;
char line[128];
string a[64];
string b[64];

int Vert(int ii, int jj)
{
	if (ii+k>n) return 0;
	FOR(i, ii+1, ii+k)
		if (b[ii][jj] != b[i][jj]) return 0;
	return 1;
}

int Hor(int ii, int jj)
{
	if (jj+k>n) return 0;
	FOR(j, jj+1, jj+k)
		if (b[ii][jj] != b[ii][j]) return 0;
	return 1;
}

int Diag1(int ii, int jj)
{
	if (ii+k>n || jj+k>n) return 0;
	FOR(p, 1, k)
		if (b[ii][jj] != b[ii+p][jj+p]) return 0;
	return 1;
}

int Diag2(int ii, int jj)
{
	if (ii+k>n || jj-k+1<0) return 0;
	FOR(p, 1, k)
		if (b[ii][jj] != b[ii+p][jj-p]) return 0;
	return 1;
}

int Check(char ch)
{
	FOR(i, 0, n)
		FOR(j, 0, n)
			if (b[i][j] == ch)
			{
				if (Vert(i, j)) return 1;
				if (Hor(i, j)) return 1;
				if (Diag1(i, j)) return 1;
				if (Diag2(i, j)) return 1;
			}
	return 0;
}

int main() {

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int tc, gl=0; scanf("%d", &tc);
	while (tc --> 0) {
		gl++;
		scanf("%d %d", &n, &k);
		FOR(i, 0, n) {
			scanf("%s", line);
			a[i] = string(line);
		}
		FOR(i, 0, n+1)
			b[i] = string(n, '.');
		FOR(i, 0, n)
			FOR(j, 0, n)
				b[i][j] = a[n-j-1][i];
		FORD(i, n-1, 0)
			FOR(j, 0, n)
				if (b[i][j] != '.')
				{
					int ii = i;
					while (ii<n-1 && b[ii+1][j] == '.') {
						swap(b[ii][j], b[ii+1][j]);
						++ii;
					}
				}

		int f1 = Check('R');
		int f2 = Check('B');

		printf("Case #%d: ", gl);

		if (f1 && f2)
			printf("Both\n");
		else
			if (f1 && !f2)
				printf("Red\n");
			else
				if (!f1 && f2)
					printf("Blue\n");
				else
					printf("Neither\n");
	}

	return 0;
}