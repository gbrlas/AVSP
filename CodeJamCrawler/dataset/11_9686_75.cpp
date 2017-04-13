#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <numeric>
#include <cstdio>
#include <memory.h>

using namespace std;   

#define SZ(a) ((int)(a).size())
#define SQR(a) ((a)*(a))
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; --i)
#define FILL(a, b) memset(a, b, sizeof(a))
#define FHAS(a, b) (find((a).begin(), (a).end(), (b))!=(a).end())
#define HAS(a, b) ((a).find(b) != (a).end())
#define HASB(a, b) (((a) & (1 << (b)))>0)

template<class A, class B> A convert(B x) {stringstream s; s << x; A r; s >> r; return r;}

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long LL;

const string prob = "C";

int n, m, maxc, optc;
int U[2001];
int V[2001];
int col[2001], opt[2001];
vector<VI> gr;
VI curr;
int state[2001];
bool bad;

vector<VI> need;

void Cycle(int v)
{
	if (bad) return;

	if (state[v] == 1)
	{
		int u = SZ(curr)-1;
		VI nn;
		nn.push_back(v);
		do
		{
			nn.push_back(curr[u]);
			u--;
		} while (curr[u] != v);
		
		nn.push_back(v);
		reverse(nn.begin(), nn.end());

		if (SZ(nn) <= 3) return;

		int f1 = 0;
		FOR(i, 0, SZ(nn)-1) {
			int ot = nn[i];
			int ku = nn[i+1];
			if (ku>ot) continue;
			if (f1) { f1=-1; break; }
			f1 = 1;
		}

		int f2 = 0;
		FOR(i, 0, SZ(nn)-1) {
			int ot = nn[i];
			int ku = nn[i+1];
			if (ku<ot) continue;
			if (f2) { f2=-1; break; }
			f2 = 1;
		}

		if (f1==-1 && f2==-1) return;

		need.push_back(nn);

		return;
	}

	if (state[v] == 2) return;

	state[v] = 1;
	curr.push_back(v);
	FOR(i, 0, SZ(gr[v]))
		Cycle(gr[v][i]);
	curr.pop_back();

	state[v] = 0;
}

void Try()
{
	/*
	if (col[0] == 1 && col[1] == 1 && col[2] == 2 && col[3] == 3 && col[4] == 1 && col[5] == 1 && col[6] == 4 && col[7] == 5)
	{
		maxc = maxc;
	}
	*/
	/*
	if (col[0] == 1 && col[1] == 2 && col[2] == 3 && col[3] == 1 && col[4] == 1 && col[5] == 3 && col[6] == 2 && col[7] == 3)
	{
		maxc = maxc;
	}
	*/
	maxc = *max_element(col, col+n);
	if (maxc <= optc) return;

	FOR(i, 0, SZ(need))
	{
		set<int> ss;
		FOR(j, 0, SZ(need[i]))
			ss.insert(col[need[i][j]]);
		if (SZ(ss) != maxc) return;
	}

	optc = maxc; FOR(i, 0, n) opt[i] = col[i];
}

void Rec(int v, int c)
{
	if (v == n) { Try(); return; }

	FOR(i, 1, c+1)
	{
		col[v] = i;
		Rec(v+1, max(c, i+1));
	}
}

int main() {

	freopen((prob+".in").c_str(), "r", stdin);
	freopen((prob+".out").c_str(), "w", stdout);

	int tc, gl=1; scanf("%d", &tc);

	while (tc --> 0)
	{
		scanf("%d %d", &n, &m);
		gr.resize(0); gr.resize(n);
		FOR(i, 0, m) {
			scanf("%d", U+i); U[i]--;
		}
		FOR(i, 0, m) {
			scanf("%d", V+i); V[i]--;
		}
		FOR(i, 0, m) {
			gr[U[i]].push_back(V[i]);
			gr[V[i]].push_back(U[i]);
		}
		FOR(i, 0, n) {
			int ot = i;
			int ku = i+1; if (ku == n) ku = 0;
			gr[ot].push_back(ku);
			gr[ku].push_back(ot);
		}

		need.clear();
		FILL(state, 0);
		Cycle(0);

		optc = 0;
		Rec(0, 1);

		printf("Case #%d: %d\n", gl++, optc);
		FOR(i, 0, n) printf("%d%c", opt[i], (i<n-1)?' ':'\n');
	}

	return 0;
}