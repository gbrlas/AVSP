// GCJ Round 2 2010 -- Sat Jun 5 2010
// Problem A
//
// pre-written code follows
// #includes {{{
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// }}}
// constants, typedefs, macros {{{
typedef long long LL;
typedef unsigned long long ULL;
const int oo = 1000000000;
const LL OO = 1000000000000000000LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef queue<int> QI;
typedef queue<PII> QPII;
typedef complex<double> tComp;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
#define FORIT(i,c) for (typeof((c).end()) i=(c).begin(); i!=(c).end(); ++i)
#define CERR(x) cerr << (#x) << " = " << (x) << endl
#define COUT(x) cout << (#x) << " = " << (x) << endl
// }}}

// code written during the competition follows
VS enhance(const VS &diamond)
{
	int n = diamond.size();
	VS new_diamond(n + 2);
	for (int i=0; i<n; i++)
		new_diamond[i + 1] = diamond[i];
	new_diamond[0] = string(diamond[0].size(), ' ');
	new_diamond[n+1] = string(diamond[0].size(), ' ');
	for (int i=0; i<n+2; i++)
		new_diamond[i] += string(2, ' ');
    new_diamond[0][(n+1)/2] = '?';
    new_diamond[n+1][(n+1)/2] = '?';
	for (int i=1; i<=n; i++)
	{
		for (int j=n-1; j>=0; j--)
			if (new_diamond[i][j] != ' ')
			{
				new_diamond[i][j+2] = '?';
				break;
			}
	}
	return new_diamond;
}
bool diff(char a, char b)
{
	return a != b && a != '?' && b != '?';
}
bool is_diamond(const VS &diamond)
{
	int n = diamond.size();
	for (int i=0; i<n/2; i++)
		for (int j=0; j<n; j++)
		{
			if (diff(diamond[i][j], diamond[n-1-i][j]))
				return false;
			if (diff(diamond[j][i], diamond[j][n-1-i]))
				return false;
		}
	return true;
}
void print(VS &out)
{
	FORIT(it, out)
		cout << *it << endl;
}
VS rotate(const VS &diamond)
{
	int n = diamond.size();
	VS new_diamond(n, string(n, ' '));
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			new_diamond[j][n-1-i] = diamond[i][j];
	return new_diamond;
}
int non_space(VS d)
{
	int ret = 0;
	FORIT(it, d)
		FORIT(it2, *it)
			if (*it2 != ' ')
				ret++;
	return ret;
}
int solve(const VS &diamond)
{
	set<VS> st;
	queue<VS> q;
	st.insert(diamond);
	q.push(diamond);
	while (!q.empty())
	{
		VS act = q.front();
//		print(act);
		q.pop();
		if (is_diamond(act))
			return non_space(act) - non_space(diamond);
		for (int i=0; i<4; i++)
		{
			VS next = enhance(act);
			VS mini = next;
			for (int j=0; j<4; j++)
			{
				next = rotate(next);
				mini = min(next, mini);
			}
			if (!st.count(mini))
			{
				st.insert(mini);
				q.push(mini);
			}
			act = rotate(act);
		}
	}
	return -1;
}
int main()
{
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		int k;
		cin >> k;
		string line;
		getline(cin, line);
		VS input;
		int n = 2 * k - 1;
		for (int i=0; i<n; i++)
		{
			getline(cin, line);
			while ((int)line.size() < n)
			{
				line.push_back(' ');
			}
			input.push_back(line);
		}
		printf("Case #%d: ", tkase+1);
		cout << solve(input) << endl;
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
