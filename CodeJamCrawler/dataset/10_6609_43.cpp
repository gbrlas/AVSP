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

int a[151][151], b[151][151];
int len[151], add[151], lenb[151];
int n;

bool Valid(int r1, int r2)
{
	FOR(i, 0, min(lenb[r1], lenb[r2]))
		if (b[r1][i] != b[r2][i] && b[r1][i]!=-1 && b[r2][i]!=-1) return false;
	return true;
}

bool canMakeSymmetric(int rr, int L, int R)
{
	if (L<0 || R<0) return false;
	lenb[rr] = L+len[rr]+R;
	FOR(i, 0, lenb[rr]) b[rr][i] = -1;
	FOR(i, L, L+len[rr])
	{
		if (i-L >= len[rr]) return false;
		b[rr][i] = a[rr][i-L];
	}
	int res = 0;
	FOR(i, 0, lenb[rr]/2)
	{
		if (b[rr][i] == -1 && b[rr][lenb[rr]-i-1] == -1)
		{
			//b[rr][i] = b[rr][lenb[rr]-i-1] = 0;
			continue;
		}
		if (b[rr][i]==-1)
		{
			b[rr][i] = b[rr][lenb[rr]-i-1];
			continue;
		}
		if (b[rr][lenb[rr]-i-1]==-1)
		{
			b[rr][lenb[rr]-i-1] = b[rr][i];
			continue;
		}
		if (b[rr][i] != b[rr][lenb[rr]-i-1]) return false;
	}
	return true;
}

int Can(int mm, int k)
{
	if (max(mm+1, 2*n-1-mm) > k) return false;
	FILL(add, 0);
	int curr = k;
	/*
	FOR(i, 1, 2*n-1)
	{
		int r1 = mm-i;
		int r2 = mm+i;
		if (r1<0 || r2>=2*n-1) break;
		if (!Valid(r1, r2)) return false;
	}
	*/
	FORD(i, mm+1, 0)
	{
		if (len[i]>curr) return false;
		add[i] = curr-len[i];
		curr--;
	}
	curr = k;
	FOR(i, mm, 2*n-1)
	{
		if (len[i]>curr) return false;
		add[i] = curr-len[i];
		curr--;
	}
	FOR(i, 0, k-len[mm]+1)
	{
		bool fl = true;
		int L = i, R = add[mm] - i;
		FORD(j, mm+1, 0)
		{
			if (L+R != add[j] || !canMakeSymmetric(j, L, R))
			{
				fl = false; break;
			}
			if (j && len[j-1]>len[j]) 
			{
				L--,--R;
			}
		}
		L = i, R = add[mm] - i;
		FOR(j, mm, 2*n-1)
		{
			if (L+R != add[j] || !canMakeSymmetric(j, L, R))
			{
				fl = false; break;
			}
			if (j<2*n-1 && len[j+1]>len[j]) 
			{
				L--,--R;
			}
		}
		if (!fl) continue;
		FOR(i, 1, 2*n-1)
		{
			int r1 = mm-i;
			int r2 = mm+i;
			if (r1<0 || r2>=2*n-1) break;
			if (!Valid(r1, r2)) fl = false;
		}
		if (fl) return true;
	}
	return false;
}

int main() {

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int tc, gl;
	for(scanf("%d", &tc), gl=1; tc-->0; gl++)
	{
		scanf("%d", &n); FILL(len, 0);
		FOR(i, 0, n) {
			len[i] = i+1;
			FOR(j, 0, i+1)
				scanf("%d", &a[i][j]);
		}
		FOR(i, n, 2*n-1) {
			len[i] = 2*n-i-1;
			FOR(j, 0, 2*n-i-1)
				scanf("%d", &a[i][j]);
		}
		int res = -1;
		FOR(k, n, 1000) {
			if (res != -1) break;
			FOR(midd, 0, 2*n-1)
				if (Can(midd, k))
				{
					res = k*k-n*n; break;
				}
		}
		printf("Case #%d: %d\n", gl, res);
	}

	return 0;
}